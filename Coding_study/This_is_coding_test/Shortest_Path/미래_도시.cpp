#include<iostream>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 101 // �ִ� ȸ�� ���� 100���̹Ƿ� 101�� MAX ������ ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int C1 = 0;
int C2 = 0;
int X = 0;
int K = 0;

// �ִܰŸ� ���̺�
int graph[MAX][MAX];

int main()
{
    // ȸ�� �� N, ��� �� M �Է�
    cin >> N >> M;

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // �Է¹��� N���� ȸ�� �߿��� ���� ȸ��� ���� ȸ�簡 ���� ���� 0���� ����
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    // ��� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &C1, &C2);

        // ��ΰ� ����Ǹ� ��������� �̵��� �� ����
        graph[C1][C2] = 1;
        graph[C2][C1] = 1;
    }

    // �÷��̵� ���� �˰��� ����
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // ������ �Ǹ��� ȸ�� X, �Ұ����� �Ϸ� �� ȸ�� K �Է�
    cin >> X >> K;

    // 1�� ȸ�翡�� K ȸ������� �Ÿ��� K ȸ�翡�� X ȸ������� �Ÿ��� ����
    int dis = graph[1][K] + graph[K][X];

    // ���� �Ÿ��� INF ���϶�� ����Ǿ� �ִٴ� ���̹Ƿ� �Ÿ� ���, �׷��� ������ -1 ���
    if(dis < INF)
    {
        cout << dis << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}