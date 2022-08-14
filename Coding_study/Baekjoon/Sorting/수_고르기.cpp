#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int M = 0;
int S = 0;
int E = 0;
int res = 2e9;
vector<int> A;

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		A.push_back(num);
	}

	// 수열 오름차순 정렬
	sort(A.begin(), A.end());

	// 투 포인터 사용하여 S 인덱스와 E 인덱스가 범위를 벗어나지 않는다면 아래 로직 수행
	while((S < A.size()) && (E < A.size()))
	{
		// 두 수의 차가 기준값인 M 이상이 아니라면 E 인덱스 증가
		if(A[E] - A[S] < M)
		{
			E++;
		}
		// 두 수의 차가 기준값인 M 이상이라면 최소값 갱신 후 S 인덱스 증가
		else
		{
			res = min(res, A[E] - A[S]);
			S++;
		}
	}

	cout << res << endl;
}