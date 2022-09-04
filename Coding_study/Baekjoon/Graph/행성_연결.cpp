#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
long long ans = 0;	// 비용의 합이 int형의 범위를 넘을 수 있으므로 long long 타입 선언

// 행성간의 플로우 관리 비용 배열
int map[MAX][MAX];

// 부모 테이블
int parent[MAX];

// 행성 간 경로 데이터 벡터
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

int main()
{
	scanf("%d",&N);

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			
			// j가 i보다 큰 경우에만 유효한 필요 경로 데이터이므로 벡터에 추가
			if(j > i)
			{
				v.push_back({map[i][j], {i, j}});
			}
		}
	}

	// 부모 테이블 초기화
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 경로 오름차순 정렬
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		// cost는 행성 간의 플로우 관리 비용
		// a,b는 두 행성
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// 순회하는 두 행성의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{
			// 두 행성 union 연산
			union_parent(a, b);

			// 비용 갱신
			ans += cost;
		}
	}
		cout << ans << endl;
}