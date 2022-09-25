#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int K = 0;
int ans = 0;
int cnt = 0;

// 간선의 데이터를 담는 벡터
vector<pair<int, pair<int, int>>> graph;

// 부모 테이블 선언
int parent[MAX];

// find 연산
int find_parent(int a)
{
    // a의 부모 노드가 a라면 그대로 a 출력
    if(a == parent[a])
    {
        return a;
    }
    // a의 부모 노드가 a가 아니라면 부모 테이블 갱신
    else
    {
        return parent[a] = find_parent(parent[a]);
    }
}

// union 연산
void union_parent(int a, int b)
{
    // a, b의 부모 노드 확인
    a = find_parent(a);
    b = find_parent(b);

    // 더 작은 값이 부모 노드가 되도록 설정
    if(a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    // 정점, 간선, 턴 수 입력
    scanf("%d %d %d", &N, &M, &K);

    // 간선 정보 입력
    for(int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph.push_back({i, {a, b}});
    }

    // 간선의 가중치 오름차순 정렬
    sort(graph.begin(), graph.end());

    // 턴의 수 만큼 반복
    for(int Tc = 0; Tc < K; Tc++)
    {
        // 부모 테이블 초기화
        for(int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }

        // 사용할 변수 초기화
        ans = 0;
        cnt = 0;

        // 간선의 수 만큼 순회
        for(int i = 0; i < graph.size(); i++)
        {
            // a, b는 연결되어 있는 노드
            // cost는 두 노드를 잇는 경로의 가중치
            int a = graph[i].second.first;
            int b = graph[i].second.second;
            int cost = graph[i].first;

            // a와 b가 서로 같은 부모 노드를 가지고 있지 않다면(=Cycle을 이루지 않는다면) 아래 로직 수행
            if(find_parent(a) != find_parent(b))
            {
                // union 연산
                union_parent(a, b);

                // 연결한 간선의 수 증가
                cnt++;

                // 비용 갱신
                ans += cost;
            }
        }

        // 한 턴이 종료되고 연결한 간선의 수가 정점의 수보다 1 더 작으면 MST 완성
        if(cnt == N - 1)
        {
            printf("%d ", ans);
        }
        else
        {
            printf("0 ");
        }

        // 오름차순 정렬했으므로 첫번째 요소가 가장 가중치가 작은 경로이므로 삭제
        graph.erase(graph.begin());
    }
}