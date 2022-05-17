#include<iostream>
#include<string>

using namespace std;

// u ���ڿ��� �ùٸ� ��ȣ ���ڿ����� Ȯ���ϴ� �Լ�
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
    
    // ���� p ���ڿ��� ""�̶�� �״�� ��ȯ
    if(p == "")
    {
        return "";
    }

    // ���� p ���ڿ��� u ���ڿ��� v ���ڿ��� �и�
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

    // u ���ڿ��� �ùٸ� ��ȣ ���ڿ����� Ȯ��
    if(check_u(u))
    {
        // u ���ڿ��� �ùٸ� ��ȣ ���ڿ��̶�� v ���ڿ��� ���ؼ� �Լ� ��ȣ���ϰ� append �� ��ȯ
        u += solution(v);
        answer += u;
        return answer;
    }
    else
    {
        // u ���ڿ��� �ùٸ� ��ȣ ���ڿ��� �ƴ϶�� 4-1 ~ 4-4 ���� ���� �� ��ȯ
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