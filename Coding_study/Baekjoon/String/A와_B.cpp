#include<iostream>
#include<string>

using namespace std;

// ����� ���� �ʱ�ȭ
string S;
string T;
int S_len = 0;
int T_len = 0;
int ans = 0;

// �Ķ���� ���ڿ��� ������ �Լ�
string reverse_string(string str)
{
	// �ӽ� ���ڿ� ����
	string temp;

	// ���ڿ��� index�� �ݴ�� �����Ͽ� temp�� append
	for(int i = (str.size() - 1); i >= 0; i--)
	{
		temp += str[i];
	}

	return temp;
}

int main()
{
	cin >> S >> T;

	while(1)
	{
		// �� ���ڿ����� ���̸� ����
		S_len = S.size();
		T_len = T.size();

		// �� ���ڿ��� ���̰� ������ �Ʒ� ���� ����
		if(S_len == T_len)
		{
			// �� ���ڿ��� ���� ���ٸ� �Ʒ� ���� ����
			if(S == T)
			{
				// ���� ����
				ans = 1;
			}
			
			break;
		}

		// T ���ڿ��� ������ ���ڰ� 'A'�̸� �ܼ��� �����ֱ⸸ ��
		if(T[T_len - 1] == 'A')
		{
			T.pop_back();
		}
		// T ���ڿ��� ������ ���ڰ� 'B'�̸� ���ڸ� �����ְ� ������
		else
		{
			T.pop_back();
			T = reverse_string(T);
		}
	}
	
	cout << ans << endl;
}