/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/1844 */
#include<vector>
#include<queue>
using namespace std;

// ��,��,��,�� ���� ����
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// ��ǥ ť ����
queue<pair<int, int>> q;

// �湮 ó���� ���� �迭
bool visited[100][100] = {false};

void bfs(int x, int y, vector<vector<int>> &maps)
{
    // X���� ���̿� Y���� ����
    int axis_x = maps.size();
    int axis_y = maps[0].size();
    
	// �Ķ���� ��ǥ �湮 ó��
    visited[x][y] = true;
    
	// �Ķ���� ��ǥ ť�� �߰�
    q.push({x, y});
    
	// ť�� �� ������ �ݺ�
    while(!q.empty())
    {
		// ť���� ��ǥ ������ ���� �� ����
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
		// ��,��,��,�� �� ���� Ȯ��
        for(int i = 0; i < 4; i++)
        {
			// ���� ��ǥ ����
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            
			// ���� ��ǥ�� �� �� �ִ��� Ȯ��
            if((next_x >= 0 ) && (next_x < axis_x) && (next_y >= 0) && (next_y < axis_y))
            {
				// ���� ��ǥ�� ���� 1�̰� ���� �湮���� �ʾҴ��� Ȯ��
                if((maps[next_x][next_y] == 1) && (visited[next_x][next_y] == false))
                {
					// ���� ��ǥ �湮 ó��
                    visited[next_x][next_y] = true;

					// ���� ��ǥ �� ����
                    maps[next_x][next_y] = maps[x][y] + 1;

					// ���� ��ǥ ť�� �߰�
                    q.push({next_x, next_y});
                }
            }
        }
    }
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;
    
	// X���� ���̿� Y���� ����
    int axis_x = maps.size();
    int axis_y = maps[0].size();
    
	// BFS �Լ� ����
    bfs(0,0, maps);
    
	// ������ ������ �湮�ߴ��� Ȯ�� �� ���
    if(visited[axis_x - 1][axis_y - 1] == false)
    {
        answer = -1;
    }
    else
    {
        answer = maps[axis_x - 1][axis_y - 1];
    }
    
    return answer;
}