#include<iostream>
#include<string>

#define LEN 26

using namespace std;

// 사용할 변수 초기화
string str;
string ans;

int alphabet[LEN] = {0};

// 문자열의 문자들을 세는 함수
void count_alphabet(void)
{
	for(int i = 0; i < str.size(); i++)
	{
		alphabet[str[i]- 'A']++;
	}
}

// 팰린드롬을 만드는 것이 불가능한 경우를 판단하는 함수
bool check_impossble(void)
{
	int error = 0;
	for(int i = 0; i < LEN; i++)
	{
		// 문자의 개수가 홀수 이상이 발생하면 아래 로직 수행
		if((alphabet[i] % 2) == 1)
		{
			// 홀수 이상의 문자가 2번 나타나면 팰린드롬을 만드는 것은 불가능
			if(error == 1)
			{
				return true;
			}

			// 1회 나타남
			error++;
		}
	}

	return false;
}

// 문자열을 뒤집어서 새로운 문자열을 만드는 함수
string reverse_str(string cri)
{
	string temp;

	for(int i = (cri.size() - 1); i >= 0; i--)
	{
		temp += cri[i];
	}

	return temp;
}

int main()
{
	cin >> str;

	// 문자 카운트
	count_alphabet();

	// 팰린드롬을 만들 수 없다면 I'm Sorry 출력
	if(check_impossble())
	{
		cout << "I'm Sorry Hansoo" << endl;
	}
	else
	{
		string pre_str;
		string post_str;
		char middle_char = '*';

		// 문자들 순회
		for(int i = 0; i < LEN; i++)
		{
			while(alphabet[i] > 0)
			{
				// 문자의 수가 2 이상이라면 아래 로직 수행
				if(alphabet[i] > 1)
				{
					// 앞의 절반인 pre_str에 문자 append
					pre_str += 'A' + i;

					// 뒤의 절반에도 추후에 구할 예정이므로 -2 감소
					alphabet[i] -= 2;
				}
				// 문자의 수가 1이라면 팰린드롬의 가운데 문자로 확인
				else if(alphabet[i] == 1)
				{
					middle_char = 'A' + i;
					break;
				}
				else
				{
					// do nothing...
				}
			}
		}

		// 앞의 절반인 pre_str을 이용하여 뒤의 절반인 post_str 갱신
		post_str = reverse_str(pre_str);

		// 가운데 문자가 갱신되지 않은 초기값이라면 가운데 문자가 없으므로 pre_str와 post_str만 append
		if(middle_char == '*')
		{
			ans = pre_str + post_str;
		}
		// 가운데 문자가 갱신되었다면 가운데 문자가 있으므로 pre_str와 middle_char와 post_str append
		else
		{
			ans = pre_str + middle_char + post_str;
		}
	}

	// 팰린드롬 출력
	cout << ans << endl;
}