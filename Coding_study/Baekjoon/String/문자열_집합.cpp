#include<iostream>
#include<string>
#include<set>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int cnt = 0;
string str;

// set STL ���
set<string> s;

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		cin >> str;

		// set�� ���ڿ� �߰�
		s.insert(str);
	}

	for(int i = 0; i < M; i++)
	{
		cin >> str;

		// set Ʈ���� str�� �����Ѵٸ� cnt ����
		if(s.find(str) != s.end())
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}