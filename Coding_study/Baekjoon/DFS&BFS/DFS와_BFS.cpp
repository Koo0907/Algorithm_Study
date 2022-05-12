#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int V = 0;

bool visited[1001];
vector<int> vec[1001];
queue<int> que;

void dfs(int x)
{
    // 함수 호출되면 방문 처리
    visited[x] = true;

    cout << x << " ";

    // 현재 노드에 연결되어 있는 노드들 순회하면서 DFS 함수 호출 시도
    for(int i = 0; i < vec[x].size(); i++)
    {
        int next_x = vec[x][i];
        if(visited[next_x] == false)
        {
            dfs(next_x);
        }
    }
}
void bfs(int x)
{
    // 함수 호출되면 방문 처리
    visited[x] = true;

    // 초기값 queue에 push
    que.push(x);

    // queue 빌 때까지 순회
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        // 현재 노드에 연결되어 있는 노드들 순회하면서 BFS 함수 호출 시도
        for(int i = 0; i < vec[cur].size(); i++)
        {
            int next_x = vec[cur][i];
            if(visited[next_x] == false)
            {
                visited[next_x] = true;
                que.push(next_x);
            }
        }
    }
}
int main() {

    cin >> N >> M >> V;

    for(int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;

        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    // BFS 탐색의 경우에는 자식 노드 중에서 값이 더 작은 노드가 먼저 탐색될 수 있도록 정렬해줌
    for(int i = 0; i <= N; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(V);
    cout << endl;

    // visited 배열 clear
    memset(visited, false, sizeof(visited));

    bfs(V);
}