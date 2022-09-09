#include<iostream>
#include<string>

#define LEN 26

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int cnt = 0;
bool not_count = false;

// ���ĺ��� ���ݱ��� ��Ÿ������ �����ִ� �迭
bool alpabet[26];

// �迭 �� falg �ʱ�ȭ
void clear(void)
{
	for(int i = 0; i < LEN; i++)
	{
		alpabet[i] = false;
	}

	not_count = false;
}

int main()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		string word;

		// �迭 �� flag �ʱ�ȭ
		clear();

		cin >> word;
		
		// �ܾ� ���̸�ŭ ��ȸ
		for(int j = 0; j < word.length(); j++)
		{
			// ���ĺ��� 'a'�� ���� �ƽ�Ű ���� ����
			int now = word[j] - 'a';

			// ���� ��Ÿ���� ���� ���ĺ��̶�� true ���� �� �Ѿ
			if(alpabet[now] == false)
			{
				alpabet[now] = true;
			}
			// �̹� ��Ÿ�� ���ĺ��̶�� �Ʒ� ���� ����
			else
			{
				// ������ ��Ÿ�� ���ĺ��� �ƴ϶�� not_count flag ����
				if(word[j - 1] != word[j])
				{
					not_count = true;
					break;
				}
			}
		}

		// not_count flag�� false�� ��쿡�� cnt ����
		if(not_count == false)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}