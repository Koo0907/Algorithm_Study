#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int tot = 0;
int res = 0;
int x = 0;
int y = 0;
int z = 0;
int cost = 0;

// 부모 테이블
int parent[200001];

// 경로 정보
vector<pair<int, pair<int, int>>> path;

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
    cin >> N >> M;

    // 부모 테이블 초기화(부모를 자기 자신으로)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // 도로 정보 입력
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        path.push_back({z, {x, y}});
        
        // 모든 도로의 유지비 계산
        tot += z;
    }

    // 도로의 유지비 오름차순으로 정렬
    sort(path.begin(), path.end());

    for(int i = 0; i < M; i++)
    {
        cost = path[i].first;
        x = path[i].second.first;
        y = path[i].second.second;

        // x번 집과 y번 집을 한 그룹으로 묶어도 사이클이 발생하지 않는 경우에만 아래 로직 수행
        if(find_parent(x) != find_parent(y))
        {
            union_parent(x, y);

            // 최소 유지비 계산
            res += cost;
        }
    }

    // 모든 도로의 유지비에서 최소 유지비의 차를 출력
    cout << tot - res << endl;
}