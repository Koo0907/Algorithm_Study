#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

    int N;
    int step = 0;
    int idx = 0;
    int score = 0;
    string ox;
    vector<int> v;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ox;

        // 문자열 끝까지 순회
        while(ox[step] != '\0')
        {
            if(ox[step] == 'O')
            {
                // 기존 점수와 누적 점수 합산
                idx++;
                score += idx;
            }
            else
            {
                // 누적 점수 초기화
                idx = 0;
            }
            step++;
        }
        // vector에 점수 추가 후 사용한 변수들 초기화
        v.push_back(score);
        idx = 0;
        step = 0;
        score = 0;
    }

    // 추가한 점수들 출력
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << endl;
    }

}