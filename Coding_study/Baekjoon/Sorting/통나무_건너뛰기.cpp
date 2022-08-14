#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
int Tc = 0;
int N = 0;
int dif = 0;
vector<int> len;
vector<int> res;

int main()
{
	cin >> Tc;

	for(int i = 0; i < Tc; i++)
	{
		cin >> N;

		for(int j = 0; j < N; j++)
		{
			int num = 0;
			cin >> num;
			len.push_back(num);
		}

		// 통나무 높이 오름차순 정렬
		sort(len.begin(), len.end());

		// j번째 통나무의 높이와 j+2번째 통나무의 높이의 차를 전부 구하고 그 중의 최대값이 최적해
		for(int j = 0; j < (len.size() - 2); j++)
		{
			dif = max(dif, abs(len[j] - len[j + 2]));
		}

		res.push_back(dif);
		
		// vector 및 결과값 초기화
		len.clear();
		dif = 0;
	}

	for(int i = 0; i < res.size(); i++)
	{
		cout << res[i] << endl;
	}
}