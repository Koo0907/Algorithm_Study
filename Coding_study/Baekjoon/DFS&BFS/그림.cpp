#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 500

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int n = 0;
int m = 0;
int cnt = 0;
int max_val = 0;

// ��ȭ�� �迭
int picture[MAX][MAX];

// BFS ���� �Լ�
void bfs(int x, int y)
{
    // �׸��� ũ�� �ʱ�ȭ
    int size = 1;

    // ť ����
    queue<pair<int, int>> q;

    // ť�� ���� ��ǥ �߰�
    q.push({x, y});

    // ���� ��ǥ�� ���� 2�� �����Ͽ� �湮�Ͽ����� ǥ��
    picture[x][y] = 2;

    // ť�� �� ������ ��ȸ
    while(!q.empty())
    {
        // ť���� ������ ���� �� ����
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // ��,��,��,�� ���� ��ȸ
        for(int i = 0; i < 4; i++)
        {
            // ���� ��ǥ ���
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ��ǥ�� ��ȭ�� ���� �ִ��� Ȯ��
            if((next_x >= 0) && (next_x < n) && (next_y >= 0) && (next_y < m))
            {
                // ���� ��ǥ�� 1(���� �湮���� ���� ���� ĥ���� �ִ� ����)���� Ȯ��
                if(picture[next_x][next_y] == 1)
                {
                    // ť�� ���� ��ǥ �߰�
                    q.push({next_x, next_y});

                    // ���� ��ǥ �湮 ó��
                    picture[next_x][next_y] = 2;

                    // �׸��� ũ�� ����
                    size++;
                }
            }
        }
    }

    // �׸��� ũ�� �ִ밪 ����
    max_val = max(max_val, size);
}

int main()
{
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &picture[i][j]);
        }
    }

    // ��ȭ�� ��ǥ ����Ž��
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            // ��ǥ ������ 1�� ��쿡�� �Ʒ� ���� ����
            if(picture[i][j] == 1)
            {
                // BFS �Լ� ȣ��
                bfs(i, j);

                // �׸��� ���� ����
                cnt++;
            }
        }
    }

    // ���
    printf("%d\n%d\n", cnt, max_val);
}