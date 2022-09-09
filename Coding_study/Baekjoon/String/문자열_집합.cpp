#include<iostream>
#include<string>
#include<set>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int cnt = 0;
string str;

// set STL 사용
set<string> s;

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
	{
		cin >> str;

		// set에 문자열 추가
		s.insert(str);
	}

	for(int i = 0; i < M; i++)
	{
		cin >> str;

		// set 트리에 str이 존재한다면 cnt 증가
		if(s.find(str) != s.end())
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}