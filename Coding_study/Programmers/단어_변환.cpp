/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43163 */
#include <string>
#include <vector>

using namespace std;

// �湮 ó���� ���� �迭 ����
bool visited[50] = {false};

// ���ڿ� ��ȯ ��
int ret = 50;

// ��ȯ�� �� �ִ� ���ڿ����� �Ǵ��ϴ� �Լ�
bool check_one_char(string A, string B)
{
    char idx = 0;
    
    // A�� B�� ���ڿ��� ��
    for(int i = 0; i < A.size(); i++)
    {
        // �� ���ڿ��� ���ڰ� ���� ��츸 idx ����
        if(A[i] == B[i])
        {
            idx++;
        }
    }
    
    // idx ���� ���ڿ� ������ 1���� �۴ٸ� ��ȯ ����
    if(idx == A.size() - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// DFS ���� �Լ�
void dfs(string begin, string target, vector<string> words, int step)
{
    // ������� ��ȯ�� Ƚ�� �̹� ���� ���� ��ȯ�� Ƚ������ ũ�ٸ� Ž�� �ǹ̰� �����Ƿ� �Լ� ����
    if(ret <= step)
    {
        return;
    }
    
    // begin ���ڿ��� target ���ڿ��� ���� ��� �Ʒ� ���� ����
    if(begin == target)
    {
        // ������ ���� ���� ��ȯ�� Ƚ���� ���� ���� ��ȯ Ƚ�� �߿� �� ���������� ����
        ret = min(ret, step);
        return;
    }
    
    // words ���� ���̸�ŭ ��ȸ
    for(int i = 0; i < words.size(); i++)
    {
        // ��ȸ���� ���ڿ��� ��ȯ �����ϰ� ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
        if(check_one_char(begin, words[i]) && visited[i] == false)
        {
            // ��ȸ���� ���ڿ� �湮 ó��
            visited[i] = true;
            
            // ��ȯ�� ���ڿ��������� target ���ڿ��� Ž���ϰ� ��ȯ Ƚ�� 1 ������Ų �Ŀ� DFS �Լ� ȣ��
            dfs(words[i], target, words, step + 1);
            
            // DSF �Լ� ����Ǹ� �湮ó���� �ٽ� ��Ʈ��ŷ�Ͽ� ���Ŀ��� �ٽ� Ž���� �� �ֵ��� ��
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // DFS �Լ� ȣ��
    dfs(begin, target, words, 0);
    
    // ��� DFS �Լ� ȣ���� ���� �ڿ� ret ���� Ȯ��
	// ���� �ʱ�ȭ ���� �����ϴٸ� 0 ���
    if(ret == 50)
    {
        answer = 0;
    }
	// ���� ���ŵǾ��ٸ� ���ŵ� �� ���
    else
    {
        answer = ret;
    }
    
    return answer;
}