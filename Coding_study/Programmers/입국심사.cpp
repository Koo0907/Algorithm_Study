/* ���α׷��ӽ� */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43238 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    // �Ա��ɻ� �ð� ���� �������� ����
    sort(times.begin(), times.end());
    
    long long answer;
    
    // �ּ� �ð��� 1��
    long long start = 1;
    
    // �ִ� �ð��� ��� �ο����� ���� ���� �ɸ��� �Ա��ɻ縦 �޴� ���
    // times ���ʹ� int���̹Ƿ� long long ����ȯ ����� ��
    long long end = (long long)times.back() * n;
    
    // start�� end�� �̺�Ž�� ��
    long long mid = 0;
    
    // ������ �ð� �ȿ� �Ա��ɻ縦 �Ϸ��� �� �ִ� ����� ��
    long long res = 0;
    
    // answer�� �ʱⰪ�� ���� ���� �ɸ��� �ִ� �ð����� ����
    answer = end;
    
    while(start <= end)
    {
        // �̺� Ž��
        mid = (start + end) / 2;
        
        // ���� �ʱ�ȭ
        res = 0;
        
        // �Ա� �ɻ� ���� ��ȸ
        for(int i = 0; i < times.size(); i++)
        {
            // mid �ð� ���� �� �ɻ���鿡�� �Ա��ɻ縦 ��ĥ �� �ִ� ����� ���� ����
            res += (mid / times[i]);
        }
        
        // ����� ���� n���� ���ٸ� ������ �ð��� �����ߴٴ� �ǹ��̹Ƿ� start ���� ����
        if(res < n)
        {
            start = mid + 1;
        }
        // ����� ���� n��� ���ų� ũ�ٸ� ������ �ð����� ����ߴٴ� �ǹ��̹Ƿ� ���� ���� �ð��� �����ϰ� end ���� ����
        else
        {
            // ������ �ð��� answer ������ ���� ��쿡 ����
            // �׷��� �� ���ǹ��� ��� ������ ������ ����
            if(mid < answer)
            {
                answer = mid;
            }
            end = mid - 1;
        }
    }
    return answer;
}