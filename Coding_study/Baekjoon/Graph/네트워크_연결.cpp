#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;
int res = 0;

// 부모 테이블
int parent[1001];

// 네트워크 정보 저장
vector<pair<int, pair<int, int>>> graph;

int find_parent(int a)
{
    // 루트노드라면(자기 자신과 부모의 값이 같다면) 값 반환
    if(a == parent[a])
    {
        return a;
    }
    // 루트노드가 아니라면 찾을 때 까지 부모테이블 갱신하면서 재귀호출
    else
    {
        return parent[a] = find_parent(parent[a]);
    }
}

void union_parent(int a, int b)
{
    // a와 b의 루트노드 탐색
    int x = find_parent(a);
    int y = find_parent(b);

    // 더 작은 값이 큰 값의 부모가 되도록 설정
    if(x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}


int main()
{
    cin >> N >> M;

    // 부모 테이블 초기화(부모를 자기 자신으로)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // 네트워크 정보 입력
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }

    // 경로의 유지비 순으로 오름차순 정렬
    sort(graph.begin(), graph.end());

    for(int i = 0; i < M; i++)
    {
        int cost = graph[i].first;
        int x = graph[i].second.first;
        int y = graph[i].second.second;

        // x, y를 한 그룹으로 묶어도 사이클이 발생하지 않는 경우에만 아래 로직 수행
        if(find_parent(x) != find_parent(y))
        {
            // 한 그룹으로 묶음
            union_parent(x, y);

            // 비용 갱신
            res += cost;
        }
    }

    cout << res << endl;
}