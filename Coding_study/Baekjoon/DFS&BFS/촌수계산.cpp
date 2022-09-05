#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 101

using namespace std;

// 사용할 변수 초기화
int n = 0;
int a = 0;
int b = 0;
int m = 0;
int x = 0;
int y = 0;
int ans = -1;

// 촌수을 나타내는 연결 리스트 벡터
vector<int> v[MAX];

// 방문 처리를 위한 배열
bool visited[MAX];

// DFS 수행 함수
void dfs(int depth, int p, int c)
{
	// p 사람 방문 처리
	visited[p] = true;

	// p와 c가 같다면(촌수를 계산할 수 있다면) 아래 로직 수행
	if(p == c)
	{
		// 현재의 촌수로 ans 갱신
		ans = depth;
	}

	// p 사람의 관계 순회
	for(int i = 0; i < v[p].size(); i++)
	{
		// 다음 사람을 아직 방문하지 않았다면 아래 로직 수행
		if(visited[v[p][i]] == false)
		{
			// 촌수를 1 증가시키고 DFS 함수 호출
			dfs((depth + 1), v[p][i], c);
		}
	}
}

int main()
{
	// 사람의 수 입력
	scanf("%d", &n);

	// 촌수를 계산하려는 두 사람 입력
	scanf("%d %d", &a, &b);

	// 촌수 데이터 수 입력
	scanf("%d", &m);

	// 촌수 데이터 입력
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);

		v[x].push_back(y);
		v[y].push_back(x);
	}

	// DFS 함수 호출
	dfs(0, a, b);

	// ans 출력
	printf("%d\n", ans);

}