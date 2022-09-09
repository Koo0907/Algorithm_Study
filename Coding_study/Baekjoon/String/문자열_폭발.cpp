#include<iostream>
#include<string>

using namespace std;

// 사용할 변수 초기화
string str;
string bomb;
string ans;

int main()
{
	cin >> str >> bomb;

	// 주어지는 string의 길이만큼 순회
	for(int i = 0; i < str.length(); i++)
	{
		// ans string에 주어지는 string의 값 대입
		ans += str[i];

		// ans의 길이가 폭탄 문자열의 길이 이상이 되는 시점부터 체크
		if(ans.size() >= bomb.size())
		{
			// 순회중인 자리의 문자가 폭탄 문자열의 마지막 문자와 같다면 아래 로직 수행
			if(ans[ans.size() - 1] == bomb[bomb.size() - 1])
			{
				// 폭발 flag set
				bool explode = true;

				// 폭탄 문자열의 길이만큼 순회
				for(int j = 0; j < bomb.size(); j++)
				{
					// ans string에서 폭탄 문자열 길이 만큼 전부터 폭탄 문자열이 있는지 확인
					// 폭탄 문자열과 다른 문자가 있다면 아래 로직 수행
					if(ans[ans.size() - bomb.size() + j] != bomb[j])
					{
						// 폭발 flag clear
						explode = false;
						break;
					}
				}

				// 폭발 flag가 set되어 있다면 폭탄문자열은 erase
				if(explode)
				{
					ans.erase(ans.size() - bomb.size());
				}
			}
		}
	}

	// ans string의 길이가 0이라면 모두 폭발했다는 의미로 "FRULA" 출력
	if(ans.size() == 0)
	{
		cout << "FRULA" << endl;
	}
	else
	{
		cout << ans << endl;
	}
}