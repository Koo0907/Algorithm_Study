#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int N = 0;
int max_high = 0;
int max_val = 0;
int area = 0;
int map[100][100];
int original_map[100][100];
queue<pair<int, int>> path;
vector<int> area_vec;

void bfs(int x, int y)
{
	// ���� ��ǥ �湮 ǥ��
	map[x][y] = 0;

	// ���� ��ǥ queue�� �߰�
	path.push({x,y});

	while(!path.empty())
	{
		// ���� queue�� ����ִ� ��ǥ �����ϰ� ����
		x = path.front().first;
		y = path.front().second;
		path.pop();

		// ���⺤�� ����ؼ� ���� ��ǥ ����
		for(int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ���� map �ȿ� ������ �Ʒ� ���� ����
			if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
			{
				// ���� ��ǥ���� ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
				if(map[next_x][next_y] != 0)
				{
					// ���� ��ǥ �湮 ǥ��
					map[next_x][next_y] = 0;

					// queue�� ���� ��ǥ �߰�
					path.push({next_x, next_y});
				}
			}
		}
	}
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);

			// map ���� �Է¹����鼭 ���� ���� ������ ���� ���ص�
			if(map[i][j] > max_high)
			{
				max_high = map[i][j];
			}
		}
	}

	// ������ų ������ map�� �߰��Ͽ� ����
	memcpy(original_map, map, sizeof(map));

	// 0���� ���� ���� ���̱��� �������� �����Ͽ� ��ȸ
	for(int tc = 0; tc <= max_high; tc++)
	{
		// ���� ���� ������ Ȯ���ϱ� ��, ������ map���� ����
		memcpy(map, original_map, sizeof(original_map));

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// ������ ���������� ���� ������ ������ ���� ���Ƿ� ���� 0���� ����
				if(map[i][j] <= tc)
				{
					map[i][j] = 0;
				}
			}
		}

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// ������ ���� 0�� �ƴ� ��쿡�� bfs �Լ� ȣ��
				if(map[i][j] != 0)
				{
					bfs(i, j);
					area++;	// �� ���� ������ ��ȸ�� ������ ���� ���� �� cnt ����
				}
			}
		}

		// ���� ���� ���� ��� vector�� �� �߰�
		area_vec.push_back(area);

		// ���� ���� �� �ʱ�ȭ
		area = 0;
	}
	
	// ���� ���� ���� ���� vector���� �ִ밪 ����
	area = *max_element(area_vec.begin(), area_vec.end());

	cout << area << endl;
}