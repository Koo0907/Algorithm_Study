#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 101

using namespace std;

// ����� ���� �ʱ�ȭ
int T = 0;
int N = 0;
int M = 0;
int K = 0;
int a = 0;
int b = 0;
int c = 0;
int ans = 0;
int min_val = INF;

// �ִܰŸ� �迭
int dis[MAX][MAX];

// ģ������ �ִ� ���� �����͸� ��� ����
vector<int> friend_vec;

// ������ �ʱ�ȭ �Լ�
void val_clear(void)
{
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            if(i == j)
            {
                continue;
            }
            
            // ��� ���� �ٸ� ��쿡�� INF�� �ʱ�ȭ
            dis[i][j] = INF;
        }
    }

    // ģ������ �ִ� ���� �����͸� ��� ���� �ʱ�ȭ
    friend_vec.clear();

    // �ּҰ� �Ǵ��� ���� ���� �ʱ�ȭ
    min_val = INF;
}

int main()
{
    // �׽�Ʈ ���̽� �� �Է�
    scanf("%d", &T);

    for(int tc = 0; tc < T; tc++)
    {
        // ���� ���� ��� �� �Է�
        scanf("%d %d", &N, &M);

        // ������ �ʱ�ȭ
        val_clear();

        // ��� ������ �Է�
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            dis[a][b] = c;
            dis[b][a] = c;
        }

        // �÷��̵� ���� �˰��� ����
        for(int k = 1; k <= N; k++)
        {
            for(int i = 1; i <= N; i++)
            {
                for(int j = 1; j <= N; j++)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        // ģ���� �� �Է�
        scanf("%d", &K);

        // ģ������ �ִ� �� �Է�
        for(int i = 0; i < K; i++)
        {
            scanf("%d", &a);
            friend_vec.push_back(a);
        }

        // �� �濡 ���ؼ� ��ȸ
        for(int i = 1; i <= N; i++)
        {
            int temp = 0;

            // ģ������ �ִ� �濡������ ���� ��ȸ�ϴ� ������� �Ÿ��� �ջ��Ͽ� temp ���� ����
            for(int j = 0; j < K; j++)
            {
                temp += dis[friend_vec[j]][i];
            }

            // temp ���� ���� �ּҰ����� �۴ٸ� �Ʒ� ���� ����
            if(temp < min_val)
            {
                // �ּҰ� ����
                min_val = temp;

                // ��� ���� �� ����
                ans = i;
            }
        }

        // ��� ���� �� ���
        printf("%d\n", ans);
    }
}