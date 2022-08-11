#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int M = 0;
int N = 0;
int K = 0;
int cnt = 0;
int map[100][100];
vector<int> area;

void dfs(int x, int y)
{
	// �湮 ó��
	map[x][y] = 1;

	// ���� cnt ����
	cnt++;

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < M) && (next_y >= 0) && (next_y < N))
		{
			// ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if(map[next_x][next_y] == 0)
			{
				// dfs �Լ� ����
				dfs(next_x, next_y);
			}
		}
	}

}

int main()
{
	cin >> M >> N >> K;

	for(int i = 0; i < K; i++)
	{
		int x1 = 0;
		int y1 = 0;
		int x2 = 0;
		int y2 = 0;

		// ���� �󿡼��� ��ǥ �� �Է�
		cin >> x1 >> y1 >> x2 >> y2;

		// 2���� �迭������ ��ǥ������ ȯ��
		int mx1 = M - y1 - 1;
		int my1 = x1;
		int mx2 = M - y2;
		int my2 = x2 - 1;

		// ȯ���� ��ǥ������ �̿��ؼ� �̸� �湮 ó��(���̸� ������ �ʵ���)
		for(int j = mx2; j <= mx1; j++)
		{
			for(int k = my1; k <= my2; k++)
			{
				map[j][k] = 1;
			}
		}
	}

	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if(map[i][j] == 0)
			{
				// dfs �Լ� ȣ��
				dfs(i, j);

				// ���� ���� ���� ���Ϳ� �߰�
				area.push_back(cnt);

				// ���� �� �ʱ�ȭ
				cnt = 0;
			}
		}
	}

	// ������������ ����
	sort(area.begin(), area.end());

	cout << area.size() << endl;

	for(int i = 0; i < area.size(); i++)
	{
		cout << area[i] << " ";
	}
}