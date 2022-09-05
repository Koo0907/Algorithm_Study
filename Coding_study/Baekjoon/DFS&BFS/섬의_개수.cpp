#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 50

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

// ����� ���� �ʱ�ȭ
int w = 0;
int h = 0;
int cnt = 0;

// ���� �迭
int map[MAX][MAX];

// BFS ���� �Լ�
void bfs(int a, int b)
{
	// ť ����
	queue<pair<int, int>> q;

	// �Ķ���� ��ǥ ť�� �߰�
	q.push({a, b});

	// �Ķ���� ��ǥ �湮 ó��
	// �� �󿡼��� 0,1�θ� ���еǱ� ������ 2�� �湮�ߴٴ� �ǹ�
	map[a][b] = 2;

	// ť�� �� ������ �ݺ�
	while(!q.empty())
	{
		// ť���� ��ǥ ���� �� ����
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// �밢�� ���� �����ؼ� �������� ��� ��ȸ
		for(int i = 0; i < 8; i++)
		{
			// ���� ��ǥ ���
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			// ���� ��ǥ�� �� �ȿ� �ִٸ� �Ʒ� ���� ����
			if((next_x >= 0) && (next_x < h) && (next_y >= 0) && (next_y < w))
			{
				// ���� ��ǥ�� ���̶�� �Ʒ� ���� ����
				if(map[next_x][next_y] == 1)
				{
					// ���� ��ǥ ť�� �߰�
					q.push({next_x, next_y});

					// ���� ��ǥ �湮 ó��
					map[next_x][next_y] = 2;
				}
			}
		}
	}
}

int main()
{
	while(1)
	{
		scanf("%d %d",&w, &h);
		
		// w�� h�� ��� 0�� �ԷµǸ� �ݺ��� ����
		if((w == 0) && (h == 0))
		{
			break;
		}

		// ���� ������ �Է�
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				scanf("%d",&map[i][j]);
			}
		}

		// ���� ������ ��ȸ
		for(int i = 0; i < h; i++)
		{
			for(int j = 0; j < w; j++)
			{
				// ��ǥ�� ���� ��� �Ʒ� ���� ����
				if(map[i][j] == 1)
				{
					// BFS �Լ� ����
					bfs(i, j);

					// ���� ���� ����
					cnt++;
				}
			}
		}

		// ���� ���� ���
		cout << cnt << endl;

		// ���� ���� �ʱ�ȭ
		cnt = 0;
	}
}