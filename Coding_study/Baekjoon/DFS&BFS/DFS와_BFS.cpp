#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int V = 0;

bool visited[1001];
vector<int> vec[1001];
queue<int> que;

void dfs(int x)
{
    // �Լ� ȣ��Ǹ� �湮 ó��
    visited[x] = true;

    cout << x << " ";

    // ���� ��忡 ����Ǿ� �ִ� ���� ��ȸ�ϸ鼭 DFS �Լ� ȣ�� �õ�
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
    // �Լ� ȣ��Ǹ� �湮 ó��
    visited[x] = true;

    // �ʱⰪ queue�� push
    que.push(x);

    // queue �� ������ ��ȸ
    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
        cout << cur << " ";
        // ���� ��忡 ����Ǿ� �ִ� ���� ��ȸ�ϸ鼭 BFS �Լ� ȣ�� �õ�
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

    // BFS Ž���� ��쿡�� �ڽ� ��� �߿��� ���� �� ���� ��尡 ���� Ž���� �� �ֵ��� ��������
    for(int i = 0; i <= N; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }

    dfs(V);
    cout << endl;

    // visited �迭 clear
    memset(visited, false, sizeof(visited));

    bfs(V);
}