/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/49191 */
#include <string>
#include <vector>

// ������ �ǹ��ϴ� INF ����
#define INF 1e9

using namespace std;

// �������� ��� ����� ��� ��
int map[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    // ��� ��� �� INF�� �ʱ�ȭ
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            map[i][j] = INF;
        }
    }
    
    // ��� ��� �����͸� ��� ��� �ʿ� ����
    for(int i = 0; i < results.size(); i++)
    {
        int x = results[i][0];
        int y = results[i][1];
        
        map[x][y] = 1;
    }
    
    // �÷��̵� �ͼ� �˰��� ����
    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    
    // �� �ึ�� ��ȸ(��� �������� ��ȸ)
    for(int i = 1; i <= n; i++)
    {
        int cnt = 0;
        
        // �� ���� ��ȸ
        for(int j = 1; j <= n; j++)
        {
            //��� ���� ����� Ȯ���ص� INF(��� ����� ���ٴ� ��)�� ���ٸ� ������ �� �� ����
            if(map[i][j] != INF || map[j][i] != INF)
            {
                // �� ������ ������ �� �� �����Ƿ� cnt ����
                cnt++;
            }
        }
        
        // �� ������ ���ؼ� ������� ��� ��ȸ�ϰ� cnt ���� ������ ������ ������ �������� ���� ���ٸ� ������ �ű� �� ����
        if(cnt == n - 1)
        {
            // answer ����
            answer++;
        }
    }
    
    return answer;
}