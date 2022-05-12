#include<iostream>
#include<queue>

#define MAX 201

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;

int map[MAX][MAX] = {0};
queue<pair<int,int>> path;

void find_path(int x, int y)
{
    // �Լ� ȣ��Ǹ� queue�� ��ǥ �߰�
    path.push({x, y});

    // queue�� ����� �� ���� �ݺ�
    while(!path.empty())
    {
        // ���� queue�� �ִ� ��ǥ �����ϰ� ����
        x = path.front().first;
        y = path.front().second;
        path.pop();

        // ��,��,��,�� �� ���⿡ ���ؼ� BFS ȣ�� �õ�
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // ���� ��ǥ���� Map�� ����� �ʴ��� Ȯ��
            if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
            {
                // ���� ��ǥ�� ���� 1���� Ȯ��(= ������ ������)
                if(map[next_x][next_y] == 1)
                {
                    // queue�� ���� ��ǥ �߰�
                    path.push({next_x, next_y});

                    // ���� ��ǥ�� ���� ���� ��ǥ���� +1�Ͽ� ��� Ƚ�� �߰�
                    map[next_x][next_y] = map[x][y] + 1;
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // ���ӵ� ���ڿ� ���ؼ� 1������ �Է� �޵��� ��
            // ex) 00110 -> 0, 0, 1, 1, 0
            scanf("%1d",&map[i][j]);
        }
    }

    find_path(0,0);

    cout << map[N - 1][M - 1] << endl;
}