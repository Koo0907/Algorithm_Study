#include<iostream>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 101 // �ִ� ���� ���� 100�� �̹Ƿ� 101�� MAX ������ ����

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int m = 0;
int u = 0;
int v = 0;
int w = 0;

// 2���� �ִܰŸ� ���̺�
int graph[MAX][MAX];

int main()
{
    cin >> n >> m;

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // �Է¹��� n���� ���� �߿��� ���� ���ÿ� ���� ���ð� ���� ���� 0���� �ʱ�ȭ
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    // ���� ���� �Է�
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);

        // ���� ���ÿ� ���� ���ø� �����ϴ� �뼱�� �ϳ��� �ƴҼ��� �����Ƿ� �ּҰ��� ���̺� ����
        graph[u][v] = min(graph[u][v], w);
    }

    // �÷��̵� ���� �˰��� ����
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // ��� ���
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }

        cout << '\n';
    }
}