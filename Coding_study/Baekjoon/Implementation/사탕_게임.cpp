#include<iostream>
#include<vector>

using namespace std;

// ��,��,��,�쿡 ���� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N = 0;
int max_val = 0;
char map[50][50];

// ��� �� ������ ��ȸ�ϸ� ���ڷ� ���� ���ڰ� �������� �ִ� ��� �ִ��� Ȯ���ϸ� �ִ밪 �����ϴ� �Լ�
void check_max(char find)
{
	int temp_max_val = 0;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// �� ���� ��ȸ
			if(map[i][j] == find)
			{
				temp_max_val++;
			}
			else
			{
				// ���ڿ� �ٸ� ���ڰ� ���´ٸ� ������� count�� temp_max_val�� ��������� �ִ밪�� max_val �� �� ����
				max_val = max(max_val, temp_max_val);
				temp_max_val = 0;
			}
		}
		// �� �࿡ ��� ���� ���ڿ� ���� ������ ��츦 ����Ͽ� �� ���� ��ȸ�� ������ �ִ밪 �� �� ����
		max_val = max(max_val, temp_max_val);
		temp_max_val = 0;
	}

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// �� ���� ��ȸ
			if(map[j][i] == find)
			{
				temp_max_val++;
			}
			else
			{
				// ���ڿ� �ٸ� ���ڰ� ���´ٸ� ������� count�� temp_max_val�� ��������� �ִ밪�� max_val �� �� ����
				max_val = max(max_val, temp_max_val);
				temp_max_val = 0;
			}
		}
		// �� �࿡ ��� ���� ���ڿ� ���� ������ ��츦 ����Ͽ� �� ���� ��ȸ�� ������ �ִ밪 �� �� ����
		max_val = max(max_val, temp_max_val);
		temp_max_val = 0;
	}
}

// swap �Լ�
void map_swap(int x, int y, int next_x, int next_y)
{
	char temp;

	temp = map[x][y];
	map[x][y] = map[next_x][next_y];
	map[next_x][next_y] = temp;
}

void change_color(int x, int y)
{
	for(int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		// ���� ��ġ�� �� ���ζ�� �Ʒ� ���� ����
		if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
		{
			// ���� ��ġ�� ���ڿ� ���� ��ġ�� ���ڰ� ���ٸ� swap�����ʰ� ���� ��ġ Ž��
			if(map[x][y] == map[next_x][next_y])
			{
				continue;
			}

			// ���� ��ġ�� ���ڿ� ��ȸ�� ���� ��ġ�� ���� swap
			map_swap(x, y, next_x, next_y);

			// ������ ���ڿ� ���ؼ� �ִ밪 Ž��
			check_max('C');
			check_max('P');
			check_max('Z');
			check_max('Y');

			// swap��Ų map ����
			map_swap(x, y, next_x, next_y);

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

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			// ��� ��ġ���� ����Ž��
			change_color(i, j);
		}
	}

	cout << max_val << endl;
}