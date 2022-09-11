/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/12913 */
#include <iostream>
#include <vector>

// ���� �ִ� ����
#define MAX 100000

using namespace std;

// dp ���̺�
int dp[MAX][4];

// ���� ū ���� ���ϱ� ���� ����
int max_val = 0;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    // ù��° ���� ���� �־��� land�� ������ ����
    for(int i = 0; i < land[0].size(); i++)
    {
        dp[0][i] = land[0][i];
    }
    
    // �ι�° ����� ��ȸ ����
    for(int i = 1; i < land.size(); i++)
    {
        // ���� �� ��ŭ ��ȸ
        for(int j = 0; j < land[i].size(); j++)
        {
            // �ӽ� ���� �ʱ�ȭ
            int temp_val = 0;
            
            // ���� ��ȸ���� ���� ���࿡�� ��ȸ
            for(int k = 0; k < land[i - 1].size(); k++)
            {
                // ���� ��ȸ���� ���� �ٸ� ���� ����
                if(k != j)
                {
                    // ���࿡���� ���� ū ���� ����
                    temp_val = max(temp_val, dp[i - 1][k]);
                }
            }
            
            // dp ���̺��� ���� ��ȸ���� ��ǥ�� ���� ����
            dp[i][j] = land[i][j] + temp_val;
            
            // dp ���̺��� �ִ밪 ����
            max_val = max(max_val, dp[i][j]);
        }
    }
    
    // dp ���̺����� �ִ밪 answer�� ����
    answer = max_val;

    return answer;
}