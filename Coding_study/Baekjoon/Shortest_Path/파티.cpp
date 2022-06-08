#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int X = 0;
int u = 0;
int v = 0;
int w = 0;
int max_time = 0;

// 노드와 간선의 정보를 pair 요소로 저장하는 벡터 배열
vector<pair<int, int>> graph[1001];

// 출발하는 마을에서 파티가 열리는 X 마을까지의 최단거리 테이블
int go_dis[1001];

// X 마을에서 출발했던 마을로 다시 돌아가는 최단거리 테이블
int back_dis[1001];

void dijkstra(int start, bool flag)
{
    // {가중치, 도착노드} pair를 요소로 가지며 가중치를 기준으로 내림차순(최소 힙, Min Heap)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // int 포인터로 사용해서 flag 파라미터의 값을 보고 go_dis 테이블 사용할지 back_dis 테이블 사용할지 판단
    int *dis;
    if(flag)
    {
        dis = go_dis;   
    }
    else
    {
        dis = back_dis;
    }

    // 최초 출발 도시와 최단 경로 0을 우선순위 큐에 삽입
    pq.push({0, start});

    // 최단경로 테이블 갱신
    dis[start] = 0;

    while(!pq.empty())
    {
        // cost는 우선순위 큐 안에서 가중치가 가장 작은 pair의 가중치
        // city는 우선순위 큐 안에서 가중치가 가장 작은 pair의 노드
        int cost = pq.top().first;
        int city = pq.top().second;
        pq.pop();

        // path의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 노드는 방문한 것과 동일
        if(dis[city] < cost)
        {
            continue;
        }

        // 해당 노드를 방문하지 않았다면 연결된 노드들을 순회
        for(int i = 0; i < graph[city].size(); i++)
        {
            // next_city는 현재 노드에서 연결된 노드
            // next_cost는 현재 노드까지 계산된 거리(cost)와 현재 노드에서부터 연결된 노드까지의 거리(graph[city][i].second)의 값을 더한 값
            int next_city = graph[city][i].first;
            int next_cost = cost + graph[city][i].second;

            // next_cost 값이 최단거리 테이블에 있는 next_city 까지의 거리보다 작다면 아래 로직 수행
            if(next_cost < dis[next_city])
            {
                // 최단거리 테이블 값 갱신
                dis[next_city] = next_cost;

                // 우선순위 큐에 가중치와 노드 데이터 추가
                pq.push({next_cost, next_city});
            }
        }
    }
}

int main()
{
    // 마을과 도시, 파티가 열리는 마을 입력
    cin >> N >> M >> X;

    // 도로 정보 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        graph[u].push_back({v, w});
    }

    // 파티가 열리는 마을(X)에서부터 각 마을에 대한 최단 경로 구함
    fill(back_dis, back_dis + 1001, INF);
    dijkstra(X, false);

    for(int i = 1; i <= N; i++)
    {
        // 각 마을에서부터 파티가 열리는 마을(X)에 대한 최단 경로를 순회하면서 구함
        fill(go_dis, go_dis + 1001, INF);
        dijkstra(i, true);

        // 현재 순회중인 마을에서 X 마을까지의 거리와 X 마을에서 다시 돌아오는 거리를 합하여 최대값을 도출
        if(go_dis[X] + back_dis[i] > max_time)
        {
            max_time = go_dis[X] + back_dis[i];
        }
    }

    // 왕복 최단 경로 최대값 출력
    cout << max_time << endl;
}