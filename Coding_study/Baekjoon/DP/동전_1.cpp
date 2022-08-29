#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수들 초기화
int n = 0;
int k = 0;

int dp[100001];
vector<int> c;

int main()
{
	scanf("%d %d",&n, &k);

	for(int i = 0; i < n; i++)
	{
		int num = 0;
		scanf("%d", &num);
		c.push_back(num);
	}

	dp[0] = 1;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= k; j++)
		{
			dp[j] = dp[j] + dp[j - c[i]];
		}


	}

	cout << dp[k] << endl;
}