#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 100001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int a = 0;
int b = 0;

// 연결 리스트를 위한 벡터
vector<int> vec[MAX];

// 방문 처리를 위한 배열
bool visited[MAX];

// 부모 노드 배열
int parent[MAX];

// DFS 수행 함수
void dfs(int x)
{
	// 파라미터 x 값 방문 처리
	visited[x] = true;

	// x에 연결되어 있는 노드들 순회
	for(int i = 0; i < vec[x].size(); i++)
	{
		// 다음 노드 탐색
		int next_x = vec[x][i];

		// 다음 노드를 아직 방문하지 않았다면 아래 로직 수행
		if(visited[next_x] == false)
		{
			// DFS 함수 호출
			dfs(next_x);

			// 부모 노드 갱신
			parent[next_x] = x;
		}
	}
}

int main()
{
	scanf("%d",&N);

	for(int i = 0; i < (N - 1); i++)
	{
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	// 루트 노드인 1부터 DFS 함수 호출
	dfs(1);

	// 부모 노드 출력
	for(int i = 2; i <= N; i++)
	{
		printf("%d\n",parent[i]);
	}
}