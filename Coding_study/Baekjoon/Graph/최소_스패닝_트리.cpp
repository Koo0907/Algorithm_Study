#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 10001

using namespace std;

// 사용할 변수 초기화
int V = 0;
int E = 0;
int A = 0;
int B = 0;
int C = 0;
int ans = 0;

// 부모 테이블
int parent[MAX];

// 경로 데이터 벡터
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
	scanf("%d %d",&V, &E);

	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d",&A, &B, &C);
		v.push_back({C, {A, B}});
	}

	// 부모 테이블을 자신으로 초기화
	for(int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}

	// 비용 오름차순 정렬
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		// cost는 두 노드를 잇는 비용
		// a와 b는 두 노드
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// 순회하는 두 노드의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{
			// 두 노드 union 연산
			union_parent(a, b);

			// 비용 갱신
			ans += cost;
		}
	}

	cout << ans << endl;
}