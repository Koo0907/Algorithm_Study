#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int w = 0;
int start_city = 0;
int end_city = 0;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[1001];

// �ִܰŸ� ���̺�
int dis[1001];

void dijkstra(int start)
{
    // {����ġ, �������} pair�� ��ҷ� ������ ����ġ�� �������� ��������(�ּ� ��, Min Heap)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ���� ��� ���ÿ� �ִ� ��� 0�� �켱���� ť�� ����
    pq.push({0, start});

    // �ִܰ�� ���̺� ����
    dis[start] = 0;

    while(!pq.empty())
    {
        // cost�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ����ġ
        // city�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ���
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();

        // path�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ���� �湮�� �Ͱ� ����
        if(dis[city] < cost)
        {
            continue;
        }

        // �ش� ��带 �湮���� �ʾҴٸ� ����� ������ ��ȸ
        for(int i = 0; i < graph[city].size(); i++)
        {
            // next_city�� ���� ��忡�� ����� ���
            // next_cost�� ���� ������ ���� �Ÿ�(cost)�� ���� ��忡������ ����� �������� �Ÿ�(graph[city][i].second)�� ���� ���� ��
            int next_city = graph[city][i].first;
            int next_cost = cost + graph[city][i].second;

            // next_cost ���� �ִܰŸ� ���̺� �ִ� next_city ������ �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(next_cost < dis[next_city])
            {
                // �ִܰŸ� ���̺� �� ����
                dis[next_city] = next_cost;

                // �켱���� ť�� ����ġ�� ��� ������ �߰�
                pq.push({next_cost, next_city});
            }
        }
    }
}

int main()
{
    // ������ ���� ������ ���� �Է�
    cin >> N >> M;

    // ���� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        graph[u].push_back({v, w});
    }

    // ��� ���ÿ� ���� ���� �Է�
    cin >> start_city >> end_city;

    // �ִܰ�� ���̺� INF�� �ʱ�ȭ
    fill(dis, dis + 1001, INF);

    // ���ͽ�Ʈ�� �˰��� ����
    dijkstra(start_city);

    // ��� ���ÿ������� ���� ���ñ����� �ִ� ��� ���
    cout << dis[end_city] << endl;
}