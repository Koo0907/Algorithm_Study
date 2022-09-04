#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int cnt = 0;

// 방문 체크 배열
bool visited[MAX];

// 그래프의 연결 리스트 벡터
vector<int> vec[MAX];

// DFS 수행 함수
void dfs(int x)
{
	// x 정점 방문처리
	visited[x] = true;

	// x 정점에 연결되어 있는 정점 수 만큼 순회
	for(int i = 0; i < vec[x].size(); i++)
	{
		// 다음 정점 탐색
		int next_x = vec[x][i];

		// 다음 정점을 아직 방문하지 않았다면 DFS 수행
		if(visited[next_x] == false)
		{
			dfs(next_x);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);

		// 무방향 그래프이므로 양 쪽에 모두 간선 추가
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	// 방문 배열 초기화
	memset(visited, false, MAX);

	for(int i = 1; i <= N; i++)
	{
		// 정점을 아직 방문하지 않았다면 아래 로직 수행
		if(visited[i] == false)
		{
			// DFS 수행
			dfs(i);

			// 연결 요소 수 증가
			cnt++;
		}
	}

	cout << cnt << endl;
}