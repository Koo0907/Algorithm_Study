#include<iostream>
#include<cstring>

#define LEN 26

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int cnt = 0;
int ans = 0;
string str;
string cmp_str;

int alphabet[LEN];
int temp[LEN];

int main()
{
	cin >> N >> str;

	// ���� ���ڿ��� ö�� �� ����
	for(int i = 0; i < str.size(); i++)
	{
		alphabet[str[i] - 'A']++;
	}

	for(int i = 0; i < N - 1; i++)
	{
		// temp �迭�� alphabet �迭 ����
		memcpy(temp, alphabet, sizeof(alphabet));

		// �� ���ڿ� �Է�
		cin >> cmp_str;

		// cnt ���� �ʱ�ȭ
		cnt = 0;

		// �� ���ڿ��� ���� ��ŭ ��ȸ
		for(int j = 0; j < cmp_str.size(); j++)
		{
			// �� ���ڿ��� ö�ڰ� ���� ���ڿ������� �����ߴ��� Ȯ��
			if(temp[cmp_str[j] - 'A'] > 0)
			{
				// ���� ���ڿ� ö�� �迭���� �ش� ���� �����ϰ� cnt ����
				temp[cmp_str[j] - 'A']--;
				cnt++;
			}
		}

		// ���� ���ڿ��� �� ���ڿ��� ���̰� ����, �� ���ڿ��� ö�ڿ� ���� ���ڿ��� ö�ڰ� �����ϰų�, �� ���ڿ��� �ϳ��� �ٸ� ��쿡�� ����� �ܾ�� �Ǵ�
		if((str.size() == cmp_str.size()) && ((cnt == cmp_str.size()) || (cnt == cmp_str.size() - 1)))
		{
			ans++;
		}
		// ���� ���ڿ��� ���̰� �� ���ڿ��� ���̺��� 1 �۰�, ���� ���ڿ��� ö�ڰ� �� ���ڿ��� ��� ���ԵǾ� �ִ� ��쿡�� ����� �ܾ�� �Ǵ�
		else if((str.size() == cmp_str.size() - 1) && (cnt == str.size()))
		{
			ans++;
		}
		// ���� ���ڿ��� ���̰� �� ���ڿ��� ���̺��� 1 ũ��, �� ���ڿ��� ö�ڰ� ���� ���ڿ��� ��� ���ԵǾ� �ִ� ��쿡�� ����� �ܾ�� �Ǵ�
		else if((str.size() == cmp_str.size() + 1) && (cnt == cmp_str.size()))
		{
			ans++;
		}
	}

	// ����� �ܾ� �� ���
	cout << ans << endl;
}