#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
int max_val = 0;
long long total_com = 0;
int ans = 0;
int map[1001][1001];

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			total_com += map[i][j];	// ��ǻ���� ���� �Է¹��������� �ջ��Ͽ� ��� ��ǻ�� ���� ���
			max_val = max(max_val, map[i][j]);	// ���� ��ǻ�� ���� ���� ���� �Ǵ�
		}
	}

	// �ּ� �ð��� 0��
	long long start = 0;

	// �ִ� �ð��� ��ǻ�Ͱ� ���� ���� ������ ��ǻ�� ��
	long long end = max_val;

	// ��ü ��ǻ���� 50%�� �������� ����
	double criteria = total_com / 2.0;

	while(start <= end)
	{
		long long sum = 0;

		// �ҿ� �ð��� �̺� Ž������ ����
		long long mid = (start + end) / 2;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// ���� ��ȸ���� ������ ��ǻ�� ���� ������ �ð����� ũ�ٸ� �������� �ջ�
				if(map[i][j] > mid)
				{
					sum += mid;
				}
				// ���� ��ȸ���� ������ ��ǻ�� ���� ������ �ð����� �۴ٸ� ��ǻ�� ���� �ջ�
				else
				{
					sum += map[i][j];
				}
			}
		}

		// �������� ���� ���� ���ذ�(��ü ��ǻ���� 50%)���� �۴ٸ� �ҿ� �ð��� �ʹ� ª�� �����ߴٴ� ���̹Ƿ� ������ ������Ŵ
		if(sum < criteria)
		{
			start = mid + 1;
		}
		// �������� ���� ���� ���ذ�(��ü ��ǻ���� 50%) �̻��̶�� ���� ������ �ð��� �����ϰ� �ҿ� �ð��� �ٿ��� Ȯ���غ��� �ϹǷ� ������ ���ҽ�Ŵ
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans << endl;
}