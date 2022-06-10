#include<iostream>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MAX 101 // 최대 도시 수가 100개 이므로 101을 MAX 값으로 설정

using namespace std;

// 사용할 변수 초기화
int n = 0;
int m = 0;
int u = 0;
int v = 0;
int w = 0;

// 2차원 최단거리 테이블
int graph[MAX][MAX];

int main()
{
    cin >> n >> m;

    // 최단거리 테이블 INF로 초기화
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // 입력받은 n개의 도시 중에서 시작 도시와 도착 도시가 같은 경우는 0으로 초기화
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(i == j)
            {
                graph[i][j] = 0;
            }
        }
    }

    // 버스 정보 입력
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);

        // 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐수도 있으므로 최소값을 테이블에 저장
        graph[u][v] = min(graph[u][v], w);
    }

    // 플로이드 워셜 알고리즘 수행
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    // 결과 출력
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(graph[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << graph[i][j] << " ";
            }
        }

        cout << '\n';
    }
}