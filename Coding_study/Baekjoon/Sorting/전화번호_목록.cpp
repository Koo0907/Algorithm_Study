#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int Tc = 0;
int N = 0;
bool ans_flag = true;
vector<string> phone_book;
vector<bool> res;

int main()
{
	scanf("%d",&Tc);

	for(int i = 0; i < Tc; i++)
	{
		scanf("%d",&N);

		for(int j = 0; j < N; j++)
		{
			string phone_num;
			cin >> phone_num;
			phone_book.push_back(phone_num);
		}

		// ��ȭ��ȣ�� �������� ����
		sort(phone_book.begin(),phone_book.end());

		for(int j = 0; j < (phone_book.size()- 1) ; j++)
		{
			// j��° ��ȭ��ȣ�� ���̰� j+1��° ��ȭ��ȣ�� ���̺��� ��ٸ� prefix�� �� �� �����Ƿ� continue
			if(phone_book[j].size() > phone_book[j + 1].size())
			{
				continue;
			}

			// j��° ��ȭ��ȣ�� j+1��° ��ȭ��ȣ�� prefix��� �ϰ����� ���ٴ� �ǹ�
			if(phone_book[j] == phone_book[j + 1].substr(0, phone_book[j].size()))
			{
				// flag ����
				ans_flag = false;
				break;
			}
		}

		// ��� ���Ϳ� flag�� �߰�
		res.push_back(ans_flag);

		// ���� �� flag �ʱ�ȭ
		phone_book.clear();
		ans_flag = true;
	}

	for(int i = 0; i < res.size(); i++)
	{
		if(res[i])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}