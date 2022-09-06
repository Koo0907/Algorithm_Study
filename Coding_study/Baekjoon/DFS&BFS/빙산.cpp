#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 300

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int year = 0;
bool success = false;

// �湮 ó���� ���� �迭
bool visited[MAX][MAX];

// ���� ��
int ice[MAX][MAX];

// ������ ��� �� ���� ���� ��
int next_ice[MAX][MAX];

// DFS �Լ� ȣ��
void dfs(int a, int b)
{
	// �Ķ���� ��ǥ �� �湮 ó��
	visited[a][b] = true;

	// ��,��,��,�� �� ���� ��ȸ
	for(int i = 0; i < 4; i++)
	{
		int x = a + dx[i];
		int y = b + dy[i];

		// ���� ��ǥ�� �� �� �ִ��� Ȯ��
		if((x >= 0) && (x < N) && (y >= 0) && (y < M))
		{
			// ���� ��ǥ�� ������ 0�� �ƴϰ� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if((ice[x][y] != 0) && (visited[x][y] == false))
			{
				// DFS �Լ� ȣ��
				dfs(x, y);
			}
		}
	}
}

// ������ �� ���� �̻����� �и��Ǿ����� üũ�ϴ� �Լ�
bool ice_check(void)
{
	// �湮 ó�� �迭 �ʱ�ȭ
	memset(visited, 0, sizeof(visited));

	// ���� �� �ʱ�ȭ
	int ice_cnt = 0;

	// ���� �� ��ȸ
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// ��ȸ�ϴ� ������ 0�� �ƴϰ� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if((ice[i][j] != 0) && (visited[i][j] == false))
			{
				// DFS �Լ� ȣ��
				dfs(i, j);

				// ���� ����
				ice_cnt++;
			}
		}
	}

	// �� ���� �̻��� ��� �Ʒ� ���� ����
	if(ice_cnt >= 2)
	{
		// �� ���� �̻����� �и��Ǿ��ٴ� ���� success flag set
		success = true;
		return true;
	}
	else
	{
		return false;
	}

}

// 1�� ���� ���� �� ���ϴ� �Լ�
void ice_melting(void)
{
	// �湮 ó�� �迭 �ʱ�ȭ
	memset(visited, 0, sizeof(visited));

	// ���� �� ��ȸ
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// ��ȸ�ϴ� ������ 0�� �ƴϰ� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if((ice[i][j] != 0) && (visited[i][j] == false))
			{
				// ��,��,��,�� ��ȸ�ϸ� 0�� �ִ� ���� Ž��
				int zero_cnt = 0;
				for(int k = 0; k < 4; k++)
				{
					int x = i + dx[k];
					int y = j + dy[k];

					// ������ �� �� �ִ��� Ȯ��
					if((x >= 0) && (x < N) && (y >= 0) && (y < M))
					{
						// ��ȸ�ϴ� ������ 0�� ��� �Ʒ� ���� ����
						if(ice[x][y] == 0)
						{
							// zero_cnt ����
							zero_cnt++;
						}
					}
				}

				// zero_cnt�� ������ ���̺��� ���ٸ� �Ʒ� ���� ����
				if(zero_cnt > ice[i][j])
				{
					// ���� ���� �ʿ� 0���� ����
					next_ice[i][j] = 0;
				}
				// zero_cnt�� ������ ���̺��� ���ų� ���ٸ� �Ʒ� ���� ����
				else
				{
					// ���� ���� �ʿ� ���� ���� �� - zero_cnt ����
					next_ice[i][j] = ice[i][j] - zero_cnt;
				}

				// ���� ��ǥ �湮 ó��
				visited[i][j] = true;
			}
		}
	}

	// 1�� ����
	year++;

	// ���� ���� ���� �����͸� ���� ���� ������ ����
	memcpy(ice, next_ice, sizeof(ice));
}

// ������ ��� ��Ҵ��� Ȯ���ϴ� �Լ�
bool all_melt(void)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			// ���� �������� ������ �ִٸ� �Ʒ� ���� ����
			if(ice[i][j] != 0)
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	// ���� ���� �ʰ� ���� ���� �� �ʱ�ȭ
	memset(ice, 0, sizeof(ice));
	memset(next_ice, 0, sizeof(next_ice));

	scanf("%d %d",&N, &M);

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			scanf("%d", &ice[i][j]);
		}
	}

	while(1)
	{
		// 1�� ���� ���� �� ���ϱ�
		ice_melting();

		// ������� �� ���̷� �������� �ִٸ� �ݺ��� Ż��
		if(ice_check())
		{
			break;
		}

		// ������� ��� ��Ҵٸ� �ݺ��� Ż��
		if(all_melt())
		{
			break;
		}
	}

	// ������ �� ���̷� ������������ ������ ���� ��� ���
	if(success)
	{
		cout << year << endl;
	}
	else
	{
		cout << 0 << endl;
	}
}