#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 50

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int n = 0;

// �̷� ��
int map[MAX][MAX];

// �ִܰŸ� ���̺�
int dis[MAX][MAX];

// �ִܰŸ� ���̺� �ʱ�ȭ
void map_clear(void)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			dis[i][j] = INF;
		}
	}
}

void dijkstra(void)
{
	// �ִܰŸ� ���̺� �ʱ�ȭ
	map_clear();

	// {�ݾ�, {x��ǥ, y��ǥ}}�� ��ҷ� �ϴ� �ּ� �� �켱���� ť ����
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	// �ִܰŸ� ���̺� ����
	// map�� ���� 1�� ��찡 �� �����̰� 0�� ��찡 �ν��� �ϴ� ���̹Ƿ� (1 - map[i][j])�� ���� 
	dis[0][0] = 1 - map[0][0];

	// ���� ��ǥ �� �ִܰŸ� ����
	pq.push({dis[0][0], {0, 0}});

	// ť�� �� ������ �ݺ�
	while(!pq.empty())
	{
		// roo�� ���� ��ǥ������ �μ� ���� �ּҰ�
		// x�� ���� ��ǥ�� x ��
		// y�� ���� ��ǥ�� y ��
		int room = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();

		// ��,��,��,�� ���� ��ȸ
		for(int i = 0; i < 4; i++)
		{
			// next_x�� ���� ��ǥ�� x ��
			// next_y�� ���� ��ǥ�� y ��
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ�� �� �ȿ� �ִٸ� �Ʒ� ���� ����
			if((next_x >= 0) && (next_x < n) && (next_y >= 0) && (next_y < n))
			{
				// next_room�� ���� ��ǥ���� �μ� ���� ���� ���� ��ǥ�� ��, Ȥ�� ������ ���� ��
				// ���� ��ǥ�� ������ 0�� ��쿡�� ���� �ν��� �ϹǷ� (1 - map[i][j]) ���
				int next_room = 1 - map[next_x][next_y] + room;

				// next_room ���� �ִܰŸ� ���̺��� ������ �۴ٸ� �Ʒ� ���� ����
				if(next_room < dis[next_x][next_y])
				{
					// �ִܰŸ� ���̺� ����
					dis[next_x][next_y] = next_room;

					// �켱���� ť�� ����
					pq.push({next_room, {next_x, next_y}});
				}
			}
		}
	}
}

int main()
{
	scanf("%d",&n);

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	dijkstra();

	cout << dis[n - 1][n - 1] << endl;

}