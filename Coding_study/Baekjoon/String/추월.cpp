#include<iostream>
#include<string>
#include<map>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int cnt = 0;
string car;

// �ͳο� �� ���� ���� Ȯ���� ���� ��
map<string, int> m;

// �ͳο��� ���ö��� ���� Ȯ���� ���� �迭
int exit_car[1000];

int main()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		cin >> car;

		// �� ��ȣ�� key������ ���� ���� i�� �߰�
		m[car] = i;
	}

	for(int i = 0; i < N; i++)
	{
		cin >> car;
		
		// �ͳο��� ���� ���� �� �� ���° ������������ �迭�� ������ ������ ��
		exit_car[i] = m[car];

	}

	for(int i = 0; i < N; i++)
	{
		for(int j = (i + 1); j < N; j++)
		{
			// i��°�� �ͳο��� ���� ���� �ͳο��� ���� �� ������ ���� ���Դٸ� �߿��� �ߴٴ� ��
			if(exit_car[i] > exit_car[j])
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;
}