#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MAX 125 // 최대 탐사 공간 수가 125이므로 MAX 값으로 설정

using namespace std;

// 상,하,좌,우 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int T = 0;
int N = 0;

// 전체 맵
int graph[MAX][MAX];

// 최단거리 테이블
int dis[MAX][MAX];

void dijkstra(void)
{
    // {가중치, {x좌표, y좌표}}} pair-pair를 요소로 가지며 가중치를 기준으로 오름차순(최소 힙, Min Heap)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // 시작점 (0,0)에서의 최단거리 테이블 갱신
    dis[0][0] = graph[0][0];

    // (0,0)에 대한 최단거리 데이터 큐에 삽입
    pq.push({graph[0][0], {0, 0}});

    while(!pq.empty())
    {
        // d = (0,0)에서 우선순위 큐 안에서 거리가 가장 짧은 데이터의 좌표까지의 거리
        // x = 우선순위 큐 안에서 거리가 짧은 가장 데이터의 좌표의 x값
        // y = 우선순위 큐 안에서 거리가 짧은 가장 데이터의 좌표의 y값
        int d = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        // d의 값이 현재 저장되어 있는 최단거리 테이블에 저장된 값보다 크다면 해당 좌표는 방문한 것과 동일
        if(dis[x][y] < d)
        {
            continue;
        }

        // 상,하,좌,우 방향으로 좌표 순회
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 좌표가 맵의 범위를 넘어간다면 무시
            if((next_x < 0) || (next_x >= N) || (next_y < 0) || (next_y >= N))
            {
                continue;
            }

            // next_d = (0,0)에서부터의 거리와 순회중인 좌표의 거리를 더한 거리
            int next_d = d + graph[next_x][next_y];

            // 위에서 계산한 next_d 값이 최단거리 테이블의 거리보다 작다면 아래 로직 수행
            if(dis[next_x][next_y] > next_d)
            {
                // 최단거리 테이블 갱신
                dis[next_x][next_y] = next_d;

                // 우선순위 큐에 가중치와 좌표 데이터 삽입
                pq.push({next_d, {next_x, next_y}});
            }
        }
    }
}

int main()
{
    // 테스트 케이스의 수 T 입력
    cin >> T;

    for(int tc = 0; tc < T; tc++)
    {
        // 탐사 공간 수 N 입력
        cin >> N;

        // 맵 정보 입력
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                scanf("%d", &graph[i][j]);
            }
        }

        // 최단거리 테이블 INF로 초기화
        for(int i = 0; i < N; i++)
        {
            fill(dis[i], dis[i] + MAX, INF);
        }

        // 다익스트라 알고리즘 수행
        dijkstra();

        // (0,0)부터 (N-1,N-1)까지의 최단거리 데이터 출력
        cout << dis[N - 1][N - 1] << endl;
    }
}