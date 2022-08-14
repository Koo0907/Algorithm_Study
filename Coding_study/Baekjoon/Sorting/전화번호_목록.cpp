#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
int Tc = 0;
int N = 0;
bool ans_flag = true;
vector<string> phone_book;
vector<bool> res;

int main()
{
	scanf("%d",&Tc);

	for(int i = 0; i < Tc; i++)
	{
		scanf("%d",&N);

		for(int j = 0; j < N; j++)
		{
			string phone_num;
			cin >> phone_num;
			phone_book.push_back(phone_num);
		}

		// 전화번호부 오름차순 정렬
		sort(phone_book.begin(),phone_book.end());

		for(int j = 0; j < (phone_book.size()- 1) ; j++)
		{
			// j번째 전화번호의 길이가 j+1번째 전화번호의 길이보다 길다면 prefix가 될 수 없으므로 continue
			if(phone_book[j].size() > phone_book[j + 1].size())
			{
				continue;
			}

			// j번째 전화번호가 j+1번째 전화번호의 prefix라면 일관성이 없다는 의미
			if(phone_book[j] == phone_book[j + 1].substr(0, phone_book[j].size()))
			{
				// flag 설정
				ans_flag = false;
				break;
			}
		}

		// 결과 벡터에 flag값 추가
		res.push_back(ans_flag);

		// 벡터 및 flag 초기화
		phone_book.clear();
		ans_flag = true;
	}

	for(int i = 0; i < res.size(); i++)
	{
		if(res[i])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}