#include<iostream>
#include<string>
#include<stack>

using namespace std;

// 결과 string 초기화
string res = "";

// stack에 쌓아 놓은 데이터 모두 결과 string에 append하는 함수
void print_stack(stack<char> &st)
{
    while(!st.empty())
    {
        res += st.top();
        st.pop();
    }
}
int main() {

    string str;
    stack<char> st;
    bool flag = 0;

    getline(cin, str);

    for(int i = 0; i < str.size(); i++)
    {
        // '<'인 경우에는 보호 flag set 해주고 stack의 데이터 모두 결과 string에 append
        if(str[i] == '<')
        {
            flag = 1;
            print_stack(st);
            res += str[i];
        }
        // '>'인 경우에는 보호 flag clear 해주고 stack의 데이터 모두 결과 string에 append
        else if(str[i] == '>')
        {
            flag = 0;
            print_stack(st);
            res += str[i];
        }
        // ' '인 경우에는 stack의 데이터 모두 결과 string에 append
        else if(str[i] == ' ')
        {
            print_stack(st);
            res += str[i];
        }
        // 그 이외의 문자인 경우에는 보호 flag set 되어 있다면 그대로 결과 string에 append, 보호 flag clear 되어 있다면 stack에 데이터 push
        else
        {
            if(flag)
            {
                res += str[i];
            }
            else
            {
                st.push(str[i]);
            }
        }
    }

    // 순회를 다 끝내고 stack의 데이터 모두 결과 string에 append
    print_stack(st);

    cout << res << endl;
}