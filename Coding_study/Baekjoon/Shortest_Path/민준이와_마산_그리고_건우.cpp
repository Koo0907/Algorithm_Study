#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 5001

using namespace std;

// ����� ���� �ʱ�ȭ
int V = 0;
int E = 0;
int P = 0;
int a = 0;
int b = 0;
int c = 0;

// ������ �������� �׷��� �����͸� ��� ����
vector<pair<int, int>> vec[MAX];

// �ִܰŸ� ���̺�
int dis[MAX];

void dijkstra(int x)
{
    // �ִܰŸ� ���̺� �ʱ�ȭ
    fill(dis, dis + MAX, INF);

    // �������� �Ÿ��� �������� �Ͽ� ��������(�ּ� ��)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // �ִܰŸ� ���̺� ����
    dis[x] = 0;

    // �켱���� ť�� ������ �߰�
    pq.push({0, x});

    while(!pq.empty())
    {
        // cost�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ����ġ
        // node�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ���
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // cost�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ���� �湮�� �Ͱ� ����
        if(dis[node] < cost)
        {
            continue;
        }

        // �ش� ��带 �湮���� �ʾҴٸ� ����� ������ ��ȸ
        for(int i = 0; i < vec[node].size(); i++)
        {
            // next_node�� ��ȸ���� ���� ����� ���� ���
            // next_cost�� ��ȸ���� ���� ����� ���� �������� �Ÿ�
            int next_node = vec[node][i].first;
            int next_cost = cost + vec[node][i].second;

            // next_cost ���� �ִܰŸ� ���̺� �ִ� next_node ������ �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(dis[next_node] > next_cost)
            {
                // �ִܰŸ� ���̺� ����
                dis[next_node] = next_cost;

                // �켱���� ť�� ������ �߰�
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main()
{
    // V, E, P ������ �Է�
    scanf("%d %d %d", &V, &E, &P);

    // ���� ����ŭ ��� ������ �Է�
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        // ��������� ����
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    // path1�� �������� �ٷ� ���� ���
    // path2�� �߰��� �ǿ츦 ���ϰ� �������� ���� ���
    int path1 = 0;
    int path2 = 0;

    // 1�� ��忡�� ����ϵ��� ���ͽ�Ʈ�� �˰��� ����
    dijkstra(1);

    // �� ��ε� ����
    path1 = dis[V];
    path2 = dis[P];

    // �ǿ찡 �ִ� P�� ��忡�� ����ϵ��� ���ͽ�Ʈ�� �˰��� ����
    dijkstra(P);

    // �ǿ츦 ���ϴ� ��� ����
    path2 += dis[V];

    // �ǿ츦 ���ϴ� ��ΰ� �������� �ٷ� ���� ��κ��� �۰ų� ���ٸ� �Ʒ� ���� ����
    if(path2 <= path1)
    {
        printf("SAVE HIM\n");
    }
    // �ǿ츦 ���ϴ� ��ΰ� �������� �ٷ� ���� ��κ��� ũ�ٸ� �Ʒ� ���� ����
    else
    {
        printf("GOOD BYE\n");
    }
}
