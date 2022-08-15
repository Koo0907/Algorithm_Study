#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
long long M = 0;
long long ans = 0;
vector<long long> vec;

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		long long num = 0;
		cin >> num;
		vec.push_back(num);
	}

	// 절단기 높이의 최소값은 0
	long long start = 0;

	// 절단기 높이의 최대값은 2e10
	long long end = 2e10;

	while(start <= end)
	{
		long long sum = 0;

		// 절단기 높이의 값은 이분 탐색으로 설정
		long long mid = (start + end) / 2;

		for(int i = 0; i < N; i++)
		{
			// 나무의 높이가 절단기 높이보다 크다면 아래 로직 수행
			if(vec[i] > mid)
			{
				// 나무의 높이와 절단기 높이의 차를 구해서 누적으로 더함
				sum += (vec[i] - mid);
			}
		}

		// 누적으로 더한 값이 M보다 작다면 절단기 높이를 너무 높게 설정했다는 뜻이므로 범위를 감소시킴
		if(sum < M)
		{
			end = mid - 1;
		}
		// 누적으로 더한 값이 M 이상이라면 조건을 만족하므로 현재 절단기 높이를 저장하고 절단기 높이를 조금 높혀서 확인해봐야 하므로 범위를 증가시킴
		else
		{
			ans = mid;
			start = mid + 1;
		}
	}

	cout << ans << endl;
}