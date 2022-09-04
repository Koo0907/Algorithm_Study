#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int A = 0;
int B = 0;
int C = 0;
int cnt = 0;
int max_val = 0;
int min_val = 0;

// 부모 테이블
int parent[MAX];

// 학교 건물 데이터 벡터
vector<pair<int, pair<int, int>>> v;

// find 연산
int find_parent(int a)
{
	// a의 부모가 a라면 루트노드라는 의미
	if(a == parent[a])
	{
		return a;
	}
	// a의 부모가 a가 아니라면 부모 테이블 갱신 및 재귀호출
	else
	{
		return parent[a] = find_parent(parent[a]);
	}
}

// union 연산
void union_parent(int a, int b)
{
	// a,b의 부모 찾기
	a = find_parent(a);
	b = find_parent(b);

	// 더 작은 값이 부모가 되도록 설정
	if(a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

// 내림차순 정렬을 위한 cmp 함수
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first > b.first;
}

// MST 구하기 위한 크루스칼 알고리즘 수행 함수
int kruskal(void)
{
	for(int i = 0; i < v.size(); i++)
	{
		// tired는 0(오르막), 1(내리막)인지 확인
		// a, b는 두 건물
		int tired = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// 순회하는 두 건물의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{
			// 두 건물 union 연산
			union_parent(a, b);

			// 두 건물을 잇는 경로가 0(오르막)이면 cnt 증가
			if(tired == 0)
			{
				cnt++;
			}
		}
	}

	// 피로도 반환
	return (cnt * cnt);
}
int main()
{
	scanf("%d %d",&N, &M);

	for(int i = 0; i < M + 1; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		v.push_back({C, {A, B}});
	}

	// 부모 테이블 초기화
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	// 경로 오름차순 정렬
	sort(v.begin(), v.end());

	// 오름차순으로 정렬했으므로 피로도가 가장 높은 코스
	max_val = kruskal();

	// cnt 초기화
	cnt = 0;

	// 부모 테이블 초기화
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	// 경로 내림차순 정렬
	sort(v.begin(), v.end(), cmp);
	
	// 내림차순으로 정렬했으므로 피로도가 가장 낮은 코스
	min_val = kruskal();

	// 두 코스의 차이 출력
	cout << max_val - min_val << endl;
}