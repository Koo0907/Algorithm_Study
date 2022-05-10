#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int solution(string s);

int main() {

    string str;

    cin >> str;

    cout << solution(str) << endl;
}
int solution(string s) {

    // 초기 answer 값은 s의 size
    int answer = s.size();
    
    // 1부터 s의 절반 사이즈의 길이까지 step 별로 확인
    for(int step = 1; step <= (s.size() / 2); step++)
    {
        string compare_str = "";
        
        // step별로 기준이 되는 문자열
        string stand_str = s.substr(0,step);
        int cnt = 1;

        // step 만큼 i 증가
        for(int i = step; i < s.size(); i += step)
        {
            // 기준 문자열이 연속으로 있다면 cnt 증가
            if(stand_str == s.substr(i, step))
            {
                cnt++;
            }
            // 기준 문자열이 연속으로 없다면 cnt 값을 보고 비교 문자열에 append (cnt가 1인 경우는 숫자 생략)
            else
            {
                if(cnt >= 2)
                {
                    compare_str = compare_str + to_string(cnt) + stand_str;
                }
                else
                {
                    compare_str = compare_str + stand_str;
                }
                
                // 기준 문자열 갱신하고 이어서 순회
                stand_str = s.substr(i,step);
                // cnt는 1로 초기화
                cnt = 1;
            }
        }

        // step 별로 순회가 끝났으면 나머지 문자열에 대해서 비교 문자열에 append
        if(cnt >= 2)
        {
            compare_str = compare_str + to_string(cnt) + stand_str;
        }
        else
        {
            compare_str = compare_str + stand_str;
        }

        // answer 값과 비교 문자열의 size 값 비교하여 작은 값으로 answer 갱신
        answer = min(answer, (int)compare_str.size());
    }

    return answer;
}