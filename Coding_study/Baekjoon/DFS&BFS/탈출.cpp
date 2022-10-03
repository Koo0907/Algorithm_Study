#include<iostream>
#include<vector>
#include<queue>

#define MAX 50

using namespace std;

// �� ������ ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int R = 0;
int C = 0;
int cnt = 0;
bool move_flag = false;
bool escape_flag = false;

// ���� �����͸� ��� �迭
char map[MAX][MAX];

// ���� ���� ������ �����ϴ� �Լ�
void water_fall(void)
{
    // ť ����
    queue<pair<int, int>> water_q;

    // ���� �� ��ȸ�Ͽ� ���� �ִ� ���� Ž��
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            // ���� �ִ� ������ �ִٸ� �Ʒ� ���� ����
            if(map[i][j] == '*')
            {
                // ť�� ��ǥ �߰�
                water_q.push({i, j});
            }
        }
    }

    // ť�� �� ������ ��ȸ
    while(!water_q.empty())
    {
        // ť���� ��ǥ ������ ���� �� ����
        int x = water_q.front().first;
        int y = water_q.front().second;
        water_q.pop();

        // ��,��,��,�� �� ���� ��ȸ
        for(int i = 0; i < 4; i++)
        {
            // ���� ��ǥ ���� ���
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ��ǥ ������ �� �� �ִ��� Ȯ��
            if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
            {
                // ���� ��ǥ ������ ��ĭ(.)�̶�� �Ʒ� ���� ����
                if(map[next_x][next_y] == '.')
                {
                    // ���� ��ǥ ���� ���� �ִ� ����(*)���� ����
                    map[next_x][next_y] = '*';
                }
            }
        }
    }
}

// ����ġ�� �̵��ϴ� ������ �����ϴ� �Լ�
void escape(void)
{
    // ť ����
    queue<pair<int, int>> escape_q;

    // ���� �� ��ȸ�Ͽ� ����ġ�� �̵��� ���� Ž��
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            // ����ġ�� �̵��� ������ �ִ� ����(S)�� �ִٸ� �Ʒ� ���� ����
            if(map[i][j] == 'S')
            {
                // ť�� ��ǥ �߰�
                escape_q.push({i, j});
            }
        }
    }

    // ����ġ�� �̵��� �ּ� �ѹ� �ߴٴ� �ǹ̸� ������ flag �ʱ�ȭ
    move_flag = false;

    // ť�� �� ������ ��ȸ
    while(!escape_q.empty())
    {
        // ť���� ��ǥ ������ ���� �� ����
        int x = escape_q.front().first;
        int y = escape_q.front().second;
        escape_q.pop();

        // ��,��,��,�� �� ���� ��ȸ
        for(int i = 0; i < 4; i++)
        {
            // ���� ��ǥ ���� ���
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ��ǥ ������ �� �� �ִ��� Ȯ��
            if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
            {
                // ���� ��ǥ ������ ����� ��(D)�̶�� �Ʒ� ���� ����
                if(map[next_x][next_y] == 'D')
                {
                    // ���� ���������Ƿ� �̵� Ȯ�� flag�� �ʱ�ȭ
                    move_flag = false;

                    // Ż�� ���� Ȯ�� flag�� set
                    escape_flag = true;

                    // �Լ� ����
                    return;
                }
                // ���� ��ǥ ������ ��ĭ(.)�̶�� �Ʒ� ���� ����
                else if(map[next_x][next_y] == '.')
                {
                    // ���� ��ǥ ���� ����ġ�� �̵��� �� �ִ� �����̹Ƿ� S�� ����
                    map[next_x][next_y] = 'S';

                    // �̵� Ȯ�� flag set
                    move_flag = true;
                }
                // �� ���� ������ �ƹ� ���� ���� ����
                else
                {
                    // do nothing...
                }
            }
        }
    }
}

int main()
{
    // R, C ������ �Է�
    scanf("%d %d", &R, &C);

    // �� ������ �Է�
    for(int i = 0; i < R; i++)
    {
        cin.ignore();
        for(int j = 0; j < C; j++)
        {
            scanf("%c",&map[i][j]);
        }
    }

    while(1)
    {
        // ���� ���� ���� ���� ����
        water_fall();

        // ����ġ�� �̵��ϴ� ���� ����
        escape();

        // �̵��� Ƚ�� ����
        cnt++;

        // �̵� Ȯ�� flag�� false ���¶�� ���ѹݺ��� Ż��
        if(move_flag == false)
        {
            break;
        }
    }

    // Ż�� Ȯ�� flag�� true��� �Ʒ� ���� ����
    if(escape_flag == true)
    {
        // Ż�� ������ �ǹ��ϹǷ� ���ݱ��� �̵��� Ƚ�� ���
        printf("%d\n", cnt);
    }
    else
    {
        // Ż�� ���и� �ǹ��ϹǷ� KAKTUS ���
        printf("KAKTUS\n");
    }
}
