#include<iostream>
#include<cstring>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int N = 0;
int normal_cnt = 0;	// ���ϻ����� �ƴ� ����� ���� ���
int abnormal_cnt = 0;	// ���ϻ����� ����� ���� ���
char map[100][100];	// ���ϻ����� �ƴ� ����� ���� ��
char ano_map[100][100];	// ���ϻ����� ����� ���� ��

// ���ϻ����� �ƴ� ����� ���� ���
void normal_dfs(int x, int y, char color)
{
	// �湮 ǥ��
	map[x][y] = 'X';

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// ���� ��ȸ���� ������ ���� ���ٸ� dfs ȣ��
			if(map[next_x][next_y] == color)
			{
				normal_dfs(next_x, next_y, color);
			}
		}
	}
}

// ���ϻ����� ����� ���� ���
void abnormal_dfs(int x, int y, char color)
{
	// �湮 ǥ��
	ano_map[x][y] = 'X';

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// ���� ��ȸ���� ������ ���� �Ǵ�
			if(color == 'B')
			{
				// ���� ��ȸ���� ������ ���� Blue��� ���� ������ ���� Blue�� ��쿡�� dfs ȣ��
				if(ano_map[next_x][next_y] == color)
				{
					abnormal_dfs(next_x, next_y, color);
				}
			}
			else
			{
				// ���� ��ȸ���� ������ ���� Red�� Green�̶�� ���� ������ ���� Red�� Green�� ��쿡�� dfs ȣ��
				if((ano_map[next_x][next_y] == 'R') || (ano_map[next_x][next_y] == 'G'))
				{
					abnormal_dfs(next_x, next_y, ano_map[next_x][next_y]);
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
		cin.ignore();	// �Է� ���� ����
		for(int j = 0; j < N; j++)
		{
			scanf("%c", &map[i][j]);
		}
	}

	memcpy(ano_map, map, sizeof(map));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(map[i][j] != 'X')
			{
				// ���ϻ����� �ƴ� ����� ���� ���
				normal_dfs(i, j, map[i][j]);

				// ���� Ž���� ������ ������ cnt ����
				normal_cnt++;
			}

			if(ano_map[i][j] != 'X')
			{
				// ���ϻ����� ����� ���� ���
				abnormal_dfs(i, j, ano_map[i][j]);

				// ���� Ž���� ������ ������ cnt ����
				abnormal_cnt++;
			}
		}
	}

	cout << normal_cnt << " " << abnormal_cnt;
}