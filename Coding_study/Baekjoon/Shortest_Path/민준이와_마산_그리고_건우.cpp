#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9
#define MAX 5001

using namespace std;

// 사용할 변수 초기화
int V = 0;
int E = 0;
int P = 0;
int a = 0;
int b = 0;
int c = 0;

// 정점과 간선간의 그래프 데이터를 담는 벡터
vector<pair<int, int>> vec[MAX];

// 최단거리 테이블
int dis[MAX];

void dijkstra(int x)
{
    // 최단거리 테이블 초기화
    fill(dis, dis + MAX, INF);

    // 정점간의 거리를 기준으로 하여 오름차순(최소 힙)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 최단거리 테이블 갱신
    dis[x] = 0;

    // 우선순위 큐에 데이터 추가
    pq.push({0, x});

    while(!pq.empty())
    {
        // cost는 우선순위 큐 안에서 가중치가 가장 작은 pair의 가중치
        // node는 우선순위 큐 안에서 가중치가 가장 작은 pair의 노드
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // cost의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 노드는 방문한 것과 동일
        if(dis[node] < cost)
        {
            continue;
        }

        // 해당 노드를 방문하지 않았다면 연결된 노드들을 순회
        for(int i = 0; i < vec[node].size(); i++)
        {
            // next_node는 순회중인 노드와 연결된 다음 노드
            // next_cost는 순회중인 노드와 연결된 다음 노드까지의 거리
            int next_node = vec[node][i].first;
            int next_cost = cost + vec[node][i].second;

            // next_cost 값이 최단거리 테이블에 있는 next_node 까지의 거리보다 작다면 아래 로직 수행
            if(dis[next_node] > next_cost)
            {
                // 최단거리 테이블 갱신
                dis[next_node] = next_cost;

                // 우선순위 큐에 데이터 추가
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main()
{
    // V, E, P 데이터 입력
    scanf("%d %d %d", &V, &E, &P);

    // 간선 수만큼 경로 데이터 입력
    for(int i = 0; i < E; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        // 양방향임을 주의
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    // path1은 마산으로 바로 가는 경로
    // path2는 중간에 건우를 구하고 마산으로 가는 경로
    int path1 = 0;
    int path2 = 0;

    // 1번 노드에서 출발하도록 다익스트라 알고리즘 수행
    dijkstra(1);

    // 각 경로들 갱신
    path1 = dis[V];
    path2 = dis[P];

    // 건우가 있는 P번 노드에서 출발하도록 다익스트라 알고리즘 수행
    dijkstra(P);

    // 건우를 구하는 경로 갱신
    path2 += dis[V];

    // 건우를 구하는 경로가 마산으로 바로 가는 경로보다 작거나 같다면 아래 로직 수행
    if(path2 <= path1)
    {
        printf("SAVE HIM\n");
    }
    // 건우를 구하는 경로가 마산으로 바로 가는 경로보다 크다면 아래 로직 수행
    else
    {
        printf("GOOD BYE\n");
    }
}
