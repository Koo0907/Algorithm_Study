#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int g = 0;
int p = 0;
int p_num = 0;
int root = 0;
int res = 0;

// 부모 테이블
int parent[100001];

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
    // 탑승구와 비행기 정보 입력
    cin >> g >> p;

    // 부모 테이블 초기화(부모를 자기 자신으로)
    for(int i = 1; i <= g; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < p; i++)
    {
        cin >> p_num;

        // 현재 비행기의 탑승구의 부모 노드 확인
        root = find_parent(p_num);

        // 부모 노드가 0이라면 더이상 도킹이 불가능하므로 공항 운행 중지
        if(find_parent(root) == 0)
        {
            break;
        }

        // 부모 노드가 0이 아니라면 바로 왼쪽의 집합과 합치기
        union_parent(root, root - 1);
        res++;
    }

    cout << res << endl;
}