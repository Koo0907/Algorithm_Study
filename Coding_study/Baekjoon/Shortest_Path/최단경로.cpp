#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int V = 0;
int E = 0;
int K = 0;
int u = 0;
int v = 0;
int w = 0;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[20001];

// �ִܰŸ� ���̺�
int dis[20001];

void dijkstra(int start)
{
    // {����ġ, �������} pair�� ��ҷ� ������ ����ġ�� �������� ��������(�ּ� ��, Min Heap)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ���� ���� ��� start�� �ִ� ����� 0�� �켱���� ť�� push
    pq.push({0, start});

    // �ִܰŸ� ���̺� ����
    dis[start] = 0;

    while(!pq.empty())
    {
        // path�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ����ġ
        // node�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ���
        int path = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // path�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ���� �湮�� �Ͱ� ����
        if(dis[node] < path)
        {
            continue;
        }

        // �ش� ��带 �湮���� �ʾҴٸ� ����� ������ ��ȸ
        for(int i = 0; i < graph[node].size(); i++)
        {
            // next_node�� ���� ��忡�� ����� ���
            // next_path�� ���� ������ ���� �Ÿ�(path)�� ���� ��忡������ ����� �������� �Ÿ�(graph[node][i].second)�� ���� ���� ��
            int next_node = graph[node][i].first;
            int next_path = path + graph[node][i].second;

            // next_path ���� �ִܰŸ� ���̺� �ִ� next_node ������ �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(next_path < dis[next_node])
            {
                // �ִܰŸ� ���̺� �� ����
                dis[next_node] = next_path;

                // �켱���� ť�� ����ġ�� ��� ������ �߰�
                pq.push({next_path, next_node});
            }
        }
    }
}

int main()
{
    // ��� �� V, ���� �� E �Է�
    cin >> V >> E;
    // ���۳�� K �Է�
    cin >> K;

    // ���� �� ��ŭ ��� ��� u, ���� ��� v, ����ġ w �Է�
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        graph[u].push_back({v, w});
    }

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    fill(dis, dis + 20001, INF);

    // ���ͽ�Ʈ�� �˰��� ����
    dijkstra(K);

    // �ִܰŸ� ���
    for(int i = 1; i <= V; i++)
    {
        // ���ͽ�Ʈ�� �˰����� �����ص� �ִ� �Ÿ� ���� INF��� ��ΰ� �������� ����
        if(dis[i] == INF)
        {
            printf("INF\n");
        }
        else
        {
            printf("%d\n",dis[i]);
        }
    }
}