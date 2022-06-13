#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int H1 = 0;
int H2 = 0;
int tar_H = 0;
int tar_dis = 0;
int tar_same = 1;

// 노드와 간선의 정보를 pair 요소로 저장하는 벡터 배열
vector<pair<int, int>> graph[20001];

// 최단거리 테이블
int dis[20001];

void dijkstra(void)
{
    // {가중치, 도착노드} pair를 요소로 가지며 가중치를 기준으로 오름차순(최소 힙, Min Heap)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 최초 출발 헛간과 최단 경로 0을 우선순위 큐에 삽입
    pq.push({0, 1});

    // 최단거리 테이블 갱신
    dis[1] = 0;

    while(!pq.empty())
    {
        // cost는 우선순위 큐 안에서 가중치가 가장 작은 pair의 거리
        // hut은 우선순위 큐 안에서 가중치가 가장 작은 pair의 헛간
        int cost = pq.top().first;
        int hut = pq.top().second;
        pq.pop();

        // cost의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 헛간은 방문한 것과 동일
        if(dis[hut] < cost)
        {
            continue;
        }

        // 해당 헛간을 방문하지 않았다면 연결된 헛간들을 순회
        for(int i = 0; i < graph[hut].size(); i++)
        {
            // next_hut은 현재 헛간에서 연결된 헛간
            // next_cost는 현재 헛간까지 계산된 거리(cost)와 현재 헛간에서부터 연결된 헛간까지의 거리(graph[hut][i].second)를 더한 거리
            int next_hut = graph[hut][i].first;
            int next_cost = cost + graph[hut][i].second;

            // 위에서 계산한 next_cost값이 현재 최단거리 테이블에 저장된 next_hut까지의 거리보다 작다면 아래 로직 수행
            if(next_cost < dis[next_hut])
            {
                // 최단거리 테이블 갱신
                dis[next_hut] = next_cost;

                // 우선순위 큐에 거리와 헛간 데이터 삽입
                pq.push({next_cost, next_hut});
            }
        }
    }
}

int main()
{
    // 헛간의 수와 통로 데이터 입력
    cin >> N >> M;

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d",&H1, &H2);

        // 통로가 양방향 통로이므로 H1과 H2에 각각 통로 데이터를 의미하는 vector 값 추가
        graph[H1].push_back({H2, 1});
        graph[H2].push_back({H1, 1});
    }

    // 최단경로 테이블 INF로 초기화
    fill(dis, dis + 20001, INF);

    // 다익스트라 알고리즘 수행
    dijkstra();

    // 최단경로 테이블에서 최대값을 찾기 위한 기준 변수 초기화
    int max_val = 0;
    for(int i = 1; i <= N; i++)
    {
        // 현재 순회중인 최단거리 테이블 값이 max_val보다 크다면 아래 로직 수행
        if(dis[i] > max_val)
        {
            // 최대값 갱신
            max_val = dis[i];

            // 출력에 필요한 데이터들 갱신
            tar_H = i;
            tar_dis = dis[i];
            tar_same = 1;
        }
        // 현재 순회중인 최단거리 테이블 값이 max_val과 동일하다면 아래 로직 수행
        else if(dis[i] == max_val)
        {
            // 숨어야 하는 헛간의 거리와 동일 헛간의 수 증가
            tar_same++;
        }
    }

    cout << tar_H << " " << tar_dis << " " << tar_same << endl;
}