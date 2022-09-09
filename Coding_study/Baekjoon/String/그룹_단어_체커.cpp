#include<iostream>
#include<string>

#define LEN 26

using namespace std;

// 사용할 변수 초기화
int N = 0;
int cnt = 0;
bool not_count = false;

// 알파벳이 지금까지 나타났는지 보여주는 배열
bool alpabet[26];

// 배열 및 falg 초기화
void clear(void)
{
	for(int i = 0; i < LEN; i++)
	{
		alpabet[i] = false;
	}

	not_count = false;
}

int main()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		string word;

		// 배열 및 flag 초기화
		clear();

		cin >> word;
		
		// 단어 길이만큼 순회
		for(int j = 0; j < word.length(); j++)
		{
			// 알파벳에 'a'를 빼서 아스키 값을 구함
			int now = word[j] - 'a';

			// 아직 나타나지 않은 알파벳이라면 true 설정 후 넘어감
			if(alpabet[now] == false)
			{
				alpabet[now] = true;
			}
			// 이미 나타난 알파벳이라면 아래 로직 수행
			else
			{
				// 직전에 나타난 알파벳이 아니라면 not_count flag 설정
				if(word[j - 1] != word[j])
				{
					not_count = true;
					break;
				}
			}
		}

		// not_count flag가 false인 경우에만 cnt 증가
		if(not_count == false)
		{
			cnt++;
		}
	}

	cout << cnt << endl;
}