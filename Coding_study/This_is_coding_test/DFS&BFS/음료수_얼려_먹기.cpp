#include<iostream>

#define MAX 1000

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int M = 0;
int N = 0;
int cnt = 0;

int ice[MAX][MAX];

void dfs(int x, int y)
{
    // �Լ� ȣ�� �ÿ� �ش� �ε��� �湮 ǥ��
    ice[x][y] = 1;

    // ��,��,��,�� �� ���⿡ ���ؼ� DFS �Լ� ȣ�� �õ�
    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // ���� ��ǥ���� Map�� ����� �ʴ��� Ȯ��
        if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
        {
            // ���� ��ǥ�� ���� �湮���� �ʾҴٸ� DFS �Լ� ȣ��
            if(ice[next_x][next_y] == 0)
            {
                dfs(next_x, next_y);
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
            scanf_s("%1d", &ice[i][j]);
        }
    }

    // ��ü ��ǥ Ž��
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // �ش� ��ǥ�� ���� �湮���� �ʾҴٸ� DFS �Լ� ȣ��
            if(ice[i][j] == 0)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}