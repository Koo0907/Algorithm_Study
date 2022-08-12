#include<iostream>
#include<queue>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int N = 0;
int M = 0;
int cnt = 0;
int map[100][100];
queue<pair<int, int>> path;

void bfs(int x, int y)
{
	// queue�� ��ǥ �߰�
	path.push({x, y});

	// queue�� ����� �� ���� �ݺ�
	while(!path.empty())
	{
		// ���� queue�� ����ִ� ��ǥ �����ϰ� ����
		x = path.front().first;
		y = path.front().second;
		path.pop();

		for(int i = 0; i < 4; i++)
		{
			// ���⺤�� ����ؼ� ���� ��ǥ ����
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ���� map �ȿ� ������ �Ʒ� ���� ����
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
			{
				// ���� ��ǥ�� ���� ���� 1�̶�� �Ʒ� ���� ����
				if(map[next_x][next_y] == 1)
				{
					// ���� ��ǥ ���� ���� ��ǥ �� + 1�� ����
					map[next_x][next_y] = map[x][y] + 1;

					// queue�� ���� ��ǥ �߰�
					path.push({next_x, next_y});
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// ���ӵ� ���ڿ� ���ؼ� 1������ �Է� �޵��� ��
            // ex) 00110 -> 0, 0, 1, 1, 0
			scanf("%1d",&map[i][j]);
		}
	}

	bfs(0, 0);	// bfs �Լ� ȣ��

	cout << map[N - 1][M - 1] << endl;
}