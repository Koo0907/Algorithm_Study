#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int path = 0;
int trip = 0;
bool flag = true;

// 부모 테이블
int parent[501];

// 여행 계획
vector<int> plan;

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
    // 여행지의 수와 계획한 여행지의 수 입력
    cin >> N >> M;

    // 부모 테이블 초기화(부모를 자기 자신으로)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // 여행지들의 경로 정보 입력받아서 경로가 연결되어 있다면 한 그룹으로 묶음
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> path;

            if(path == 1)
            {
                union_parent(i, j);
            }
        }
    }

    // 여행 계획 정보 입력
    for(int i = 0; i < M; i++)
    {
        cin >> trip;
        plan.push_back(trip);
    }

    // 여행 계획에 있는 여행지들의 부모 노드를 비교
    for(int i = 0; i < (M - 1); i++)
    {
        // 여행지들의 부모 노드가 다르다면 연결되어 있지 않으므로 가능 flag를 false로 바꿈
        if(find_parent(plan[i]) != find_parent(plan[i + 1]))
        {
            flag = false;
        }
    }

    // 출력
    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}