#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int H1 = 0;
int H2 = 0;
int tar_H = 0;
int tar_dis = 0;
int tar_same = 1;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[20001];

// �ִܰŸ� ���̺�
int dis[20001];

void dijkstra(void)
{
    // {����ġ, �������} pair�� ��ҷ� ������ ����ġ�� �������� ��������(�ּ� ��, Min Heap)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ���� ��� �갣�� �ִ� ��� 0�� �켱���� ť�� ����
    pq.push({0, 1});

    // �ִܰŸ� ���̺� ����
    dis[1] = 0;

    while(!pq.empty())
    {
        // cost�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� �Ÿ�
        // hut�� �켱���� ť �ȿ��� ����ġ�� ���� ���� pair�� �갣
        int cost = pq.top().first;
        int hut = pq.top().second;
        pq.pop();

        // cost�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� �갣�� �湮�� �Ͱ� ����
        if(dis[hut] < cost)
        {
            continue;
        }

        // �ش� �갣�� �湮���� �ʾҴٸ� ����� �갣���� ��ȸ
        for(int i = 0; i < graph[hut].size(); i++)
        {
            // next_hut�� ���� �갣���� ����� �갣
            // next_cost�� ���� �갣���� ���� �Ÿ�(cost)�� ���� �갣�������� ����� �갣������ �Ÿ�(graph[hut][i].second)�� ���� �Ÿ�
            int next_hut = graph[hut][i].first;
            int next_cost = cost + graph[hut][i].second;

            // ������ ����� next_cost���� ���� �ִܰŸ� ���̺� ����� next_hut������ �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(next_cost < dis[next_hut])
            {
                // �ִܰŸ� ���̺� ����
                dis[next_hut] = next_cost;

                // �켱���� ť�� �Ÿ��� �갣 ������ ����
                pq.push({next_cost, next_hut});
            }
        }
    }
}

int main()
{
    // �갣�� ���� ��� ������ �Է�
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d",&H1, &H2);

        // ��ΰ� ����� ����̹Ƿ� H1�� H2�� ���� ��� �����͸� �ǹ��ϴ� vector �� �߰�
        graph[H1].push_back({H2, 1});
        graph[H2].push_back({H1, 1});
    }

    // �ִܰ�� ���̺� INF�� �ʱ�ȭ
    fill(dis, dis + 20001, INF);

    // ���ͽ�Ʈ�� �˰��� ����
    dijkstra();

    // �ִܰ�� ���̺��� �ִ밪�� ã�� ���� ���� ���� �ʱ�ȭ
    int max_val = 0;
    for(int i = 1; i <= N; i++)
    {
        // ���� ��ȸ���� �ִܰŸ� ���̺� ���� max_val���� ũ�ٸ� �Ʒ� ���� ����
        if(dis[i] > max_val)
        {
            // �ִ밪 ����
            max_val = dis[i];

            // ��¿� �ʿ��� �����͵� ����
            tar_H = i;
            tar_dis = dis[i];
            tar_same = 1;
        }
        // ���� ��ȸ���� �ִܰŸ� ���̺� ���� max_val�� �����ϴٸ� �Ʒ� ���� ����
        else if(dis[i] == max_val)
        {
            // ����� �ϴ� �갣�� �Ÿ��� ���� �갣�� �� ����
            tar_same++;
        }
    }

    cout << tar_H << " " << tar_dis << " " << tar_same << endl;
}