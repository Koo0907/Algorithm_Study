#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 101

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int m = 0;
int r = 0;
int t = 0;
int a = 0;
int b = 0;
int l = 0;
int ans = 0;

// ������ ������ ����
vector<int> v;

// �ִܰŸ� �迭
int dis[MAX][MAX];

// �ִܰŸ� �迭 �ʱ�ȭ
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
	scanf("%d %d %d",&n, &m, &r);

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&t);
		v.push_back(t);
	}

	// �ִܰŸ� �迭 �ʱ�ȭ
	map_clear();

	for(int i = 0; i < r; i++)
	{
		scanf("%d %d %d",&a, &b, &l);
		// �瓇������ ����
		dis[a][b] = l;
		dis[b][a] = l;
	}

	// �÷��̵� ���� �˰��� ����
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	for(int i = 1; i <= n; i++)
	{
		// item�� ���� �������� ��
		// now_path�� ���ݱ��� ������ �Ÿ�
		int item = 0;
		int now_path = 0;

		// ���ϵ� ��ġ���� �����Ͽ� ��ȸ
		for(int j = 1; j <= n; j++)
		{
			// now_path�� ����Ǿ� �ִ� ��ġ�� ����� ���� m���� �۴ٸ� �Ʒ� ���� ����
			if((dis[i][j] != INF) && (now_path + dis[i][j] <= m))
			{
				// ���� �������� �� ����
				item += v[j - 1];
			}
		}

		// ���� �������� �� �߿����� �ִ밪 ����
		ans = max(ans, item);
	}

	cout << ans << endl;
}