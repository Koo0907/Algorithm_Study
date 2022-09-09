#include<iostream>
#include<string>

using namespace std;

// 사용할 변수 초기화
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

		// 순회하는 문자가 'O'이면 재순회
		if(str[i] == 'O')
		{
			continue;
		}

		// 순회하는 문자가 'I'이고 뒤의 두 문자가 "OI"이면 반복
		while((str[i + 1] == 'O') && (str[i + 2] == 'I'))
		{
			// "IOI" 패턴 증가
			pattern++;

			// "IOI" 패턴이 N과 같다면 아래 로직 수행
			if(pattern == N)
			{
				// cnt 증가
				cnt++;

				// 패턴 수 감소
				pattern--;
			}

			// 두 index를 동시에 확인했으므로 +2 해줌
			i += 2;
		}

		// 패턴이 더 이상 없다면 초기화
		pattern = 0;
	}

	cout << cnt << endl;
}