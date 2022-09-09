#include<iostream>
#include<string>

#define LEN 26

using namespace std;

// ����� ���� �ʱ�ȭ
string str;
string ans;

int alphabet[LEN] = {0};

// ���ڿ��� ���ڵ��� ���� �Լ�
void count_alphabet(void)
{
	for(int i = 0; i < str.size(); i++)
	{
		alphabet[str[i]- 'A']++;
	}
}

// �Ӹ������ ����� ���� �Ұ����� ��츦 �Ǵ��ϴ� �Լ�
bool check_impossble(void)
{
	int error = 0;
	for(int i = 0; i < LEN; i++)
	{
		// ������ ������ Ȧ�� �̻��� �߻��ϸ� �Ʒ� ���� ����
		if((alphabet[i] % 2) == 1)
		{
			// Ȧ�� �̻��� ���ڰ� 2�� ��Ÿ���� �Ӹ������ ����� ���� �Ұ���
			if(error == 1)
			{
				return true;
			}

			// 1ȸ ��Ÿ��
			error++;
		}
	}

	return false;
}

// ���ڿ��� ����� ���ο� ���ڿ��� ����� �Լ�
string reverse_str(string cri)
{
	string temp;

	for(int i = (cri.size() - 1); i >= 0; i--)
	{
		temp += cri[i];
	}

	return temp;
}

int main()
{
	cin >> str;

	// ���� ī��Ʈ
	count_alphabet();

	// �Ӹ������ ���� �� ���ٸ� I'm Sorry ���
	if(check_impossble())
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		string pre_str;
		string post_str;
		char middle_char = '*';

		// ���ڵ� ��ȸ
		for(int i = 0; i < LEN; i++)
		{
			while(alphabet[i] > 0)
			{
				// ������ ���� 2 �̻��̶�� �Ʒ� ���� ����
				if(alphabet[i] > 1)
				{
					// ���� ������ pre_str�� ���� append
					pre_str += 'A' + i;

					// ���� ���ݿ��� ���Ŀ� ���� �����̹Ƿ� -2 ����
					alphabet[i] -= 2;
				}
				// ������ ���� 1�̶�� �Ӹ������ ��� ���ڷ� Ȯ��
				else if(alphabet[i] == 1)
				{
					middle_char = 'A' + i;
					break;
				}
				else
				{
					// do nothing...
				}
			}
		}

		// ���� ������ pre_str�� �̿��Ͽ� ���� ������ post_str ����
		post_str = reverse_str(pre_str);

		// ��� ���ڰ� ���ŵ��� ���� �ʱⰪ�̶�� ��� ���ڰ� �����Ƿ� pre_str�� post_str�� append
		if(middle_char == '*')
		{
			ans = pre_str + post_str;
		}
		// ��� ���ڰ� ���ŵǾ��ٸ� ��� ���ڰ� �����Ƿ� pre_str�� middle_char�� post_str append
		else
		{
			ans = pre_str + middle_char + post_str;
		}
	}

	// �Ӹ���� ���
	cout << ans << endl;
}