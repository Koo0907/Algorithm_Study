/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43238 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    
    // 입국심사 시간 벡터 오름차순 정렬
    sort(times.begin(), times.end());
    
    long long answer;
    
    // 최소 시간은 1분
    long long start = 1;
    
    // 최대 시간은 모든 인원들이 가장 오래 걸리는 입국심사를 받는 경우
    // times 벡터는 int형이므로 long long 형변환 해줘야 함
    long long end = (long long)times.back() * n;
    
    // start와 end의 이분탐색 값
    long long mid = 0;
    
    // 설정한 시간 안에 입국심사를 완료할 수 있는 사람의 수
    long long res = 0;
    
    // answer의 초기값은 가장 오래 걸리는 최대 시간으로 설정
    answer = end;
    
    while(start <= end)
    {
        // 이분 탐색
        mid = (start + end) / 2;
        
        // 변수 초기화
        res = 0;
        
        // 입국 심사 벡터 순회
        for(int i = 0; i < times.size(); i++)
        {
            // mid 시간 동안 각 심사관들에게 입국심사를 마칠 수 있는 사람의 수를 갱신
            res += (mid / times[i]);
        }
        
        // 사람의 수가 n명보다 적다면 설정한 시간이 부족했다는 의미이므로 start 값을 갱신
        if(res < n)
        {
            start = mid + 1;
        }
        // 사람의 수가 n명과 같거나 크다면 설정한 시간으로 충분했다는 의미이므로 현재 설정 시간을 저장하고 end 값을 갱신
        else
        {
            // 설정한 시간이 answer 값보다 작은 경우에 갱신
            // 그러나 이 조건문은 없어도 무방할 것으로 보임
            if(mid < answer)
            {
                answer = mid;
            }
            end = mid - 1;
        }
    }
    return answer;
}