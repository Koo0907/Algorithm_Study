#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9     // ������ �ǹ��ϴ� INF
#define MAX 50001   // �갣�� �ִ� ��

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;

// �갣�� ���� �����͸� ���Ḯ��Ʈ�� ������ ����
vector<pair<int, int>> vec[MAX];

// �ִܰŸ� ���̺�
int dis[MAX];

void dijkstra(int x)
{
    // �ִܰŸ� ���̺� �ʱ�ȭ
    fill(dis, dis + MAX, INF);

    // ���� ���� ������������ �����ϴ� �ּ��� �켱���� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ��� �갣�� �ִܰŸ� ������ ť�� �߰�
    pq.push({0, x});

    // �ִܰŸ� ���̺� ����
    dis[x] = 0;

    // ť�� �� ������ ��ȸ
    while(!pq.empty())
    {   
        // ť���� ������ ���� �� ����
        int cow = pq.top().first;
        int hut = pq.top().second;
        pq.pop();

        // cow�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ���� �湮�� �Ͱ� ����
        if(dis[hut] < cow)
        {
            continue;
        }

        // ��ȸ���� �갣�� ����� �갣�� ��ȸ
        for(int i = 0; i < vec[hut].size(); i++)
        {
            // ���� �갣�� ���� ���� ���� ���� �갣������ ���� ���� ���� �� ����
            int next_cow = cow + vec[hut][i].second;
            int next_hut = vec[hut][i].first;

            // next_cow ���� �ִܰŸ� ���̺��� ������ ������ �Ʒ� ���� ����
            if(dis[next_hut] > next_cow)
            {
                // �ִܰŸ� ���̺� ����
                dis[next_hut] = next_cow;

                // ���� �갣�� ���ݱ����� ���� �� ť�� �߰�
                pq.push({next_cow, next_hut});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        // ��������� ����
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    // 1�� �갣���� ���
    dijkstra(1);

    // N�� �갣������ �ִܰŸ��� ���
    printf("%d\n", dis[N]);

}