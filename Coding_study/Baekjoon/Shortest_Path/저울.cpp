#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 101

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;

// �ִܰŸ� �迭
int dis[MAX][MAX];

// �� ��� �Է� ����
vector<int> v;

// �ִܰŸ� �迭 �ʱ�ȭ
void map_clear(void)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			dis[i][j] = INF;
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	// �ִܰŸ� 2���� �迭 �ʱ�ȭ
	map_clear();

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d",&a, &b);

		// a�� b���� ���̴ٴ� �ǹ�
		dis[a][b] = 1;
	}

	// �÷��̵� �ͼ� �˰��� ����
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

	for(int i = 1; i <= N; i++)
	{
		int cnt = 0;
		for(int j = 1; j <= N; j++)
		{
			// ��� ���� ��������� ���� INF(�������� ���ٴ� �ǹ�)��� cnt ����
			if((dis[i][j] == INF) && (dis[j][i] == INF))
			{
				cnt++;
			}
		}

		// ��� ���� ���� ���� �����ϱ� ���� cnt - 1 ����
		v.push_back(cnt - 1);
	}

	// ���
	for(vector<int>::iterator itr = v.begin(); itr < v.end(); ++itr)
	{
		cout << *itr << endl;
	}
}