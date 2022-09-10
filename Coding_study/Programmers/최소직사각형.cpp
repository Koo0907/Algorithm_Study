/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/86491 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    // ���� ����
    int width = 0;
    
    // ���� ����
    int height = 0;
    
    // ���� ��
    int len = sizes.size();
    
    // ��� ���� ��ȸ
    for(int i = 0; i < len; i++)
    {
        // ��ȸ���� ������ ���α��̰� ���α��̺��� �� ���
        if(sizes[i][0] > sizes[i][1])
        {
            width = max(width, sizes[i][0]);
            height = max(height, sizes[i][1]);
        }
        // ��ȸ���� ������ ���α��̰� ���α��̺��� �� ���
        else
        {
            width = max(width, sizes[i][1]);
            height = max(height, sizes[i][0]);
        }
    }
    
    // ���� ū ���α��̿� ���α����� ���� answer ������ ����
    answer = width * height;
    
    return answer;
}