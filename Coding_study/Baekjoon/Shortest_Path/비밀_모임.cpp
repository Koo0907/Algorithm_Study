#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 101

using namespace std;

// 사용할 변수 초기화
int T = 0;
int N = 0;
int M = 0;
int K = 0;
int a = 0;
int b = 0;
int c = 0;
int ans = 0;
int min_val = INF;

// 최단거리 배열
int dis[MAX][MAX];

// 친구들이 있는 방의 데이터를 담는 벡터
vector<int> friend_vec;

// 변수들 초기화 함수
void val_clear(void)
{
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= N; j++)
        {
            if(i == j)
            {
                continue;
            }
            
            // 행과 열이 다른 경우에만 INF로 초기화
            dis[i][j] = INF;
        }
    }

    // 친구들이 있는 방의 데이터를 담는 벡터 초기화
    friend_vec.clear();

    // 최소값 판단을 위한 변수 초기화
    min_val = INF;
}

int main()
{
    // 테스트 케이스 수 입력
    scanf("%d", &T);

    for(int tc = 0; tc < T; tc++)
    {
        // 방의 수와 경로 수 입력
        scanf("%d %d", &N, &M);

        // 변수들 초기화
        val_clear();

        // 경로 데이터 입력
        for(int i = 0; i < M; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            dis[a][b] = c;
            dis[b][a] = c;
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

        // 친구의 수 입력
        scanf("%d", &K);

        // 친구들이 있는 방 입력
        for(int i = 0; i < K; i++)
        {
            scanf("%d", &a);
            friend_vec.push_back(a);
        }

        // 각 방에 대해서 순회
        for(int i = 1; i <= N; i++)
        {
            int temp = 0;

            // 친구들이 있는 방에서부터 현재 순회하는 방까지의 거리를 합산하여 temp 값에 대입
            for(int j = 0; j < K; j++)
            {
                temp += dis[friend_vec[j]][i];
            }

            // temp 값이 현재 최소값보다 작다면 아래 로직 수행
            if(temp < min_val)
            {
                // 최소값 갱신
                min_val = temp;

                // 비밀 모임 방 갱신
                ans = i;
            }
        }

        // 비밀 모임 방 출력
        printf("%d\n", ans);
    }
}