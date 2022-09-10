/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/49189 */
#include <string>
#include <vector>
#include <queue>

#define MAX 20001

using namespace std;

// ���� ������ ���Ḯ��Ʈ�� ��� ����
vector<int> v[MAX];

// ����� �湮 ó���� ���� �迭
bool visited[MAX];

// ����� ��θ� ��� �迭
int node_val[MAX];

// 1�� ��忡������ ���� �� �������� ���
int max_val = 0;

// 1�� ��忡������ ���� �� ������ ��
int cnt = 0;

// BFS �Լ� ȣ��
void bfs(int x)
{
    // ť ����
    queue<int> q;
    
    // �Ķ���� ��� �湮 ó��
    visited[x] = true;
    
    // �Ķ���� ��� ��δ� 0���� ����
    node_val[x] = 0;
    
    // �Ķ���� ��� ť�� �߰�
    q.push(x);
    
    // ť�� �� ������ ��ȸ
    while(!q.empty())
    {
        // ť���� ��� ���� �� ����
        x = q.front();
        q.pop();
        
        // ��ȸ�ϴ� ��忡 ����Ǿ� �ִ� ��� ��� ��ȸ
        for(int i = 0; i < v[x].size(); i++)
        {
            int next_x = v[x][i];
            
            // ���� ��带 ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
            if(visited[next_x] == false)
            {
                // ���� ��� �湮 ó��
                visited[next_x] = true;
                
                // ���� �������� ��� ����
                node_val[next_x] = node_val[x] + 1;
                
                // 1�� ��忡������ ���� �� ��� ����
                max_val = max(max_val, node_val[next_x]);
                
                // ���� ��� ť�� �߰�
                q.push(next_x);
            }
        }
    } 
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    for(int i = 0; i < edge.size(); i++)
    {
        // ��������� �����ϸ� ���Ϳ� �߰�
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }
    
    // BFS �Լ� ȣ��
    bfs(1);
    
    // ��� ��� ��ȸ
    for(int i = 1; i <= n; i++)
    {
        // 1�� ��忡������ ���� �� ��θ� ���� ������ �� ����
        if(node_val[i] == max_val)
        {
            cnt++;
        }
    }
    
    // answer�� ���� �� ���
    answer = cnt;
    
    return answer;
}