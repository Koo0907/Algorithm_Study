#include<iostream>
#include<string>

using namespace std;

int main() {
    
    string str;
    int res = 0;

    cin >> str;
    res = str[0] - '0'; // 첫 번째 값을 기준으로 반복문 시작
    
    for(int i = 1; i < str.length(); i++)
    {
        // 순회하는 값, 혹은 현재 계산값이 2 이하이면 + 연산
        if((str[i] == '0') || (str[i] == '1') || (res < 2))
        {
            res += (str[i] - '0');
        }
        // 그 이외에는 * 연산
        else
        {
            res *= (str[i] - '0');
        }
    }

    cout << res << endl;
}