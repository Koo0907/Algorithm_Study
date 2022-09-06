#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 51

using namespace std;

// 사용할 변수 초기화
int N = 0;
int a = 0;
int b = 0;
int cri_score = INF;

// 최단거리 배열
int dis[MAX][MAX];

// 회장 후보를 담는 벡터
vector<int> v;

// 최단거리 배열 초기화
void map_clear(void)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(i != j)
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	// 최단거리 2차원 배열 초기화
	map_clear();

	while(1)
	{
		scanf("%d %d",&a, &b);
		{
			// 두 입력이 모두 -1이면 반복문 탈출
			if((a == -1) && (b == -1))
			{
				break;
			}
		}

		// 서로 친구사이 임으로 각각 경로 갱신
		dis[a][b] = 1;
		dis[b][a] = 1;
	}

	// 플로이드 워셜 알고리즘 수행
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	// 모든 사람들을 순회하면서 체크
	for(int i = 1; i <= N; i++)
	{
		int temp_score = 0;

		// 한 행에 가장 큰 값을 구함
		for(int j = 1; j <= N; j++)
		{
			temp_score = max(temp_score, dis[i][j]);
		}
		
		// 한 행에서 가장 큰 값이 현재까지의 회장 후보 기준 점수와 비교
		// 회장 후보 기준 점수보다 작다면 아래 로직 수행
		if(temp_score < cri_score)
		{
			// 회장 후보 담는 벡터 초기화
			v.clear();

			// 회장 후보 기준 점수 갱신
			cri_score = temp_score;

			// 순회중인 사람 추가
			v.push_back(i);
		}
		// 회장 후보 기준 점수와 같다면 아래 로직 수행
		else if(temp_score == cri_score)
		{
			// 회장 후보 담는 벡터에 순회중인 사람 추가
			v.push_back(i);
		}
		else
		{
			//nothing...
		}
	}

	// 회장 후보 담는 벡터 오름차순 정렬
	sort(v.begin(), v.end());

	// 회장 기준 점수와 후보 수 출력
	cout << cri_score << " " << v.size() << endl;

	// 회장 후보 사람들 출력
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}