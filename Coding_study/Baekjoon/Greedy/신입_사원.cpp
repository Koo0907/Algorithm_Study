#include<iostream>
#include<algorithm>

using namespace std;

pair<int, int> Appl[100000];
int pass[21];
int Tc = 0;
int num = 0;

int main()
{
	cin >> Tc;

	for (int i = 0; i < Tc; i++)
	{
		cin >> num;

		for (int j = 0; j < num; j++)
		{
			cin >> Appl[j].first >> Appl[j].second;
		}

		// first ������ �������� �������� ����
		sort(Appl, Appl + num);

		int score = Appl[0].second;
		int cnt = 0;
		// �����ڵ��� ������ ��ȸ�ϸ鼭 second�� ������ ���� ������ �ִ� �������� ���ٸ� �հݽ�Ŵ
		for (int j = 0; j < num; j++)
		{
			if (Appl[j].second <= score)
			{
				cnt++;
				score = Appl[j].second;
			}
			pass[i] = cnt;
		}

	}

	for (int i = 0; i < Tc; i++)
	{
		cout << pass[i] << endl;
	}
}