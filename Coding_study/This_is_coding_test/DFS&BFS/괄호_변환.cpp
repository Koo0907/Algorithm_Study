#include<iostream>
#include<string>

using namespace std;

// u 문자열이 올바른 괄호 문자열인지 확인하는 함수
bool check_u(string u)
{
    int idx = 0;
    int n1 = 0;
    int n2 = 0;

    while(idx < u.length())
    {
        if(u[idx] == '(')
        {
            n1++;
        }
        else if(u[idx] == ')')
        {
            n2++;
        }

        if(n2 > n1)
        {
            return false;
        }

        idx++;
    }
    return true;
}

string solution(string p)
{
    string answer = "";
    string u = "";
    string v = "";
    int idx = 0;
    int n1 = 0;
    int n2 = 0;
    
    // 인자 p 문자열이 ""이라면 그대로 반환
    if(p == "")
    {
        return "";
    }

    // 인자 p 문자열을 u 문자열과 v 문자열로 분리
    while(idx < p.length())
    {
        u += p[idx];

        if(u[idx] == '(')
        {
            n1++;
        }
        else if(u[idx] == ')')
        {
            n2++;
        }

        if(n1 == n2)
        {
            v = p.substr(u.length());
            break;
        }

        idx++;
    }

    // u 문자열이 올바른 괄호 문자열인지 확인
    if(check_u(u))
    {
        // u 문자열이 올바른 괄호 문자열이라면 v 문자열에 대해서 함수 재호출하고 append 후 반환
        u += solution(v);
        answer += u;
        return answer;
    }
    else
    {
        // u 문자열이 올바른 괄호 문자열이 아니라면 4-1 ~ 4-4 과정 수행 후 반환
        answer += '(';
        answer += solution(v);
        answer += ')';
        for(int i = 1; i < u.length() - 1; i++)
        {
            if(u[i] == '(')
            {
                answer += ')';
            }
            else if(u[i] == ')')
            {
                answer += '(';
            }
        }

        return answer;
    }
}

int main()
{
    string str;

    cin >> str;

    cout << solution(str) << endl;
}