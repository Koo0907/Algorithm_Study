#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define INF -1
#define MAX 50

using namespace std;

// ��,��,��,�� ���� ����
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int max_val = 0;
int ans = 0;

// ������ ���� ��
char map[MAX][MAX];

// �湮 ó�� �� ��� ��
int visited[MAX][MAX];

// BFS ���� �Լ�
void bfs(int x, int y)
{
	// �湮 ó�� �� ��� �� �ʱ�ȭ
	memset(visited, INF, sizeof(visited));

	// ť ����
	queue<pair<int, int>> q;

	// �Ķ���� ��ǥ ť�� �߰�
	q.push({ x, y });

	// �湮 ó�� �� ��� ����
	visited[x][y] = 0;

	// ť�� �� ������ �ݺ�
	while (!q.empty())
	{
		// ť�� �ִ� ��ǥ ������ ����
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// ��,��,��,�� ���� ��ȸ
		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ�� �� �� �ִ��� Ȯ��
			if ((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// ���� ��ǥ�� ���� �湮���� �ʾҰ� ���� ��ǥ�� ������ �������� Ȯ��
				if ((visited[next_x][next_y] == INF) && (map[next_x][next_y] == 'L'))
				{
					// ���� ��ǥ �湮 ó�� �� ��� ����
					visited[next_x][next_y] = visited[x][y] + 1;

					// ���� ��ǥ ť�� �߰�
					q.push({ next_x, next_y });

					// �ִ� ��� �� ����
					max_val = max(max_val, visited[next_x][next_y]);
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1s", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			// ��� ���� ��ǥ���� BFS ����
			if (map[i][j] == 'L')
			{
				bfs(i, j);
			}
		}
	}

	// �ִ� ��ΰ� ���
	cout << max_val << endl;

}