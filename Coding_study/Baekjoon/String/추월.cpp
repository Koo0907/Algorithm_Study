#include<iostream>
#include<string>
#include<map>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int cnt = 0;
string car;

// 터널에 들어갈 때의 순위 확인을 위한 맵
map<string, int> m;

// 터널에서 나올때의 순위 확인을 위한 배열
int exit_car[1000];

int main()
{
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		cin >> car;

		// 차 번호을 key값으로 같고 값은 i로 추가
		m[car] = i;
	}

	for(int i = 0; i < N; i++)
	{
		cin >> car;
		
		// 터널에서 나온 차가 들어갈 때 몇번째 순서였는지를 배열의 값으로 갖도록 함
		exit_car[i] = m[car];

	}

	for(int i = 0; i < N; i++)
	{
		for(int j = (i + 1); j < N; j++)
		{
			// i번째로 터널에서 나온 차가 터널에서 먼저 들어간 차보다 일찍 나왔다면 추월을 했다는 뜻
			if(exit_car[i] > exit_car[j])
			{
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;
}