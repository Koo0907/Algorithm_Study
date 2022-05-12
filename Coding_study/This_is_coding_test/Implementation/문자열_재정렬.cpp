#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    string str;
    vector<char> v;
    int n = 0;
    char flag = 0;

    cin >> str;

    for(int i = 0; i < str.size(); i++)
    {
        // 알파벳 대문자라면 vector v에 추가
        if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            v.push_back(str[i]);
        }
        // 숫자가 한번이라도 나왔다면 flag set하고 합 계산
        else
        {
            if(flag == 0)
            {
                flag = 1;
            }
            n += (str[i] - '0');
        }
    }
   
    // 알파벳 대문자 오름차순 정렬
    sort(v.begin(), v.end());

    // 알파벳 대문자 출력
    for(vector<char>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr;
    }

    // 합산 값 출력
    if(flag == 1)
    {
        cout << n;
    }
}