#include<iostream>
#include<vector>
#include<queue>

// 문제의 답이 int의 범위를 넘어가기 때문에 INF 값도 크게 설정
#define INF 1e12
#define MAX 100000

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
char S = 0;
int a = 0;
int b = 0;
int t = 0;

// 각 넥서스에서 상대의 시야에 있는지에 대한 데이터를 받을 배열
char visible[MAX];

// 각 넥서스와 시간을 입력받을 벡터
vector<pair<int, int>> vec[MAX];

// 최단거리 테이블
long long dis[MAX];

void dijkstra(int x)
{
    // 넥서스간의 시간을 기준으로 오름차순(최소 힙)으로 정렬되도록 우선순위 큐 선언
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    // 시작 넥서스에 대한 최단거리 테이블 갱신
    dis[x] = 0;

    // 큐에 데이터 추가
    pq.push({0, x});

    // 큐가 빌 때까지 반복
    while(!pq.empty())
    {
        // cost는 우선순위 큐 안에서 가중치가 가장 작은 pair의 가중치
        // node는 우선순위 큐 안에서 가중치가 가장 작은 pair의 노드
        long long cost = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        // 최단거리 테이블의 값이 이미 해당 넥서스까지의 거리보다 작거나, 상대의 시야에 있는 넥스서라면 continue
        if((dis[node] < cost) || (visible[node] == 1))
        {
            continue;
        }

        // 현재 순회중인 넥서스와 연결되어 있는 넥서스들 순회
        for(int i = 0; i < vec[node].size(); i++)
        {
            // next_node는 다음 넥서스
            // next_cost는 다음 넥서스까지의 시간
            long long next_node = vec[node][i].first;
            long long next_cost = cost + vec[node][i].second;

            // next_cost 값이 최단거리 테이블에 있는 next_node 까지의 거리보다 작다면 아래 로직 수행
            if(dis[next_node] > next_cost)
            {
                // 최단거리 테이블 갱신
                dis[next_node] = next_cost;

                // 큐에 데이터 추가
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main()
{
    // N와 M 입력
    scanf("%d %d", &N, &M);

    // 각 넥서스가 상대의 시야에 있는지에 대한 데이터 입력
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &S);
        visible[i] = S;
    }

    // 간선 수 만큼 순회
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &t);

        // 양방향임을 주의
        vec[a].push_back({b, t});
        vec[b].push_back({a, t});
    }

    // 최단거리 테이블 초기화
    fill(dis, dis + N, INF);

    // 0번 넥서스부터 시작하여 다익스트라 알고리즘 수행
    dijkstra(0);

    // N - 1번 넥서스까지의 경로가 없다면 -1 출력
    if(dis[N - 1] == INF)
    {
        printf("-1\n");
    }
    // 그렇지 않다면 최단거리 출력
    else
    {
        printf("%lld\n", dis[N - 1]);
    }
}
