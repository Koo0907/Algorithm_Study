#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 401

using namespace std;

// ����� ���� �ʱ�ȭ
int V = 0;
int E = 0;
int a = 0;
int b = 0;
int c = 0;
int ans = INF;

vector<pair<int, int>> vec[MAX];

// �ִܰŸ� �迭
int dis[MAX][MAX];

// �ִܰŸ� �迭 �ʱ�ȭ
void map_clear(void)
{
	for(int i = 1; i <= V; i++)
	{
		for(int j = 1; j <= V; j++)
		{
			// ��� ���� ���� ��쿡�� 0���� �ʱ�ȭ
			if(i == j)
			{
				dis[i][j] = 0;
			}
			// �� ���̿��� INF�� �ʱ�ȭ
			else
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &V, &E);

	// �ִܰŸ� 2���� �迭 �ʱ�ȭ
	map_clear();

	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d",&a, &b, &c);
		// �Ϲ��������� ����
		dis[a][b] = c;
	}

	// �÷��̵� �ͼ� �˰��� ����
	for(int k = 1; k <= V; k++)
	{
		for(int i = 1; i <= V; i++)
		{
			for(int j = 1; j <= V; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i <= V; i++)
	{
		for(int j = 1; j <= V; j++)
		{
			// ��� ���� �ٸ� ��ǥ�� ���� ���� ����� ��ΰ� �ִٸ� i -> j -> i�� ���ƿ��� ���� �ִٴ� ���̹Ƿ� �ּҰ� ���� ���� ����
			if((i != j) && (dis[i][j] != INF) && (dis[j][i] != INF))
			{
				// ����� ���� ���� ���ݱ��� ���� �ּҰ����� �۴ٸ� ����
				if(dis[i][j] + dis[j][i] < ans)
				{
					ans = dis[i][j] + dis[j][i];
				}
			}
		}
	}

	// ��ΰ� �ִٸ� �ּҰ� ���
	if(ans != INF)
	{
		cout << ans << endl;
	}
	// ��ΰ� ���ٸ� -1 ���
	else
	{
		cout << -1 << endl;
	}
}