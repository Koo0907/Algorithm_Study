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

		// first 순위를 기준으로 오름차순 정렬
		sort(Appl, Appl + num);

		int score = Appl[0].second;
		int cnt = 0;
		// 지원자들의 순위를 순회하면서 second의 순위가 현재 저장한 최대 순위보다 낮다면 합격시킴
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