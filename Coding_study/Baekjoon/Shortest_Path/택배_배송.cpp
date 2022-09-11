#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9     // 무한을 의미하는 INF
#define MAX 50001   // 헛간의 최대 수

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;

// 헛간과 소의 데이터를 연결리스트로 가지는 벡터
vector<pair<int, int>> vec[MAX];

// 최단거리 테이블
int dis[MAX];

void dijkstra(int x)
{
    // 최단거리 테이블 초기화
    fill(dis, dis + MAX, INF);

    // 소의 수를 오름차순으로 정렬하는 최소힙 우선순위 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 출발 헛간과 최단거리 데이터 큐에 추가
    pq.push({0, x});

    // 최단거리 테이블 갱신
    dis[x] = 0;

    // 큐가 빌 때까지 순회
    while(!pq.empty())
    {   
        // 큐에서 데이터 추출 및 삭제
        int cow = pq.top().first;
        int hut = pq.top().second;
        pq.pop();

        // cow의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 노드는 방문한 것과 동일
        if(dis[hut] < cow)
        {
            continue;
        }

        // 순회중인 헛간에 연결된 헛간들 순회
        for(int i = 0; i < vec[hut].size(); i++)
        {
            // 다음 헛간과 현재 소의 수와 다음 헛간까지의 소의 수를 합한 값 구함
            int next_cow = cow + vec[hut][i].second;
            int next_hut = vec[hut][i].first;

            // next_cow 값이 최단거리 테이블의 값보다 작으면 아래 로직 수행
            if(dis[next_hut] > next_cow)
            {
                // 최단거리 테이블 갱신
                dis[next_hut] = next_cow;

                // 다음 헛간과 지금까지의 소의 수 큐에 추가
                pq.push({next_cow, next_hut});
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);

        // 양방향임을 주의
        vec[a].push_back({b, c});
        vec[b].push_back({a, c});
    }

    // 1번 헛간에서 출발
    dijkstra(1);

    // N번 헛간까지의 최단거리만 출력
    printf("%d\n", dis[N]);

}