#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 125

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int cnt = 0;

// ���� ��
int map[MAX][MAX];

// �ִܰŸ� ���̺�
int dis[MAX][MAX];

// �ִܰŸ� ���̺� �ʱ�ȭ
void map_clear(void)
{
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0; j < MAX; j++)
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

	// ���� ��ǥ �� �ݾ� ����
	pq.push({map[0][0], {0, 0}});

	// �ִܰŸ� ���̺� ����
	dis[0][0] = map[0][0];

	// ť�� �� ������ �ݺ�
	while(!pq.empty())
	{
		// cost�� ���� ��ǥ�� �ݾ�
		// x�� ���� ��ǥ�� x ��
		// y�� ���� ��ǥ�� y ��
		int cost = pq.top().first;
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
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
			{
				// next_cost�� ���� ��ǥ�� �ݾװ� ���� ��ǥ�� �ݾ��� ��
				int next_cost = cost + map[next_x][next_y];

				// next_cost ���� �ִܰŸ� ���̺��� ������ �۴ٸ� �Ʒ� ���� ����
				if(dis[next_x][next_y] > next_cost)
				{
					// �ִܰŸ� ���̺� ����
					dis[next_x][next_y] = next_cost;

					// �켱���� ť�� ����
					pq.push({next_cost, {next_x, next_y}});
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d", &N);

		// 0 �ԷµǸ� ����
		if(N == 0)
		{
			break;
		}

		// �׽�Ʈ ���̽� ��
		cnt++;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}

		dijkstra();

		cout << "Problem " << cnt << ": " << dis[N - 1][N - 1] << endl;
	}

}