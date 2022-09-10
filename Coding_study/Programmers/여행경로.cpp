/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43164 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �湮 ó���� ���� �迭
bool visited[10000];

// ���� ��� ����
vector<string> vec;

bool dfs(string now, vector<vector<string>> tickets, int depth)
{
	// dfs�� ����(���� ���)�� Ƽ���� ���� ���ٸ� ���� Ȯ���� ���̹Ƿ� true ��ȯ
    if(depth == tickets.size())
    {
        return true;
    }
    
	// Ƽ�� ���θ� Ȯ��
    for(int i = 0; i < tickets.size(); i++)
    {
		// Ƽ���� ��� ������ �Ķ���ͷ� ���� ���װ� ���� ���� �湮���� ���� Ƽ���̶�� �Ʒ� ���� ����
        if(tickets[i][0] == now && visited[i] == false)
        {
			// Ƽ�� �湮 ó��
            visited[i] = true;

			// Ƽ���� ���� ���� ���Ϳ� �߰�
            vec.push_back(tickets[i][1]);
			
			// Ƽ���� ���� ������ ��� �������� �����ϰ� Ȯ���� Ƽ�� ���� 1 ���� ������ DFS �Լ� ȣ��
            bool temp_res = dfs(tickets[i][1], tickets, depth + 1);

			// �������� DFS �Լ��� true��� ���� ��ΰ� Ƽ���� ��� Ȯ���ϱ� ���� ��Ű�� �ʾҴٴ� ���̹Ƿ� true ��ȯ
            if(temp_res == true)
            {
                return true;
            }
			// �������� DFS �Լ��� false��� ���� ��ΰ� Ƽ���� ��� Ȯ���ϱ� ���� ���״ٴ� �ǹ̹Ƿ� ���� Ȯ���� Ƽ���� �湮 ó�� ���
            else
            {
                visited[i] = false;
            }
        }
    }
    
	// Ƽ�� ���θ� Ȯ���ߴµ��� �Ķ���ͷ� ���� ��� ������ Ƽ���� ã�� ���� ��쿡�� ������ ���Ϳ� �߰��� ���� �����ϰ� false ��ȯ
    vec.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
	// Ƽ�� �������� ����
    sort(tickets.begin(), tickets.end());
    
	// ���� ���� ���Ϳ� �߰�
    vec.push_back("ICN");
    
	// DFS �Լ� ȣ��
    dfs("ICN", tickets, 0);
    
	// answer ���Ϳ� ���� ���� ����
    answer = vec;
    
    return answer;
}