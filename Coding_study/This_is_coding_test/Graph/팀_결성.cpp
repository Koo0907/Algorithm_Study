#include<iostream>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int op = 0;
int x = 0;
int y = 0;

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

    // M번 연산 수행
    for(int i = 0; i < M; i++)
    {
        // 입력
        cin >> op >> x >> y;

        // op가 0이라면 '팀 합치기' 함수 수행
        if(op == 0)
        {
            union_parent(x, y);
        }
        // op가 0이 아니라면 '같은 팀 여부 확인' 함수 수행
        else
        {
            // 두 값의 루트노드가 같다면(같은 팀이라면) 'YES' 출력 
            if(find_parent(x) == find_parent(y))
            {
                cout << "YES" << endl;
            }
            // 두 값의 루트노드가 다르다면 'NO' 출력
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}