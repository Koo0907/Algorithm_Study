/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/49189 */
#include <string>
#include <vector>
#include <queue>

#define MAX 20001

using namespace std;

// 노드와 간선의 연결리스트를 담는 벡터
vector<int> v[MAX];

// 노드의 방문 처리를 위한 배열
bool visited[MAX];

// 노드의 경로를 담는 배열
int node_val[MAX];

// 1번 노드에서부터 가장 먼 노드까지의 경로
int max_val = 0;

// 1번 노드에서부터 가장 먼 노드들의 수
int cnt = 0;

// BFS 함수 호출
void bfs(int x)
{
    // 큐 선언
    queue<int> q;
    
    // 파라미터 노드 방문 처리
    visited[x] = true;
    
    // 파라미터 노드 경로는 0으로 갱신
    node_val[x] = 0;
    
    // 파라미터 노드 큐에 추가
    q.push(x);
    
    // 큐가 빌 때까지 순회
    while(!q.empty())
    {
        // 큐에서 노드 추출 및 삭제
        x = q.front();
        q.pop();
        
        // 순회하는 노드에 연결되어 있는 모든 노드 순회
        for(int i = 0; i < v[x].size(); i++)
        {
            int next_x = v[x][i];
            
            // 다음 노드를 아직 방문하지 않았다면 아래 로직 수행
            if(visited[next_x] == false)
            {
                // 다음 노드 방문 처리
                visited[next_x] = true;
                
                // 다음 노드까지의 경로 갱신
                node_val[next_x] = node_val[x] + 1;
                
                // 1번 노드에서부터 가장 먼 경로 갱신
                max_val = max(max_val, node_val[next_x]);
                
                // 다음 노드 큐에 추가
                q.push(next_x);
            }
        }
    } 
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++)
    {
        // 양방향임을 주의하며 벡터에 추가
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    // BFS 함수 호출
    bfs(1);
    
    // 모든 노드 순회
    for(int i = 1; i <= n; i++)
    {
        // 1번 노드에서부터 가장 먼 경로를 가진 노드들의 수 갱신
        if(node_val[i] == max_val)
        {
            cnt++;
        }
    }
    
    // answer에 대입 및 출력
    answer = cnt;
    
    return answer;
}