#include<iostream>
#include<queue>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int N = 0;
int M = 0;
int res = 0;
bool already = true;
int map[1000][1000];
queue<pair<int, int>> path;

// map�� 0(���� ���� �丶��)�� �ִ��� Ȯ���ϴ� �Լ�
bool check()
{
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] == 0)
			{
				return true;
			}
		}
	}

	return false;
}

void bfs()
{
	while(!path.empty())
	{
		// ���� queue�� ����ִ� ��ǥ �����ϰ� ����
		int x = path.front().first;
		int y = path.front().second;
		path.pop();

		for(int i = 0; i < 4; i++)
		{
			// ���⺤�� ����ؼ� ���� ��ǥ ����
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ���� map �ȿ� ������ �Ʒ� ���� ����
			if((next_x >= 0) && (next_x < M) && (next_y >= 0) && (next_y < N))
			{
				// ���� ��ǥ�� �丶�䰡 ���� �ʾҴٸ� �Ʒ� ���� ����
				if(map[next_x][next_y] == 0)
				{
					// ���� ��ǥ�� ������ ���� ��ǥ �� +1�� ����
					// 0�� �ƴ� �ڿ����� ��� ���� �丶���� �Ǵ�
					// �ش� ��ǥ�� ���� ���� �丶�䰡 �ͱ���� �ɸ� ��¥�� 1�� ���� ����
					map[next_x][next_y] = map[x][y] + 1;

					// queue�� ���� ��ǥ �߰�
					path.push({next_x, next_y});

					// �ѹ��̶� ���� ���� �丶�䰡 �;��ٸ�, flag clear
					already = false;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// �ʱ� map���� ���� �丶���� ��ǥ�� queue�� �̸� �߰�
			if(map[i][j] == 1)
			{
				path.push({i, j});
			}
		}
	}

	// bfs �Լ� ȣ��
	bfs();

	// map �� ���� 0(���� ���� �丶��)�� �ִٸ� ������� -1
	if(check())
	{
		res = -1;
	}
	// �ѹ��� ���� ���� �丶�䰡 ������ ���� �丶��� ���ؼ� ���� ���� ���ٸ� ������� 0
	else if(already)
	{
		res = 0;
	}
	// �� �̿��� ��쿡 ������� map ���� ���� �� �߿� �ִ밪���� 1�� ���� ��
	else
	{
		for(int i = 0; i < M; i++)
		{
			for(int j = 0; j < N; j++)
			{
				if(map[i][j] > res)
				{
					res = map[i][j] - 1;
				}
			}
		}
	}

	cout << res << endl;
}