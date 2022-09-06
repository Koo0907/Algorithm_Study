#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

#define MAX 100

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int ch = 0;
int cnt = 0;

// ġ���� �迭
int map[MAX][MAX];

// �湮 ó�� �迭
bool visited[MAX][MAX];

// ġ���ǿ����� ġ�� ������ ���ϴ� �Լ�
void count_cheese(void)
{
	// �������� ch �ʱ�ȭ
	ch = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// �ش� ��ǥ�� ���� 1(ġ��)�̸� ch ����
			if(map[i][j] == 1)
			{
				ch++;
			}
		}
	}
}

// ġ� �� ��Ҵ��� Ȯ���ϴ� �Լ�
bool check(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// �ش� ��ǥ�� ���� 1(ġ��)�̸� flase ��ȯ
			if(map[i][j] == 1)
			{
				return false;
			}
		}
	}

	return true;
}

// ���� ������ ä��� BFS ���� �Լ�
// ����° �Ķ���ʹ� �ܺ� ����(2), ���� ����(3)�� ���� �ٸ��� ȣ��
void oxyzen_bfs(int x, int y, int cri)
{
	// �湮 ó�� �迭 �ʱ�ȭ
	memset(visited, false, sizeof(visited));
	
	// ť ����
	queue<pair<int, int>> q;

	// �Ķ���� ��ǥ ť�� �߰�
	q.push({x, y});

	// �Ķ���� ��ǥ cri(�ܺ� ����:2 or ���ΰ���:3) ����
	map[x][y] = cri;

	// �湮 ó��
	visited[x][y] = true;

	// ť�� �� ������ �ݺ�
	while(!q.empty())
	{
		// ť���� ��ǥ ���� �� ����
		x = q.front().first;
		y = q.front().second;
		q.pop();

		// ��,��,��,�� ���� ��ȸ
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ�� �� �� �ִ��� Ȯ��
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// ���� ��ǥ�� 0(����)�̰� ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
				if(map[next_x][next_y] == 0 && visited[next_x][next_y] == false)
				{
					// ���� ��ǥ cri(�ܺ� ����:2 or ���ΰ���:3) ����
					map[next_x][next_y] = cri;

					// ���� ��ǥ �湮 ó��
					visited[next_x][next_y] = true;

					// ���� ��ǥ ť�� �߰�
					q.push({next_x, next_y});
				}
			}
		}
	}
}

// ġ� ��� ������ �����ϴ� �Լ�
void melting_cheese(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// �ش� ��ǥ�� 1(ġ��)�̸� �Ʒ� ���� ����
			if(map[i][j] == 1)
			{
				// ġ���� ��ġ���� ��,��,��,�� ���� Ȯ��
				for(int k = 0; k < 4; k++)
				{
					int next_i = i + dx[k];
					int next_j = j + dy[k];

					// ���� ��ǥ�� �� �� �ִ��� Ȯ��
					if((next_i >= 0) && (next_i < N) && (next_j >= 0) && (next_j < M))
					{
						// ġ�� �ֺ� ��ǥ�� 2(�ܺ� ����)�� �ִٸ� �Ʒ� ���� ����
						if(map[next_i][next_j] == 2)
						{
							// ���� ��ǥ������ ġ��� ��Ƽ� 0���� �����ϰ� break
							map[i][j] = 0;
							break;
						}
					}
				}
			}
		}
	}
}

// 2(�ܺ� ����)�� 3(���� ����)�� �������� ���� ������ ��� 0(����)�� �����ϴ� �Լ�
void restore_oxyzen(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// ��ȸ���� ��ǥ�� 2 or 3�̶�� 0���� ����
			if((map[i][j] == 2) || (map[i][j] == 3))
			{
				map[i][j] = 0;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	while(1)
	{
		// ��������� ġ�� �� ���
		count_cheese();

		// �ܺ� ���� ������ ���� BFS �Լ� ȣ��
		oxyzen_bfs(0, 0, 2);

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < M; j++)
			{
				// ��ȸ���� ��ǥ�� 0�̶�� ���� ���⸦ �ǹ��ϹǷ� �Ʒ� ���� ����
				if(map[i][j] == 0)
				{
					// ���� ���� ������ ���� BFS �Լ� ȣ��
					oxyzen_bfs(i, j, 3);
				}
			}
		}

		// ġ� ��� �Լ� ȣ��
		melting_cheese();

		// �帥 �ð��� �ǹ��ϴ� cnt ����
		cnt++;

		// ġ� ��� ��Ҵ��� Ȯ��
		if(check())
		{
			break;
		}

		// ġ��ʿ����� �ܺ� ����, ���� ���⸦ ��� ����� ����
		restore_oxyzen();
	}

	cout << cnt << endl << ch << endl;
}