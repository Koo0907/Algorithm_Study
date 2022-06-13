#include<iostream>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 501 // �ִ� �л� ���� 500���̹Ƿ� 501�� MAX ������ ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int S1 = 0;
int S2 = 0;
int cnt = 0;

// �ִܰŸ� ���̺�
int graph[MAX][MAX];

int main()
{
    // �л� �� N, �� Ƚ�� M
    cin >> N >> M;

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // �л����� ���� �� ������ �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d",&S1, &S2);
        graph[S1][S2] = 1;
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

    for(int i = 1; i <= N; i++)
    {
        int temp = 0;

        // �� ��ȣ�� ���� ���� ��ȸ
        for(int j = 1; j <= N; j++)
        {
            // ��ȸ���� ���� �࿡ INF(������ ���� ���� ���ٴ� �ǹ�)�� ���ٸ� temp �� ����
            if((graph[i][j] != INF) ||(graph[j][i] != INF))
            {
                temp++;
            }
        }

        // temp ���� graph[i][j]�� �����ϰ� INF�� ���ٸ� ������ ������ �� �� �����Ƿ� cnt ����
        if(temp == (N - 1))
        {
            cnt++;
        }
    }

    cout << cnt << endl;
}