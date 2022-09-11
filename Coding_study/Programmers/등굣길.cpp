/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/42898 */
#include <string>
#include <vector>

// ���� �ִ� ũ��
#define MAX 101

using namespace std;

// modular ��
int div_num = 1000000007;

// dp ���̺�
int dp[MAX][MAX];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    // ������ ��ǥ Ȯ��
    for(int i = 0; i < puddles.size(); i++)
    {
        int x = puddles[i][0];
        int y = puddles[i][1];
        
        // ������ ��ǥ�� ���� -1�� ����
        dp[y][x] = -1;
    }
    
    // ���� �ִ� ��ġ�� 1�� ����
    dp[1][1] = 1;
    
    // �� ��ü ��ȸ
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            // ��ȸ�ϴ� ������ �����̰� �ƴ϶�� �Ʒ� ���� ����
            if(dp[i][j] != -1)
            {
                // �ӽ� ���� ����
                int a = 0;
                int b = 0;
                
                // ��ȸ�ϴ� ������ ���� ������ �����̰� �ƴ��� Ȯ��
                if(dp[i-1][j] != -1)
                {
                    a = dp[i-1][j]; 
                }
                
                // ��ȸ�ϴ� ������ ���� ������ �����̰� �ƴ��� Ȯ��
                if(dp[i][j-1] != -1)
                {
                    b = dp[i][j-1];
                }
                
                // ��ȸ�ϴ� ���� ����
                dp[i][j] += ((a + b) % div_num);
            }
        }
    }
    
    // �б� ��ǥ�� �� ����
    answer = dp[n][m];
    
    return answer;
}