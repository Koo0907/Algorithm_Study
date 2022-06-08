#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int X = 0;
int u = 0;
int v = 0;
int w = 0;
int max_time = 0;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[1001];

// ����ϴ� �������� ��Ƽ�� ������ X ���������� �ִܰŸ� ���̺�
int go_dis[1001];

// X �������� ����ߴ� ������ �ٽ� ���ư��� �ִܰŸ� ���̺�
int back_dis[1001];

void dijkstra(int start, bool flag)
{
    // {����ġ, �������} pair�� ��ҷ� ������ ����ġ�� �������� ��������(�ּ� ��, Min Heap)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // int �����ͷ� ����ؼ� flag �Ķ������ ���� ���� go_dis ���̺� ������� back_dis ���̺� ������� �Ǵ�
    int *dis;
    if(flag)
    {
        dis = go_dis;   
    }
    else
    {
        dis = back_dis;
    }

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
    // ������ ����, ��Ƽ�� ������ ���� �Է�
    cin >> N >> M >> X;

    // ���� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        graph[u].push_back({v, w});
    }

    // ��Ƽ�� ������ ����(X)�������� �� ������ ���� �ִ� ��� ����
    fill(back_dis, back_dis + 1001, INF);
    dijkstra(X, false);

    for(int i = 1; i <= N; i++)
    {
        // �� ������������ ��Ƽ�� ������ ����(X)�� ���� �ִ� ��θ� ��ȸ�ϸ鼭 ����
        fill(go_dis, go_dis + 1001, INF);
        dijkstra(i, true);

        // ���� ��ȸ���� �������� X ���������� �Ÿ��� X �������� �ٽ� ���ƿ��� �Ÿ��� ���Ͽ� �ִ밪�� ����
        if(go_dis[X] + back_dis[i] > max_time)
        {
            max_time = go_dis[X] + back_dis[i];
        }
    }

    // �պ� �ִ� ��� �ִ밪 ���
    cout << max_time << endl;
}