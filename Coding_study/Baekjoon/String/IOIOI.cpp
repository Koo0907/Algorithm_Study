#include<iostream>
#include<string>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int cnt = 0;

int main()
{
	string str;
	
	scanf("%d", &N);

	scanf("%d", &M);

	cin >> str;

	for(int i = 0; i < M; i++)
	{
		int pattern = 0;

		// ��ȸ�ϴ� ���ڰ� 'O'�̸� ���ȸ
		if(str[i] == 'O')
		{
			continue;
		}

		// ��ȸ�ϴ� ���ڰ� 'I'�̰� ���� �� ���ڰ� "OI"�̸� �ݺ�
		while((str[i + 1] == 'O') && (str[i + 2] == 'I'))
		{
			// "IOI" ���� ����
			pattern++;

			// "IOI" ������ N�� ���ٸ� �Ʒ� ���� ����
			if(pattern == N)
			{
				// cnt ����
				cnt++;

				// ���� �� ����
				pattern--;
			}

			// �� index�� ���ÿ� Ȯ�������Ƿ� +2 ����
			i += 2;
		}

		// ������ �� �̻� ���ٸ� �ʱ�ȭ
		pattern = 0;
	}

	cout << cnt << endl;
}