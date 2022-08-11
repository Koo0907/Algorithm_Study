#include<iostream>
#include<cstring>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ����� ������ �ʱ�ȭ
int R = 0;
int C = 0;
int max_val = 0;
char map[20][20];
bool check[26];	// ���ĺ� �湮 ���� Ȯ��

void dfs(int x, int y, int path)
{
	// ���� ����(���� �̵��� ĭ ��)�� �ִ밪�� �� �� ����
	max_val = max(max_val, path);

	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
		{
			// ���� ������ ���ĺ��� ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
			if(check[map[next_x][next_y] - 'A'] == false)
			{
				// ���� ������ ���ĺ� �湮 ó��
				check[map[next_x][next_y] - 'A'] = true;

				// ���̸� �������� dfs �Լ� ȣ��
				dfs(next_x, next_y, path + 1);

				// �湮ó���ߴ� ���ĺ� ����
				check[map[next_x][next_y] - 'A'] = false;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for(int i = 0; i < R; i++)
	{
		cin.ignore();	// �Է� ���� ����
		for(int j = 0; j < C; j++)
		{
			scanf("%c",&map[i][j]);
		}
	}

	// �ʱ� ��ġ ������ ���ĺ� �湮 ó��
	check[map[0][0] - 'A'] = true;

	// �ʱ� ��ġ ���� dfs �Լ� ȣ��
	dfs(0, 0, 1);

	cout << max_val << endl;
}