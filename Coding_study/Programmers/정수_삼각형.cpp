/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43105 */
#include <string>
#include <vector>

#define MAX 500

using namespace std;

// dp ���̺� ����
int memo[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // �־��� triangle�� ����
    int height = triangle.size();
    
    // �� ���� ���� dp ���̺� ���� ����
    memo[0][0] = triangle[0][0];
    
    // �ι�° �� ���� ��ȸ
    for(int i = 1; i < height; i++)
    {
        // �� ������ ���� ����� ���� �ϳ��̹Ƿ� dp ���̺� ����
        memo[i][0] = memo[i - 1][0] + triangle[i][0];
        
        // �ﰢ�� ������ ������ �� ���� �ٿ��� ������ �� �ִ� ��찡 �ΰ��� �����Ƿ�, �� �߿��� ū ���� �̿��Ͽ� dp ���̺� ����
        for(int j = 1; j < i; j++)
        {
            memo[i][j] = max(memo[i - 1][j - 1], memo[i - 1][j]) + triangle[i][j];
        }
        
        // �� ������ ���� ����� ���� �ϳ��̹Ƿ� dp ���̺� ����
        memo[i][i] = memo[i - 1][i - 1] + triangle[i][i];
    }
    
    // ������ �� ��ȸ�� ���� index ����
    int last_line = height - 1;
    
    // ������ �ٸ� ��ȸ
    for(int i = 0; i < triangle[last_line].size(); i++)
    {
        // ������ �ٿ��� �ִ밪�� answer�� ����
        answer = max(answer, memo[last_line][i]);
    }
    
    return answer;
}