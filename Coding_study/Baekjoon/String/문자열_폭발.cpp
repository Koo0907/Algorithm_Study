#include<iostream>
#include<string>

using namespace std;

// ����� ���� �ʱ�ȭ
string str;
string bomb;
string ans;

int main()
{
	cin >> str >> bomb;

	// �־����� string�� ���̸�ŭ ��ȸ
	for(int i = 0; i < str.length(); i++)
	{
		// ans string�� �־����� string�� �� ����
		ans += str[i];

		// ans�� ���̰� ��ź ���ڿ��� ���� �̻��� �Ǵ� �������� üũ
		if(ans.size() >= bomb.size())
		{
			// ��ȸ���� �ڸ��� ���ڰ� ��ź ���ڿ��� ������ ���ڿ� ���ٸ� �Ʒ� ���� ����
			if(ans[ans.size() - 1] == bomb[bomb.size() - 1])
			{
				// ���� flag set
				bool explode = true;

				// ��ź ���ڿ��� ���̸�ŭ ��ȸ
				for(int j = 0; j < bomb.size(); j++)
				{
					// ans string���� ��ź ���ڿ� ���� ��ŭ ������ ��ź ���ڿ��� �ִ��� Ȯ��
					// ��ź ���ڿ��� �ٸ� ���ڰ� �ִٸ� �Ʒ� ���� ����
					if(ans[ans.size() - bomb.size() + j] != bomb[j])
					{
						// ���� flag clear
						explode = false;
						break;
					}
				}

				// ���� flag�� set�Ǿ� �ִٸ� ��ź���ڿ��� erase
				if(explode)
				{
					ans.erase(ans.size() - bomb.size());
				}
			}
		}
	}

	// ans string�� ���̰� 0�̶�� ��� �����ߴٴ� �ǹ̷� "FRULA" ���
	if(ans.size() == 0)
	{
		cout << "FRULA" << endl;
	}
	else
	{
		cout << ans << endl;
	}
}