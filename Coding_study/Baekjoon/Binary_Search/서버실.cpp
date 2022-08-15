#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int max_val = 0;
long long total_com = 0;
int ans = 0;
int map[1001][1001];

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			total_com += map[i][j];	// 컴퓨터의 수를 입력받을때마다 합산하여 모든 컴퓨터 수를 계산
			max_val = max(max_val, map[i][j]);	// 가장 컴퓨터 수가 많은 영역 판단
		}
	}

	// 최소 시간은 0분
	long long start = 0;

	// 최대 시간은 컴퓨터가 가장 많은 영역의 컴퓨터 수
	long long end = max_val;

	// 전체 컴퓨터의 50%를 기준으로 잡음
	double criteria = total_com / 2.0;

	while(start <= end)
	{
		long long sum = 0;

		// 소요 시간은 이분 탐색으로 설정
		long long mid = (start + end) / 2;

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				// 현재 순회중인 구역의 컴퓨터 수가 설정한 시간보다 크다면 설정값을 합산
				if(map[i][j] > mid)
				{
					sum += mid;
				}
				// 현재 순회중인 구역의 컴퓨터 수가 설정한 시간보다 작다면 컴퓨터 수를 합산
				else
				{
					sum += map[i][j];
				}
			}
		}

		// 누적으로 더한 값이 기준값(전체 컴퓨터의 50%)보다 작다면 소요 시간을 너무 짧게 설정했다는 뜻이므로 범위를 증가시킴
		if(sum < criteria)
		{
			start = mid + 1;
		}
		// 누적으로 더한 값이 기준값(전체 컴퓨터의 50%) 이상이라면 현재 설정한 시간을 저장하고 소요 시간을 줄여서 확인해봐야 하므로 범위를 감소시킴
		else
		{
			ans = mid;
			end = mid - 1;
		}
	}

	cout << ans << endl;
}