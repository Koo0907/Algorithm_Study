#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 50

using namespace std;

// 사용할 변수 초기화
int N = 0;
int total = 0;
int cnt = 0;
int ans = 0;

// 랜선 길이 데이터를 담는 벡터
vector<pair<int, pair<int, int>>> graph;

// 랜선 길이 데이터를 담는 배열
char map[MAX][MAX];

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

// 랜선 길이 변환 함수
int convert_value(char ch)
{
    // 랜선 길이가 소문자인 경우
    if((ch >= 'a') && (ch <= 'z'))
    {
        return ch - 'a' + 1;
    }
    // 랜선 길이가 대문자인 경우
    else if((ch >= 'A') && (ch <= 'Z'))
    {
        return ch - 'A' + 27;
    }
    // 랜선 길이가 0인 경우
    else
    {
        return 0;
    }
}

int main()
{
    // 방의 수 입력
    scanf("%d", &N);

    // 컴퓨터의 랜선 데이터 입력
    for(int i = 0; i < N; i++)
    {
        cin.ignore();
        for(int j = 0; j < N; j++)
        {
            scanf("%c", &map[i][j]);

            // 주어지는 랜선 길이를 모두 합산
            total += convert_value(map[i][j]);
        }
    }

    // 각 컴퓨터들에 대한 연결 유무 확인 및 최소 길이 갱신
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            // i와 j가 같은 경우거나, i번 컴퓨터와 j번 컴퓨터 사이의 랜선 길이가 모두 0으로 주어지는 경우는 제외
            if((i == j) || (map[i][j] == '0') && (map[j][i] == '0'))
            {
                continue;
            }

            // 랜선 길이 초기화
            int cost = 0;

            // i번 컴퓨터와 j번 컴퓨터의 랜선 길이가 모두 0이 아닌 경우에는 더 적은 랜선 길이를 선택
            if((map[i][j] != '0') && (map[j][i] != '0'))
            {
                cost = min(convert_value(map[i][j]), convert_value(map[j][i]));
            }
            // i번 컴퓨터에서 j번 컴퓨터까지의 랜선 길이가 0이지만, j번 컴퓨터에서 i번 컴퓨터까지의 랜선길이가 0이 아니라면 해당 랜선 길이를 선택
            else if((map[i][j] == '0') && (map[j][i] != '0'))
            {
                cost = convert_value(map[j][i]);
            }
            // j번 컴퓨터에서 i번 컴퓨터까지의 랜선 길이가 0이지만, i번 컴퓨터에서 j번 컴퓨터까지의 랜선길이가 0이 아니라면 해당 랜선 길이를 선택
            else
            {
                cost = convert_value(map[i][j]);
            }

            // 벡터에 선택한 랜선 길이와 두 컴퓨터 정보 삽입
            graph.push_back({cost, {i, j}}); 
        }
    }

    // 부모 테이블 초기화
    for(int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    // 랜선 길이 오름차순 정렬
    sort(graph.begin(), graph.end());

    // 벡터의 데이터 수 만큼 순회
    for(int i = 0; i < graph.size(); i++)
    {
        // a, b는 컴퓨터의 번호
        // lan은 두 컴퓨터를 연결하는 랜선 길이
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int lan = graph[i].first;

        // 순회하는 두 노드의 부모 노드가 다르다면(=cycle이 형성되지 않는다면) 아래 로직 수행
        if(find_parent(a) != find_parent(b))
        {
            // 두 노드 union 연산
            union_parent(a, b);

            // 간선 수 증가
            cnt++;

            // 총 랜선 길이 갱신
            ans += lan;
        }
    }

    // 간선의 수가 컴퓨터의 수보다 1 작다면 MST 성립
    if(cnt == N - 1)
    {
        // 전체 랜선 길이에서 MST에 사용되는 랜선 길이를 뺀 차이값 출력
        printf("%d\n", total - ans);   
    }
    else
    {
        // -1 출력
        printf("-1\n");
    }
}