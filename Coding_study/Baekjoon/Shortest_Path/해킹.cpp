#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9     // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 10001   // ��ǻ���� �ִ� ��

using namespace std;

// ����� ���� �ʱ�ȭ
int T = 0;
int n = 0;
int d = 0;
int c = 0;
int a = 0;
int b = 0;
int s = 0;

// ��ǻ�͵鰣�� �������� ��Ÿ���� ����
vector<pair<int, int>> v[MAX];

// �ִܰŸ� ���̺�
int dis[MAX];

void dijkstra(void)
{
    // ������ �ɸ��� �ð����� �������� ���� �ϴ� �ּ� �� ť ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // ������ ���۵Ǵ� ��ǻ�Ϳ� ���� �ð� ť�� �߰�
    pq.push({0, c});

    // �ִܰŸ� ���̺� ����
    dis[c] = 0;

    // ť�� �� ������ �ݺ�
    while(!pq.empty())
    {
        // ť���� �����ð��� ��ǻ�� ������ ���� �� ����
        int time = pq.top().first;
        int com = pq.top().second;
        pq.pop();

        // time�� ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ��ǻ�ʹ� �湮�� ������ �Ǵ�
        if(dis[com] < time)
        {
            continue;
        }

        // ���� ��ǻ�Ϳ� �������� �ִ� ��ǻ�͵� ��ȸ
        for(int i = 0; i < v[com].size(); i++)
        {
            // next_time�� ���� ��ǻ�Ͱ� �����Ǳ� ������ �ð�\
            // next_com�� ������ ���� ��ǻ��
            int next_time = v[com][i].second + time;
            int next_com = v[com][i].first;

            // next_time�� �ִܰŸ� ���̺��� ������ �۴ٸ� �Ʒ� ���� ����
            if(next_time < dis[next_com])
            {
                // �ִܰŸ� ���̺� �ʱ�ȭ
                dis[next_com] = next_time;

                // ť�� ���� ��ǻ���� ������ �߰�
                pq.push({next_time, next_com});
            }
        }
    }
}

int main()
{
    cin >> T;

    for(int Tc = 0; Tc < T; Tc++)
    {
        // ������ ��ǻ�Ϳ� �׿� �ɸ��� �ð��� ��Ÿ���� ���� ����
        int hacked_com = 0;
        int all_time = 0;

        // ��ǻ���� ��, ������ ��, ������ ���۵� ��ǻ���� ��ȣ �Է�
        cin >> n >> d >> c;

        // ��ǻ�͵鰣�� �������� ��Ÿ��� ���� �ʱ�ȭ
        for(int i = 1; i <= n; i++)
        {
            v[i].clear();
        }

        // ��ǻ�͵鰣�� ������ ������ �Է�
        for(int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;

            // ������� �ƴ��� ����
            v[b].push_back({a, s});
        }

        // �ִܰŸ� ���̺� �ʱ�ȭ
        fill(dis, dis + MAX, INF);
        
        // ���ͽ�Ʈ�� �˰��� ����
        dijkstra();

        // �ִܰŸ� ���̺� ��ȸ
        for(int i = 1; i <= n; i++)
        {
            // �ִܰŸ� ���̺��� ���� INF�� �ƴ϶�� C�� ��ǻ�ͷ� ���ؼ� �����Ǿ��ٴ� �ǹ��̹Ƿ� �Ʒ� ���� ����
            if(dis[i] != INF)
            {
                // ������ ��ǻ�� �� ����
                hacked_com++;

                // �ִܰŸ� ���̺��� �ִ밪�� ������ ��ǻ�Ͱ� �����Ǳ������ �ð��� �����ϹǷ� �ִ밪 ����
                all_time = max(all_time, dis[i]);
            }
        }

        // ���
        cout << hacked_com << " " << all_time << endl;
    }
}