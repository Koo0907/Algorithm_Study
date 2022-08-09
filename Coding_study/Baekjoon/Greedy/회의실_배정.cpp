#include<iostream>
#include<algorithm>

using namespace std;

int N = 0;
int res_cnt = 0;
pair<int, int> meet_time[100000];

bool cmp(pair<int, int> A, pair<int, int> B)
{
	if(A.second == B.second)
	{
		// 회의 종료 시간이 같다면 시작 시간이 빠른 순으로 정렬
		return A.first < B.first;
	}
	else
	{
		// 회의 종료 시간이 빠른 순으로 정렬
		return A.second < B.second;
	}
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> meet_time[i].first >> meet_time[i].second;
	}

	sort(meet_time, meet_time + N, cmp);

	int standard_time = 0;	// 이전 회의 종료 시간이자 다음 강의가 시작되는 시간의 기준
	int cnt = 0;	// 회의 수
	for(int i = 0; i < N; i++)
	{
		// 이전 회의의 종료 시간보다 순회중인 회의의 시작 시간이 더 크다면 cnt 증가 
		if(standard_time <= meet_time[i].first)
		{
			standard_time = meet_time[i].second;	// 회의 종료 시간 갱신
			cnt++;	// 회의 수 증가
		}
	}

	cout << cnt << endl;
}