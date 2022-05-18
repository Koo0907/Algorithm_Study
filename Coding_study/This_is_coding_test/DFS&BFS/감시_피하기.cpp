/* ���� ��ũ */
/* https://www.acmicpc.net/problem/18428 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 6

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int cnt = 0;
bool check_flag = true;

// �ʱ� �־����� �л���� �����Ե��� ��ġ map
char map[MAX][MAX];

// ��ֹ� �� ���� ��ġ�� ���� �л���� �����Ե��� ��ġ map
char temp[MAX][MAX];

// dir �μ��� ���� �� �������� Ž���Ͽ� �л��� �ִ��� Ȯ���ϴ� �Լ�
void check_direction(int x, int y, int dir)
{
    int next_x = x + dx[dir];
    int next_y = y + dy[dir];

    // ���� ������ map�� ����� �ʴ´ٸ� �� ���⿡ �л��� �ִ��� Ȯ��
    if(next_x >= 0 && next_x < N && next_y >=0 && next_y < N)
    {
        // ���� ������ �� �����̶�� ���ȣ��
        if(temp[next_x][next_y] == 'X')
        {
            check_direction(next_x, next_y, dir);
        }
        // ���� ������ �л��� �ִٸ� flag�� clear
        else if(temp[next_x][next_y] == 'S')
        {
            check_flag = false;
        }
        // ���� ������ ��ֹ�('O')��� ���ȣ������ �����״� ���� Ȯ������ �ʾƵ� ������
    }
}

// ������('T')�� �ִ� ��ġ���� ��,��,��,�� �������� map ������ �л��� �ִ� Ȯ���ϴ� �Լ�
void check(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        // ���� ������ �������� �� ���⿡ �л��� �ִ��� Ȯ���ϴ� �Լ� ȣ��
        check_direction(x, y, i);
    }
}

// ��ֹ� ��ġ �Լ�
void obstacle(void)
{
    // ��ֹ��� ��� ��ġ�ߴٸ� �Ʒ� ���� ����
    if(cnt == 3)
    {
        // ��ֹ��� ��ġ�� ��츶�� ���� ������ �ִ��� Ȯ���ؾ� �ϹǷ� Ȯ�� ���� flag set
        check_flag = true;

        // ���� map�� ������ temp map�� ����
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                temp[i][j] = map[i][j];
            }
        }

        // �������� �ִ� ������ Ȯ�εǸ� ��,��,��,�� ���⿡ �л����� �ִ��� Ȯ���ϴ� �Լ� ȣ��
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(temp[i][j] == 'T')
                {
                    check(i, j);
                }
            }
        }

        // �̹� ��ֹ��� ��ġ�� ��쿡 flag�� clear���� �ʾҴٸ� ���� ������ �����Ѵٴ� �ǹ̹Ƿ� return
        if(check_flag == true)
        {
            return;
        }
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(map[i][j] == 'X')
                {
                    map[i][j] = 'O';
                    cnt++;

                    // ��ֹ� ��ġ �Լ� ȣ��
                    obstacle();

                    // ��ֹ��� ��� ��ġ�ϰ� ��� üũ�� ���� ���Ŀ��� flag�� clear���� �ʾҴٸ� ���� ������ �����Ѵٴ� �ǹ̹Ƿ� return
                    if(check_flag == true)
                    {
                        return;
                    }

                    // ��ֹ� ��ġ �� ��� üũ�� ����ƴٸ� ��ġ�� ��ֹ� �ʱ�ȭ
                    map[i][j] = 'X';
                    cnt--;
                }
            }
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // ��ֹ� ��ġ �Լ� ȣ��
    obstacle();

    // ���� ������ ������ �ǹ��ϴ� flag ���� ���� ���
    if(check_flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}