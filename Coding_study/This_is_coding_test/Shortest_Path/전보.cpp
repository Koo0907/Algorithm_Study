#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int C = 0;
int X = 0;
int Y = 0;
int Z = 0;

// 노드와 간선의 정보를 pair 요소로 저장하는 벡터 배열
vector<pair<int, int>> graph[30001];

// 최단거리 테이블
int dis[30001];

void dijkstra(int start)
{
    // {가중치, 도착노드} pair를 요소로 가지며 가중치를 기준으로 오름차순(최소 힙, Min Heap)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 최초 시작 노드 start와 최단 경로인 0을 우선순위 큐에 push
    pq.push({0, start});

    // 최단거리 테이블 갱신
    dis[start] = 0;

    while(!pq.empty())
    {
        // path는 우선순위 큐 안에서 가중치가 가장 작은 pair의 가중치
        // node는 우선순위 큐 안에서 가중치가 가장 작은 pair의 노드
        int path = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // path의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 노드는 방문한 것과 동일
        if(dis[node] < path)
        {
            continue;
        }

        // 해당 노드를 방문하지 않았다면 연결된 노드들을 순회
        for(int i = 0; i < graph[node].size(); i++)
        {
            // next_node는 현재 노드에서 연결된 노드
            // next_path는 현재 노드까지 계산된 거리(path)와 현재 노드에서부터 연결된 노드까지의 거리(graph[node][i].second)의 값을 더한 값
            int next_node = graph[node][i].first;
            int next_path = path + graph[node][i].second;

            // next_path 값이 최단거리 테이블에 있는 next_node 까지의 거리보다 작다면 아래 로직 수행
            if(next_path < dis[next_node])
            {
                // 최단거리 테이블 값 갱신
                dis[next_node] = next_path;

                // 우선순위 큐에 가중치와 노드 데이터 추가
                pq.push({next_path, next_node});
            }
        }
    }
}

int main()
{
    // 도시 수 N, 통로 수 M, 메시지를 보내고자 하는 도시 C 입력
    cin >> N >> M >> C;

    // 통로 정보 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &X, &Y, &Z);
        graph[X].push_back({Y, Z});
    }

    // 최단거리 테이블 INF로 초기화
    fill(dis, dis + 30001, INF);

    // 다익스트라 알고리즘 수행
    dijkstra(C);

    int cnt = 0;
    int max_dis = 0;

    for(int i = 1; i <= N; i++)
    {
        // 최단거리 테이블에서 INF가 아니면 C 도시와 연결되어 있다는 의미
        if(dis[i] != INF)
        {
            cnt++;
        }

        // 최단거리 테이블에서 가장 긴 거리 탐색
        max_dis = max(max_dis, dis[i]);
    }

    cout << cnt - 1 << " " << max_dis << endl;
}