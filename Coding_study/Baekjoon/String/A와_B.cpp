#include<iostream>
#include<string>

using namespace std;

// 사용할 변수 초기화
string S;
string T;
int S_len = 0;
int T_len = 0;
int ans = 0;

// 파라미터 문자열을 뒤집는 함수
string reverse_string(string str)
{
	// 임시 문자열 변수
	string temp;

	// 문자열의 index를 반대로 참조하여 temp에 append
	for(int i = (str.size() - 1); i >= 0; i--)
	{
		temp += str[i];
	}

	return temp;
}

int main()
{
	cin >> S >> T;

	while(1)
	{
		// 각 문자열들의 길이를 구함
		S_len = S.size();
		T_len = T.size();

		// 각 문자열의 길이가 같으면 아래 로직 수행
		if(S_len == T_len)
		{
			// 각 문자열이 서로 같다면 아래 로직 수행
			if(S == T)
			{
				// 정답 갱신
				ans = 1;
			}
			
			break;
		}

		// T 문자열의 마지막 문자가 'A'이면 단순히 없애주기만 함
		if(T[T_len - 1] == 'A')
		{
			T.pop_back();
		}
		// T 문자열의 마지막 문자가 'B'이면 문자를 없애주고 뒤집음
		else
		{
			T.pop_back();
			T = reverse_string(T);
		}
	}
	
	cout << ans << endl;
}