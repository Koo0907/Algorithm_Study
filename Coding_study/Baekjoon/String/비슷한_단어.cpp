#include<iostream>
#include<cstring>

#define LEN 26

using namespace std;

// 사용할 변수 초기화
int N = 0;
int cnt = 0;
int ans = 0;
string str;
string cmp_str;

int alphabet[LEN];
int temp[LEN];

int main()
{
	cin >> N >> str;

	// 기준 문자열의 철자 수 저장
	for(int i = 0; i < str.size(); i++)
	{
		alphabet[str[i] - 'A']++;
	}

	for(int i = 0; i < N - 1; i++)
	{
		// temp 배열에 alphabet 배열 복사
		memcpy(temp, alphabet, sizeof(alphabet));

		// 비교 문자열 입력
		cin >> cmp_str;

		// cnt 변수 초기화
		cnt = 0;

		// 비교 문자열의 길이 만큼 순회
		for(int j = 0; j < cmp_str.size(); j++)
		{
			// 비교 문자열의 철자가 기준 문자열에서도 존재했는지 확인
			if(temp[cmp_str[j] - 'A'] > 0)
			{
				// 기준 문자열 철자 배열에서 해당 문자 감소하고 cnt 증가
				temp[cmp_str[j] - 'A']--;
				cnt++;
			}
		}

		// 기준 문자열과 비교 문자열의 길이가 같고, 비교 문자열의 철자와 기준 문자열의 철자가 동일하거나, 비교 문자열이 하나만 다른 경우에는 비슷한 단어로 판단
		if((str.size() == cmp_str.size()) && ((cnt == cmp_str.size()) || (cnt == cmp_str.size() - 1)))
		{
			ans++;
		}
		// 기준 문자열의 길이가 비교 문자열의 길이보다 1 작고, 기준 문자열의 철자가 비교 문자열에 모두 포함되어 있는 경우에는 비슷한 단어로 판단
		else if((str.size() == cmp_str.size() - 1) && (cnt == str.size()))
		{
			ans++;
		}
		// 기준 문자열의 길이가 비교 문자열의 길이보다 1 크고, 비교 문자열의 철자가 기준 문자열에 모두 포함되어 있는 경우에는 비슷한 단어로 판단
		else if((str.size() == cmp_str.size() + 1) && (cnt == cmp_str.size()))
		{
			ans++;
		}
	}

	// 비슷한 단어 수 출력
	cout << ans << endl;
}