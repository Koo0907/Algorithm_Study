#include<iostream>
#include<string>
#include<map>

using namespace std;

// ����� ���� �ʱ�ȭ
string str;
int P_cnt = 0;

int main()
{
	cin >> str;

	// ���ڿ� ��ü ��ȸ
	for(int i = 0; i < str.size(); i++)
	{
		// P�� ������ P�� ������ P_cnt �����ϰ� continue
		if(str[i] == 'P')
		{
			P_cnt++;
			continue;
		}

		// A�� ������ ���ݱ��� P�� 2�� �̻� �������� ������ ���� ���ڰ� P���� Ȯ��
		// �׷��� ���� ���ڱ��� �����ؼ� "PPAP"�� �ϼ���
		if((P_cnt >= 2) && (str[i + 1] == 'P'))
		{
			// "PPAP"�� P�� ġȯ�� ���̹Ƿ� P_cnt�� 1 ����
			P_cnt--;

			// ���� ������ P���� Ȯ�������Ƿ� i�� 1 ����
			i++;
		}
		// A�� ���Դµ� P�� ���� 2�� ������ �ʰų� ���� ���ڰ� P�� �ƴ϶�� PPAP ���ڿ��� �ƴ�
		else
		{
			cout << "NP" << endl;
			return 0;
		}
	}

	// ��ȸ�� �� �ϰ� P�� �����ٸ� PPAP ���ڿ���
	if(P_cnt == 1)
	{
		cout << "PPAP" << endl;
	}
	else
	{
		cout << "NP" << endl;
	}
}