#include<iostream>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����
#define MAX 501 // �ִ� �л� ���� 500���̹Ƿ� 501�� MAX ������ ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int cnt = 0;

// 2���� �ִܰŸ� ���̺�
int graph[MAX][MAX];

int main()
{
    cin >> N >> M;

    // �ִܰŸ� ���̺� INF�� �ʱ�ȭ
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // �л����� Ű �� ������ �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);

        // u��° �л����� v��° �л��� Ű�� �� ũ�ٴ� 
        graph[u][v] = 1;
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
            // ��ȸ���� ���� �࿡ INF(Ű�� ���� ���� ���ٴ� �ǹ�)�� ���ٸ� temp �� ����
            if((graph[i][j] != INF) || (graph[j][i] != INF))
            {
                temp++;
            }
        }

        // temp ���� graph[i][j]�� �����ϰ� INF�� ���ٸ� Ű�� ������ �� �� �����Ƿ� cnt ����
        if(temp == N - 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

}