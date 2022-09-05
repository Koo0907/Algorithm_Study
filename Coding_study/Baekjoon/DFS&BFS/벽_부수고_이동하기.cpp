#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 1000

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int ans = 0;

// �� �迭
int map[MAX][MAX];

// ���� �μ� �Ϳ� ���� ���ο� �湮 ó�� �� ��� ���� 3���� �迭
int visited[2][MAX][MAX];

// BFS ���� �Լ�
int bfs(int wall, int x, int y)
{
	// ���� �μ� �Ϳ� ���� ���ο� ��ǥ�� ��ҷ� �ϴ� ť ����
	queue<pair<int, pair<int, int>>> q;

	// �ʱ� �� ť�� �߰�
	q.push({wall, {x, y}});

	// �ش� ��ǥ �湮 ó��
	visited[wall][x][y] = 1;

	// ť�� �� ������ �ݺ�
	while(!q.empty())
	{
		// ť�� �ִ� ������ ���� �� ����
		wall = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();

		// ������ ��ǥ�� ������ ��ǥ��� ���ݱ����� ��� ��ȯ
		if((x == (N - 1)) && (y == (M - 1)))
		{
			return visited[wall][x][y];
		}

		// ��,��,��,�� �������� ��ȸ
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			
			// ���� ��ǥ�� �� �ȿ� �ִ��� Ȯ��
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// ���� ��ǥ�� 0�� ���
				if(map[next_x][next_y] == 0)
				{
					// ���� ��ǥ�� �湮ó�� ���� �ʾҴٸ� �Ʒ� ���� ����
					if(visited[wall][next_x][next_y] == 0)
					{
						// ���� ��ǥ �湮 ó�� �� ��� ���� 
						visited[wall][next_x][next_y] = visited[wall][x][y] + 1;

						// ���� ��ǥ ť�� �߰�
						q.push({wall, {next_x, next_y}});
					}	
				}
				// ���� ��ǥ�� 1�� ���
				else
				{
					// ���� ���� �μ� ���� ���ٸ� �Ʒ� ���� ����
					if(wall == 0)
					{
						// ���� ��ǥ�� �湮ó�� ���� �ʾҴٸ� �Ʒ� ���� ����
						if(visited[wall + 1][next_x][next_y] == 0)
						{
							// ���� ��ǥ �湮 ó�� �� ��� ����
							// ������ ���� ��� �����ϴ� visited �迭�� wall = 1�� �迭��
							// ���ݱ����� wall = 0���� ���� �μ��� ���� ä�� ��θ� ������ ����
							// ���� ���� ������ ���� �ѹ� �ν����Ƿ� wall = 1�� visited �迭�� ��θ� ������
							visited[wall + 1][next_x][next_y] = visited[wall][x][y] + 1;

							// ���� ��ǥ ť�� �߰�
							q.push({wall + 1, {next_x, next_y}});
						}
					}
				}
			}
		}
	}
	// ��θ� ã�� ���ߴٸ� -1 ��ȯ
	return -1;
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}

	// �ʱ� ��ǥ�� ���� �μ��� �ʾҴٴ� ���ǿ��� BFS �Լ� ����
	ans = bfs(0, 0, 0);

	cout << ans << endl;

}