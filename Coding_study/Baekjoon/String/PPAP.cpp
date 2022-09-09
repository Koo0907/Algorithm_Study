#include<iostream>
#include<string>
#include<map>

using namespace std;

// 사용할 변수 초기화
string str;
int P_cnt = 0;

int main()
{
	cin >> str;

	// 문자열 전체 순회
	for(int i = 0; i < str.size(); i++)
	{
		// P가 나오면 P의 개수인 P_cnt 증가하고 continue
		if(str[i] == 'P')
		{
			P_cnt++;
			continue;
		}

		// A가 나오면 지금까지 P가 2번 이상 연속으로 나오고 다음 문자가 P인지 확인
		// 그러면 다음 문자까지 포함해서 "PPAP"가 완성됨
		if((P_cnt >= 2) && (str[i + 1] == 'P'))
		{
			// "PPAP"를 P로 치환할 것이므로 P_cnt는 1 감소
			P_cnt--;

			// 다음 문자인 P까지 확인했으므로 i는 1 증가
			i++;
		}
		// A가 나왔는데 P가 연속 2번 나오지 않거나 다음 문자가 P가 아니라면 PPAP 문자열이 아님
		else
		{
			cout << "NP" << endl;
			return 0;
		}
	}

	// 순회를 다 하고 P로 끝났다면 PPAP 문자열임
	if(P_cnt == 1)
	{
		cout << "PPAP" << endl;
	}
	else
	{
		cout << "NP" << endl;
	}
}