#include<iostream>
#include<string>

using namespace std;

// 사용할 변수 초기화
int T = 0;
string str;

// 회문 확인하는 함수
int check_palline(int start, int end, bool except)
{
	// start index가 end index보다 작다면 반복 수행
	while(start <= end)
	{
		// 두 문자가 다르다면 회문이 아닌 것이므로 아래 로직 수행
		if(str[start] != str[end])
		{
			// 아직 문자 하나를 지우고 확인해보지 않았다면 아래 로직 수행
			if(except == false)
			{
				// 문자가 틀렸던 두 index 중에 start index의 문자나 end index의 문자를 각각 제외시키고 회문인지 확인
				if((check_palline(start, end-1, true) == 0) || (check_palline(start + 1, end, true) == 0))
				{
					// 문자를 제외시키고 회문이라면 유사 회문 반환
					return 1;
				}
				else
				{
					// 문자를 제외시키고도 회문이 아니라면 비회문 반환
					return 2;
				}
			}
			// 이미 문자를 지워서 확인해봤다면 비회문 반환
			else
			{
				return 2;
			}
		}
		// 두 문자가 같다면 index 갱신 후 반복해서 확인
		else
		{
			start++;
			end--;
		}
	}

	// 회문 반환
	return 0;
}

int main()
{
	scanf("%d", &T);

	for(int Tc = 0; Tc < T; Tc++)
	{
		cin >> str;

		// 입력된 문자열에 대해서 회문 확인 후 반환값 출력
		cout << check_palline(0, str.size() - 1, false) << endl;;
	}
}