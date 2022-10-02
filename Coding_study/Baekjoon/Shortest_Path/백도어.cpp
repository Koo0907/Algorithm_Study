#include<iostream>
#include<vector>
#include<queue>

// ������ ���� int�� ������ �Ѿ�� ������ INF ���� ũ�� ����
#define INF 1e12
#define MAX 100000

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
char S = 0;
int a = 0;
int b = 0;
int t = 0;

// �� �ؼ������� ����� �þ߿� �ִ����� ���� �����͸� ���� �迭
char visible[MAX];

// �� �ؼ����� �ð��� �Է¹��� ����
vector<pair<int, int>> vec[MAX];

// �ִܰŸ� ���̺�
long long dis[MAX];

void dijkstra(int x)
{
    // �ؼ������� �ð��� �������� ��������(�ּ� ��)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    // ���� �ؼ����� ���� �ִܰŸ� ���̺� ����
    dis[x] = 0;

    // ť�� ������ �߰�
    pq.push({0, x});

    // ť�� �� ������ �ݺ�
    while(!pq.empty())
    {
        // cost�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ����ġ
        // node�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� ���
        long long cost = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        // �ִܰŸ� ���̺��� ���� �̹� �ش� �ؼ��������� �Ÿ����� �۰ų�, ����� �þ߿� �ִ� �ؽ������ continue
        if((dis[node] < cost) || (visible[node] == 1))
        {
            continue;
        }

        // ���� ��ȸ���� �ؼ����� ����Ǿ� �ִ� �ؼ����� ��ȸ
        for(int i = 0; i < vec[node].size(); i++)
        {
            // next_node�� ���� �ؼ���
            // next_cost�� ���� �ؼ��������� �ð�
            long long next_node = vec[node][i].first;
            long long next_cost = cost + vec[node][i].second;

            // next_cost ���� �ִܰŸ� ���̺� �ִ� next_node ������ �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(dis[next_node] > next_cost)
            {
                // �ִܰŸ� ���̺� ����
                dis[next_node] = next_cost;

                // ť�� ������ �߰�
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main()
{
    // N�� M �Է�
    scanf("%d %d", &N, &M);

    // �� �ؼ����� ����� �þ߿� �ִ����� ���� ������ �Է�
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &S);
        visible[i] = S;
    }

    // ���� �� ��ŭ ��ȸ
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &t);

        // ��������� ����
        vec[a].push_back({b, t});
        vec[b].push_back({a, t});
    }

    // �ִܰŸ� ���̺� �ʱ�ȭ
    fill(dis, dis + N, INF);

    // 0�� �ؼ������� �����Ͽ� ���ͽ�Ʈ�� �˰��� ����
    dijkstra(0);

    // N - 1�� �ؼ��������� ��ΰ� ���ٸ� -1 ���
    if(dis[N - 1] == INF)
    {
        printf("-1\n");
    }
    // �׷��� �ʴٸ� �ִܰŸ� ���
    else
    {
        printf("%lld\n", dis[N - 1]);
    }
}
