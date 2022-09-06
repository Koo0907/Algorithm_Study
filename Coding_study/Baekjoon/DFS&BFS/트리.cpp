#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 50

using namespace std;

// 사용할 변수 초기화
int N = 0;
int root = 0;
int exclude_node = 0;
int cnt = 0;

// 노드 연결 리스트 벡터
vector<int> v[MAX];

// 방문 처리 배열
bool visited[MAX];

// DFS 수행 함수
void dfs(int node)
{
	// 순회하는 노드가 지울 노드라면 바로 return
	if(node == exclude_node)
	{
		return;
	}

	// 현재 노드 방문 처리
	visited[node] = true;

	// 현재 노드에 연결되어 있는 자식 노드가 없는지 확인
	if(v[node].size() == 0)
	{
		// 자식 노드가 없다면 리프 노드이므로 cnt 증가
		cnt++;
	}

	// 현재 노드에 연결되어 있는 자식 노드가 1개인지 확인
	if(v[node].size() == 1)
	{
		// 1개 있는 자식 노드가 지울 노드라면 현재 노드는 결국 리프 노드가 되므로 cnt 증가
		if(v[node][0] == exclude_node)
		{
			cnt++;
		}
	}

	// 자식 노드 순회
	for(int i = 0; i < v[node].size(); i++)
	{
		int next_node = v[node][i];

		// 자식 노드를 아직 방문하지 않았다면 DFS 함수 호출
		if(visited[next_node] == false)
		{
			dfs(next_node);
		}
	}
}

int main()
{
	scanf("%d",&N);

	for(int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);

		// -1이 입력되는 번호의 노드가 루트노트
		if(num == -1)
		{
			root = i;
		}
		else
		{
			// 부모-자식 관계이므로 단방향 벡터
			v[num].push_back(i);
		}
	}

	// 지울 노드 입력
	scanf("%d", &exclude_node);

	// 루트노드에서부터 DFS 함수 호출
	dfs(root);

	cout << cnt << endl;
}