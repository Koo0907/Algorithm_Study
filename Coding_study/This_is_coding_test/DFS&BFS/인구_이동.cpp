#include<iostream>
#include<queue>
#include<cstring>

#define MAX 50

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int N = 0;
int L = 0;
int R = 0;
int cnt = 0;
int uni_cnt = 0;
int sum = 0;
unsigned char check_flag = 0;

int map[MAX][MAX];
int visited[MAX][MAX];

// �� ������ �α� ���̸� ���ϴ� �Լ�
int abs(int x, int y)
{
    if(x > y)
    {
        return x - y;
    }
    else
    {
        return y - x;
    }
}

void move_popul(int x, int y)
{
    // ��ȸ�� ���� ť
    queue<pair<int, int>> q;

    // ������ ���� �α� �̵��� ���� ť
    queue<pair<int, int>> united_q;

    // �ش� �Լ� ȣ��ȴٸ� �湮 ó��
    visited[x][y] = 1;

    q.push({x, y});

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // ��, ��, ��, �� �������� ��ȸ
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ������ map�� ����� �ʴ��� Ȯ��
            if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
            {
                // ���� ������ �̹� �湮�߾����� Ȯ��
                if(visited[next_x][next_y] == 0)
                {
                    int dif = abs(map[x][y], map[next_x][next_y]);

                    // �� ������ �α� ���̰� L�� R �������� Ȯ��
                    if((dif >= L) && (dif <= R))
                    {
                        // ���� ���� �湮 ó��
                        visited[next_x][next_y] = 1;

                        // ť �߰�
                        q.push({next_x, next_y});

                        // ���� ���ʷ� �߰ߵ� �����̶�� ������ ����(x, y)�� �α� �̵��� ���� ť�� �߰�
                        // �α� �̵��� ���� ��ȸ�� ������ �α� ��굵 �ʿ��ϱ� ����
                        if(united_q.size() == 0)
                        {
                            united_q.push({x, y});
                            uni_cnt++;
                            sum += map[x][y];
                        }

                        // ���� ������ �α� �̵��� ���� ť�� �߰�
                        united_q.push({next_x, next_y});

                        // ���� �� �� �� �α��� ���
                        uni_cnt++;
                        sum += map[next_x][next_y];                     
                    }
                }
            }
        }
    }

    // �α� �̵��� ���� ť�� ���� �����Ѵٸ�(=������ �̷�����ٸ�) �Ʒ� ���� �߰�
    if(united_q.size() > 0)
    {
        // ���� �������� ������ �̷������� üũ�ϴ� flag set
        // flag�� ���� �������Ѽ� ����
        check_flag++;
        while(!united_q.empty())
        {
            int x = united_q.front().first;
            int y = united_q.front().second;
            united_q.pop();
            map[x][y] = (sum / uni_cnt);
        }

        // �α� �̵��� ������ ���� ���� �� �α��� clear
        uni_cnt = 0;
        sum = 0;
    }
}

int main()
{
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    while(1)
    {
        // ��ȸ�� �ϱ� ���� �湮 Ȯ�� �迭 �� ���� ���� flag clear
        memset(visited, 0, sizeof(visited));
        check_flag = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j< N; j++)
            {
                if(visited[i][j] == 0)
                {
                    move_popul(i, j);
                }
            }
        }

        // ��� �������� Ȯ���������� �ѹ��� ������ �̷������ �ʾҴٸ� �ݺ��� Ż��
        if(check_flag == 0)
        {
            break;
        }

        cnt++;
    }

    cout << cnt << endl;
}