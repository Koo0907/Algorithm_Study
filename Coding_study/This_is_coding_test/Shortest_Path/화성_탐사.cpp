#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 125 // �ִ� Ž�� ���� ���� 125�̹Ƿ� MAX ������ ����

using namespace std;

// ��,��,��,�� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int T = 0;
int N = 0;

// ��ü ��
int graph[MAX][MAX];

// �ִܰŸ� ���̺�
int dis[MAX][MAX];

void dijkstra(void)
{
    // {����ġ, {x��ǥ, y��ǥ}}} pair-pair�� ��ҷ� ������ ����ġ�� �������� ��������(�ּ� ��, Min Heap)���� ���ĵǵ��� �켱���� ť ����
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // ������ (0,0)������ �ִܰŸ� ���̺� ����
    dis[0][0] = graph[0][0];

    // (0,0)�� ���� �ִܰŸ� ������ ť�� ����
    pq.push({graph[0][0], {0, 0}});

    while(!pq.empty())
    {
        // d = (0,0)���� �켱���� ť �ȿ��� �Ÿ��� ���� ª�� �������� ��ǥ������ �Ÿ�
        // x = �켱���� ť �ȿ��� �Ÿ��� ª�� ���� �������� ��ǥ�� x��
        // y = �켱���� ť �ȿ��� �Ÿ��� ª�� ���� �������� ��ǥ�� y��
        int d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        // d�� ���� ���� ����Ǿ� �ִ� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ��ǥ�� �湮�� �Ͱ� ����
        if(dis[x][y] < d)
        {
            continue;
        }

        // ��,��,��,�� �������� ��ǥ ��ȸ
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ��ǥ�� ���� ������ �Ѿ�ٸ� ����
            if((next_x < 0) || (next_x >= N) || (next_y < 0) || (next_y >= N))
            {
                continue;
            }

            // next_d = (0,0)���������� �Ÿ��� ��ȸ���� ��ǥ�� �Ÿ��� ���� �Ÿ�
            int next_d = d + graph[next_x][next_y];

            // ������ ����� next_d ���� �ִܰŸ� ���̺��� �Ÿ����� �۴ٸ� �Ʒ� ���� ����
            if(dis[next_x][next_y] > next_d)
            {
                // �ִܰŸ� ���̺� ����
                dis[next_x][next_y] = next_d;

                // �켱���� ť�� ����ġ�� ��ǥ ������ ����
                pq.push({next_d, {next_x, next_y}});
            }
        }
    }
}

int main()
{
    // �׽�Ʈ ���̽��� �� T �Է�
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        // Ž�� ���� �� N �Է�
        cin >> N;

        // �� ���� �Է�
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }

        // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
        for(int i = 0; i < N; i++)
        {
            fill(dis[i], dis[i] + MAX, INF);
        }

        // ���ͽ�Ʈ�� �˰��� ����
        dijkstra();

        // (0,0)���� (N-1,N-1)������ �ִܰŸ� ������ ���
        cout << dis[N - 1][N - 1] << endl;
    }
}