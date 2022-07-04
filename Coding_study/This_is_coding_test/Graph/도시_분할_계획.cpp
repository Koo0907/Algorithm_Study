/* 백준 링크 */
/* https://www.acmicpc.net/problem/1647 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int x = 0;
int y = 0;
int cost = 0;
int res = 0;
int last_val = 0;

vector<pair<int, pair<int, int>>> path;
// 부모 테이블 초기화
int parent[100001];

int find_parent(int x)
{
    // 루트노드라면(자기 자신과 부모의 값이 같다면) 값 반환
    if(x == parent[x])
    {
        return x;
    }
    // 루트노드가 아니라면 찾을 때 까지 부모테이블 갱신하면서 재귀호출
    else
    {
        return parent[x] = find_parent(parent[x]);
    }
}

void union_parent(int x, int y)
{
    // x와 y의 루트노드 탐색
    x = find_parent(x);
    y = find_parent(y);
    
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

    // 경로 정보 입력
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y >> cost;
        path.push_back({cost, {x, y}});
    }

    // 경로의 유지비 순으로 오름차순 정렬
    sort(path.begin(), path.end());

    for(int i = 0; i < M; i++)
    {
        cost = path[i].first;
        x = path[i].second.first;
        y = path[i].second.second;

        // x, y를 한 그룹으로 묶어도 사이클이 발생하지 않는 경우에만 아래 로직 수행
        if(find_parent(x) != find_parent(y))
        {
            // 한 그룹으로 묶음
            union_parent(x, y);
            
            // 유지비 갱신
            res += cost;

            // 마지막 수 갱신
            last_val = cost;
        }
    }

    // 유지비의 총 합에서 마지막 last_val 값을 뺌
    // 현재 마을을 기준으로 작성한 최소 신장 트리에서 가장 큰 유지비를 가진 경로를 빼면
    // 자연스럽게 두 마을로 나눠지면서 최소의 유지비로 경로를 구축하고 있음.
    cout << res - last_val << endl;
}