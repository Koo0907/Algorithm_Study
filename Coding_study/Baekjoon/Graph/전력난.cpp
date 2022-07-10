#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

// 사용할 변수 초기화
int m = 0;
int n = 0;
int x = 0;
int y = 0;
int z = 0;
int res = 0;
int total = 0;

// 부모 테이블
int parent[200001];

// 경로 정보
vector<pair<int, pair<int, int>>> graph;

int find_parent(int a)
{
    // 루트노드라면(자기 자신과 부모의 값이 같다면) 값 반환
    if(parent[a] == a)
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
    a = find_parent(a);
    b = find_parent(b);

    // 더 작은 값이 큰 값의 부모가 되도록 설정
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
    while(true)
    {
        cin >> m >> n;

        // 무한 반복문 탈출 조건 판단
        if((m == 0) && (n == 0))
        {
            break;
        }

        // 다음 테스트 케이스를 위한 변수 초기화
        graph.clear();
        memset(parent, 0, sizeof(parent));
        res = 0;
        total = 0;

        // 부모 테이블 초기화(부모를 자기 자신으로)
        for(int i = 0; i < m; i++)
        {
            parent[i] = i;
        }

        // 마을 경로 입력
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            graph.push_back({z, {x, y}});
            total += z;
        }

        // 가로등의 유지비 순으로 오름차순 정렬
        sort(graph.begin(), graph.end());

        for(int i = 0; i < n; i++)
        {
            int cost = graph[i].first;
            int a = graph[i].second.first;
            int b = graph[i].second.second;

            // a, b를 한 그룹으로 묶어도 사이클이 발생하지 않는 경우에만 아래 로직 수행
            if(find_parent(a) != find_parent(b))
            {
                // 한 그룹으로 묶음
                union_parent(a, b);

                // 비용 갱신
                res += cost;
            }
        }

        // 결과 출력
        cout << total - res << endl;
    }
}