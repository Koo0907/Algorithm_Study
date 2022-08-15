#include<iostream>
#include<vector>
#include<algorithm>

#define off_set 0.5

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
int H = 0;
int res1 = 0;
int res2 = 0;
int res = 0;
int res_cnt = 0;
int min_val = 2e9;
vector<int> bot;
vector<int> top;

int main()
{
	cin >> N >> H;

	for(int i = 0; i < N; i++)
	{
		int len = 0;
		cin >> len;

		if((i % 2) == 0)
		{
			// ���� ���� ����
			bot.push_back(len);
		}
		else
		{
			// ������ ���� ����
			top.push_back(len);
		}
	}

	// �� ���� ����
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());

	for(int i = 1; i <= H; i++)
	{
		// ���� ���� ���Ϳ��� lower_bound �޼��� Ȱ��
		res1 = (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
		res1 = bot.size() - res1;

		// ������ ���� ���Ϳ��� lower_bound �޼��� Ȱ��
		res2 = (upper_bound(top.begin(), top.end(), (H-i)) - top.begin());
		res2 = top.size() - res2;

		// ��ü cnt �ջ�
		res = res1 + res2;

		// ���� cnt�� ������ �����ߴ� �ּҰ��� ���ٸ� ���� �� ����
		if(res == min_val)
		{
			res_cnt++;
		}
		// ���� cnt�� ������ �����ߴ� �ּҰ����� �۴ٸ� �ּҰ� �簻�� �� ���� �� �ʱ�ȭ
		else if(res < min_val)
		{
			min_val = res;
			res_cnt = 1;
		}
		else
		{
			// nothing
		}

		// ���� �ʱ�ȭ
		res1 = 0;
		res2 = 0;
		res = 0;
	}

	cout << min_val << " " << res_cnt << endl;
}