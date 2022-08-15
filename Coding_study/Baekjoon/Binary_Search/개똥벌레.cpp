#include<iostream>
#include<vector>
#include<algorithm>

#define off_set 0.5

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int H = 0;
int res1 = 0;
int res2 = 0;
int res = 0;
int res_cnt = 0;
int min_val = 2e9;
vector<int> bot;
vector<int> top;

int main()
{
	cin >> N >> H;

	for(int i = 0; i < N; i++)
	{
		int len = 0;
		cin >> len;

		if((i % 2) == 0)
		{
			// 석순 높이 벡터
			bot.push_back(len);
		}
		else
		{
			// 종유석 높이 벡터
			top.push_back(len);
		}
	}

	// 각 벡터 정렬
	sort(bot.begin(), bot.end());
	sort(top.begin(), top.end());

	for(int i = 1; i <= H; i++)
	{
		// 석순 높이 벡터에서 lower_bound 메서드 활용
		res1 = (lower_bound(bot.begin(), bot.end(), i) - bot.begin());
		res1 = bot.size() - res1;

		// 종유석 높이 벡터에서 lower_bound 메서드 활용
		res2 = (upper_bound(top.begin(), top.end(), (H-i)) - top.begin());
		res2 = top.size() - res2;

		// 전체 cnt 합산
		res = res1 + res2;

		// 구한 cnt가 이전에 갱신했던 최소값과 같다면 구역 수 증가
		if(res == min_val)
		{
			res_cnt++;
		}
		// 구한 cnt가 이전에 갱신했던 최소값보다 작다면 최소값 재갱신 후 구역 수 초기화
		else if(res < min_val)
		{
			min_val = res;
			res_cnt = 1;
		}
		else
		{
			// nothing
		}

		// 변수 초기화
		res1 = 0;
		res2 = 0;
		res = 0;
	}

	cout << min_val << " " << res_cnt << endl;
}