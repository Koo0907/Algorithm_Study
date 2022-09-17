#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int cnt = 0;
int max_val = 0;

// 컴퓨터들의 신뢰도 데이터를 담는 벡터
vector<int> vec[MAX];

// 결과 벡터
vector<int> ans;

// 방문 처리를 위한 배열
bool visited[MAX];

// DFS 함수 호출
int dfs(int node)
{
    // 해당 노드 방문 처리
    visited[node] = true;

    // 해킹한 컴퓨터 수 증가
    cnt++;

    // 해당 노드와 신뢰하는 관계인 컴퓨터들 순회
    for(int i = 0; i < vec[node].size(); i++)
    {
        // 다음 노드 갱신
        int next_node = vec[node][i];

        // 다음 노드을 아직 방문하지 않았다면 DFS 함수 호출
        if(visited[next_node] == false)
        {
            dfs(next_node);
        }
    }

    // 해킹한 컴퓨터 수 반환
    return cnt;
}

int main()
{
    // 컴퓨터 수, 신뢰 데이터 수 입력
    scanf("%d %d", &N, &M);

    // 컴퓨터들의 신뢰도 데이터 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d",&a, &b);
        // 단방향임을 주의

        vec[b].push_back(a);
    }

    // 모든 컴퓨터들 순회
    for(int i = 1; i <= N; i++)
    {
        // 방문 처리 배열 초기화
        fill(visited, visited + MAX, false);

        // 해킹한 컴퓨터 수 초기호
        cnt = 0;

        // i번 컴퓨터를 통해 해킹할 수 있는 컴퓨터의 수 반환
        int res = dfs(i);

        // res 값이 지금까지 계산에서의 최대값보다 크다면 아래 로직 수행
        if(res > max_val)
        {
            // 결과 벡터 초기화
            ans.clear();

            // 최대값 갱신
            max_val = res;

            // 결과 벡터에 값 추가
            ans.push_back(i);
        }
        // res 값이 지금까지 계산에서의 최대값과 같다면 아래 로직 수행
        else if(res == max_val)
        {
            // 결과 벡터에 추가
            ans.push_back(i);
        }
        // 그 외에 경우는 pass
        else
        {
            /// do nothing...
        }
    }

    // 결과 벡터 오름차순 정렬
    sort(ans.begin(), ans.end());

    // 결과 벡터 출력
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%d\n", ans[i]);
    }
}