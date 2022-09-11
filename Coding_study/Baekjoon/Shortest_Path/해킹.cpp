#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9     // 무한을 의미하는 값으로 10억을 설정
#define MAX 10001   // 컴퓨터의 최대 수

using namespace std;

// 사용할 변수 초기화
int T = 0;
int n = 0;
int d = 0;
int c = 0;
int a = 0;
int b = 0;
int s = 0;

// 컴퓨터들간의 의존성을 나타내는 벡터
vector<pair<int, int>> v[MAX];

// 최단거리 테이블
int dis[MAX];

void dijkstra(void)
{
    // 감염에 걸리는 시간으로 오름차순 정렬 하는 최소 힙 큐 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // 감염이 시작되는 컴퓨터와 감염 시간 큐에 추가
    pq.push({0, c});

    // 최단거리 테이블 갱신
    dis[c] = 0;

    // 큐가 빌 때까지 반복
    while(!pq.empty())
    {
        // 큐에서 감염시간과 컴퓨터 데이터 추출 및 삭제
        int time = pq.top().first;
        int com = pq.top().second;
        pq.pop();

        // time의 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 컴퓨터는 방문한 것으로 판단
        if(dis[com] < time)
        {
            continue;
        }

        // 현재 컴퓨터와 의존성이 있는 컴퓨터들 순회
        for(int i = 0; i < v[com].size(); i++)
        {
            // next_time은 다음 컴퓨터가 감염되기 까지의 시간\
            // next_com은 감염될 다음 컴퓨터
            int next_time = v[com][i].second + time;
            int next_com = v[com][i].first;

            // next_time이 최단거리 테이블의 값보다 작다면 아래 로직 수행
            if(next_time < dis[next_com])
            {
                // 최단거리 테이블 초기화
                dis[next_com] = next_time;

                // 큐에 다음 컴퓨터의 데이터 추가
                pq.push({next_time, next_com});
            }
        }
    }
}

int main()
{
    cin >> T;

    for(int Tc = 0; Tc < T; Tc++)
    {
        // 감염된 컴퓨터와 그에 걸리는 시간을 나타내는 변수 선언
        int hacked_com = 0;
        int all_time = 0;

        // 컴퓨터의 수, 의존성 수, 감염이 시작된 컴퓨터의 번호 입력
        cin >> n >> d >> c;

        // 컴퓨터들간의 의존성을 나타대는 벡터 초기화
        for(int i = 1; i <= n; i++)
        {
            v[i].clear();
        }

        // 컴퓨터들간의 의존성 데이터 입력
        for(int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;

            // 양방향이 아님을 주의
            v[b].push_back({a, s});
        }

        // 최단거리 테이블 초기화
        fill(dis, dis + MAX, INF);
        
        // 다익스트라 알고리즘 수행
        dijkstra();

        // 최단거리 테이블 순회
        for(int i = 1; i <= n; i++)
        {
            // 최단거리 테이블의 값이 INF가 아니라면 C번 컴퓨터로 인해서 감염되었다는 의미이므로 아래 로직 수행
            if(dis[i] != INF)
            {
                // 감염된 컴퓨터 수 증가
                hacked_com++;

                // 최단거리 테이블의 최대값이 마지막 컴퓨터가 감염되기까지의 시간과 동일하므로 최대값 갱신
                all_time = max(all_time, dis[i]);
            }
        }

        // 출력
        cout << hacked_com << " " << all_time << endl;
    }
}