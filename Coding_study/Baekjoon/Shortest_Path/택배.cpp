#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9   // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 201   // �������� �ִ��

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int m = 0;
int u = 0;
int v = 0;
int w = 0;

// ������ ���� �ִܰŸ� ���̺�
int dis[MAX][MAX];

// ������ ���� �ִܰŸ��� �̵��� �� ���� ���� ��ġ�� �������� ��Ÿ���� �迭
int res[MAX][MAX];

// �ִܰŸ� ���̺� �ʱ�ȭ �Լ�
void map_clear(void)
{
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			// ��� ���� �ٸ� ������ INF�� �ʱ�ȭ
			if(i != j)
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
    cin >> n >> m;

    // �ִܰŸ� ���̺� �ʱ�ȭ
    map_clear();

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        // �ִܰŸ� ���̺� �ٷ� �� ����
        dis[u][v] = w;
        dis[v][u] = w;

        // �־��� ��ο��� ���� ���� ��ġ�� ������ ����
        res[u][v] = v;
        res[v][u] = u;
    }
    
    // �÷��̵� ���� �˰��� ����
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                // k �������� ���İ��� ��ΰ� �� ª�� �Ÿ���� �Ʒ� ���� ����
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    // �ִܰŸ� ���̺� ����
                    dis[i][j] = dis[i][k] + dis[k][j];

                    // ���İ��� �����嵵 j�� �ƴ� k�� ����
                    res[i][j] = res[i][k];
                }
            }
        }
    }

    // ���İ��� ������ �迭 ���
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            // ���� 0�� ���� '-' ���
            if(res[i][j] == 0)
            {
                printf("- ");
            }
            else
            {
                printf("%d ",res[i][j]);
            }
        }
        printf("\n");
    }
}