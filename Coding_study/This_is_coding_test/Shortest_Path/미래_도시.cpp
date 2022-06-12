#include<iostream>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MAX 101 // 최대 회사 수가 100개이므로 101을 MAX 값으로 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int C1 = 0;
int C2 = 0;
int X = 0;
int K = 0;

// 최단거리 테이블
int graph[MAX][MAX];

int main()
{
    // 회사 수 N, 경로 수 M 입력
    cin >> N >> M;

    // 최단거리 테이블 INF로 초기화
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // 입력받은 N개의 회사 중에서 시작 회사와 도착 회사가 같은 경우는 0으로 설정
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    // 경로 정보 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &C1, &C2);

        // 통로가 연결되면 양방향으로 이동할 수 있음
        graph[C1][C2] = 1;
        graph[C2][C1] = 1;
    }

    // 플로이드 워셜 알고리즘 수행
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 물건을 판매할 회사 X, 소개팅을 하러 갈 회사 K 입력
    cin >> X >> K;

    // 1번 회사에서 K 회사까지의 거리와 K 회사에서 X 회사까지의 거리를 구함
    int dis = graph[1][K] + graph[K][X];

    // 구한 거리가 INF 이하라면 연결되어 있다는 뜻이므로 거리 출력, 그렇지 않으면 -1 출력
    if(dis < INF)
    {
        cout << dis << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}