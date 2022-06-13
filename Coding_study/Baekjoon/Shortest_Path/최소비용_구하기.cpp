#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int w = 0;
int start_city = 0;
int end_city = 0;

// 노드와 간선의 정보를 pair 요소로 저장하는 벡터 배열
vector<pair<int, int>> graph[1001];

// 최단거리 테이블
int dis[1001];

void dijkstra(int start)
{
    // {가중치, 도착노드} pair를 요소로 가지며 가중치를 기준으로 오름차순(최소 힙, Min Heap)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
    // 도시의 수와 버스의 개수 입력
    cin >> N >> M;

    // 버스 정보 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d",&u, &v, &w);
        graph[u].push_back({v, w});
    }

    // 출발 도시와 도착 도시 입력
    cin >> start_city >> end_city;

    // 최단경로 테이블 INF로 초기화
    fill(dis, dis + 1001, INF);

    // 다익스트라 알고리즘 수행
    dijkstra(start_city);

    // 출발 도시에서부터 도착 도시까지의 최단 경로 출력
    cout << dis[end_city] << endl;
}