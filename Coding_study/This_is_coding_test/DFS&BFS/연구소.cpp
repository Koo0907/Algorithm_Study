#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 8

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int cnt = 0;
int res = 0;
int real_res = 0;

// �ʱ� ������ ��
int map[MAX][MAX];

// �� ���� ���� ������ ��
int temp[MAX][MAX];

// ���� ���� ���
void count_safety(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(temp[i][j] == 0)
            {
                res++;
            }
        }
    }
}

// ���̷��� Ȯ�� �Լ�
void spread_virus(int x, int y)
{
    // ���̷����� Ȯ��� ������ 3���� ǥ���Ͽ� �湮�ߴٴ� ���� üũ
    temp[x][y] = 3;

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        // ���̷����� �ִ� �������� ������ ������ 0���� Ȯ��
        if(temp[next_x][next_y] == 0)
        {
            // ���� ������ map�� ����� �ʾҴٸ� �Լ� ȣ��
            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
            {
                spread_virus(next_x, next_y);
            }
        }
    }
}

// �� ����� �Լ�
void wall(void)
{
    // ���� ��� �����ٸ� �Ʒ� ���� ����
    if(cnt == 3)
    {
        // ���� map�� ������ temp map�� ����
        for(int i = 0; i < N; i++)
        {
            for(int j =0; j < M; j++)
            {
                temp[i][j] = map[i][j];
            }
        }

        // ���̷����� �ִ� ������ Ȯ�εǸ� ���̷��� Ȯ�� �Լ� ȣ��
        for(int i = 0; i < N; i++)
        {
            for(int j =0; j < M; j++)
            {
                if(temp[i][j] == 2)
                {
                    spread_virus(i, j);
                }
            }
        }

        // ���� ���� ���
        count_safety();

        // ���� ���� ���� ������ ���� ����Ǿ� �ִ� ������ ũ�ٸ� ����
        if(res > real_res)
        {
            real_res = res;
        }

        res = 0;
    }
    else
    {
        for(int i = 0; i< N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(map[i][j] == 0)
                {
                    map[i][j] = 1;
                    cnt++;

                    // �� ����� �Լ� ȣ��
                    wall();
                    
                    // �� ����� ������ �ѹ� ����ƴٸ� ���� �� �ʱ�ȭ
                    map[i][j] = 0;
                    cnt--;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    // �� ����� �Լ� ȣ��
    wall();

    cout << real_res << endl;
}