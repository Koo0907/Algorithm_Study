#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int K = 0;
int u = 0;
int v = 0;
int w = 0;
int ans = 0;

// 부모 테이블
int parent[MAX];

// 발전기 도시 배열
int generation[MAX];

// 경로 데이터 벡터
vector<pair<int, pair<int, int>>> vec;

// 모든 도시의 부모노드가 발전기 도시들의 부모노드인지 확인
bool check_generation(void)
{
	for(int i = 1; i <= N; i++)
	{
		if(parent[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}

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
	scanf("%d %d %d", &N, &M, &K);

	// 부모 테이블 초기화
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 발전기 도시 입력
	for(int i = 0; i < K; i++)
	{
		scanf("%d",&generation[i]);

		// 발전기 도시들은 미리 최상위 우선순위인 0으로 부모노드를 설정해서 union 연산함
		parent[generation[i]] = 0;
	}

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		vec.push_back({w, {u, v}});
	}

	// 경로 오름차순 배열
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++)
	{
		// cost는 두 도시의 경로 길이
		// a,b는 두 도시
		int cost = vec[i].first;
		int a = vec[i].second.first;
		int b = vec[i].second.second;

		// 순회하는 두 도시의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{
			// 두 도시 union 연산
			union_parent(a, b);
			
			// 경로 갱신
			ans += cost;
		}

		// 순회가 끝날때마다 모든 도시의 부모노드가 발전기 도시의 부모노드와 같은지 확인
		if(check_generation())
		{
			break;
		}
	}

	cout << ans << endl;
}