#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int C = 0;
int X = 0;
int Y = 0;
int Z = 0;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[30001];

// �ִܰŸ� ���̺�
int dis[30001];

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
    // ���� �� N, ��� �� M, �޽����� �������� �ϴ� ���� C �Է�
    cin >> N >> M >> C;

    // ��� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &X, &Y, &Z);
        graph[X].push_back({Y, Z});
    }

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    fill(dis, dis + 30001, INF);

    // ���ͽ�Ʈ�� �˰��� ����
    dijkstra(C);

    int cnt = 0;
    int max_dis = 0;

    for(int i = 1; i <= N; i++)
    {
        // �ִܰŸ� ���̺��� INF�� �ƴϸ� C ���ÿ� ����Ǿ� �ִٴ� �ǹ�
        if(dis[i] != INF)
        {
            cnt++;
        }

        // �ִܰŸ� ���̺��� ���� �� �Ÿ� Ž��
        max_dis = max(max_dis, dis[i]);
    }

    cout << cnt - 1 << " " << max_dis << endl;
}