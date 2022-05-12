#include<iostream>
#include<vector>

#define MAX 50

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int T = 0;
int M = 0;
int N = 0;
int K = 0;
int cnt = 0;

int map[MAX][MAX] = {0};
vector<int> earthworm;

void find_earthworm(int x, int y)
{
    // �ش� ���� �湮 ǥ��
    map[x][y] = 0;

    // ��,��,��,�� �� ���⿡ ���ؼ� DFS �Լ� ȣ�� �õ�
    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // ���� ��ǥ���� map�� ����� �ʴ��� Ȯ��
        if((next_x >= 0) && (next_x < M) && (next_y >= 0) && (next_y < N))
        {
            // ���� ��ǥ�� ���� �湮���� �ʾҴٸ� DFS �Լ� ȣ��
            if(map[next_x][next_y] == 1)
            {
                find_earthworm(next_x, next_y);
            }
        }
    }

}

int main() {

    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        for(int j = 0; j < K; j++)
        {
            int n1, n2;
            cin >> n1 >> n2;
            map[n1][n2] = 1;
        }

        // ��ü ��ǥ Ž��
        for(int j = 0; j < M; j++)
        {
            for(int k = 0; k < N; k++)
            {
                if(map[j][k] == 1)
                {
                    find_earthworm(j, k);
                    cnt++;
                }
            }
        }

        earthworm.push_back(cnt);
        cnt = 0;
    }

    for(auto itr = earthworm.begin(); itr != earthworm.end(); ++itr)
    {
        cout << *itr << endl;
    }
}