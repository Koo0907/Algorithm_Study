#include<iostream>
#include<string>

using namespace std;

// ����� ���� �ʱ�ȭ
int T = 0;
string str;

// ȸ�� Ȯ���ϴ� �Լ�
int check_palline(int start, int end, bool except)
{
	// start index�� end index���� �۴ٸ� �ݺ� ����
	while(start <= end)
	{
		// �� ���ڰ� �ٸ��ٸ� ȸ���� �ƴ� ���̹Ƿ� �Ʒ� ���� ����
		if(str[start] != str[end])
		{
			// ���� ���� �ϳ��� ����� Ȯ���غ��� �ʾҴٸ� �Ʒ� ���� ����
			if(except == false)
			{
				// ���ڰ� Ʋ�ȴ� �� index �߿� start index�� ���ڳ� end index�� ���ڸ� ���� ���ܽ�Ű�� ȸ������ Ȯ��
				if((check_palline(start, end-1, true) == 0) || (check_palline(start + 1, end, true) == 0))
				{
					// ���ڸ� ���ܽ�Ű�� ȸ���̶�� ���� ȸ�� ��ȯ
					return 1;
				}
				else
				{
					// ���ڸ� ���ܽ�Ű�� ȸ���� �ƴ϶�� ��ȸ�� ��ȯ
					return 2;
				}
			}
			// �̹� ���ڸ� ������ Ȯ���غôٸ� ��ȸ�� ��ȯ
			else
			{
				return 2;
			}
		}
		// �� ���ڰ� ���ٸ� index ���� �� �ݺ��ؼ� Ȯ��
		else
		{
			start++;
			end--;
		}
	}

	// ȸ�� ��ȯ
	return 0;
}

int main()
{
	scanf("%d", &T);

	for(int Tc = 0; Tc < T; Tc++)
	{
		cin >> str;

		// �Էµ� ���ڿ��� ���ؼ� ȸ�� Ȯ�� �� ��ȯ�� ���
		cout << check_palline(0, str.size() - 1, false) << endl;;
	}
}