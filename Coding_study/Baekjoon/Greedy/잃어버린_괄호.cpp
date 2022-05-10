#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

    string str;
    string num = "";
    bool flag = 0;
    int res = 0;

    cin >> str;

    for(int i = 0; i <= str.size(); i++)
    {
        // 문자가 숫자가 아니라면 지금까지 만든 숫자를 계산
        if(str[i] == '-' || str[i] == '+' || i == str.size())
        {
            // '-' 문자가 한번이라도 나왔다면 뺄셈
            if(flag)
            {
                res = res - stoi(num);
                num = "";
            }
            // '-' 문자가 아직 나오지 않았다면 덧셈
            else
            {
                res = res + stoi(num);
                num = "";
            }
        }
        // 문자가 숫자라면 string에 append
        else
        {
            num += str[i];
        }

        // '-' 문자가 나왔다면 flag set
        if(str[i] == '-')
        {
            flag = 1;
        }
    }

    cout << res << endl;
}