/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/86491 */
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    // 가로 길이
    int width = 0;
    
    // 세로 길이
    int height = 0;
    
    // 명함 수
    int len = sizes.size();
    
    // 모든 명함 순회
    for(int i = 0; i < len; i++)
    {
        // 순회중인 명함이 가로길이가 세로길이보다 긴 경우
        if(sizes[i][0] > sizes[i][1])
        {
            width = max(width, sizes[i][0]);
            height = max(height, sizes[i][1]);
        }
        // 순회중인 명함이 세로길이가 가로길이보다 긴 경우
        else
        {
            width = max(width, sizes[i][1]);
            height = max(height, sizes[i][0]);
        }
    }
    
    // 가장 큰 세로길이와 가로길이의 곱을 answer 변수에 대입
    answer = width * height;
    
    return answer;
}