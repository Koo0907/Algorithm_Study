#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int Tc = 0;
int N = 0;
int dif = 0;
vector<int> len;
vector<int> res;

int main()
{
	cin >> Tc;

	for(int i = 0; i < Tc; i++)
	{
		cin >> N;

		for(int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			len.push_back(num);
		}

		// �볪�� ���� �������� ����
		sort(len.begin(), len.end());

		// j��° �볪���� ���̿� j+2��° �볪���� ������ ���� ���� ���ϰ� �� ���� �ִ밪�� ������
		for(int j = 0; j < (len.size() - 2); j++)
		{
			dif = max(dif, abs(len[j] - len[j + 2]));
		}

		res.push_back(dif);
		
		// vector �� ����� �ʱ�ȭ
		len.clear();
		dif = 0;
	}

	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
}