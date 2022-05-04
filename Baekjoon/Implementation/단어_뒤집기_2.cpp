#include<iostream>
#include<string>
#include<stack>

using namespace std;

// ��� string �ʱ�ȭ
string res = "";

// stack�� �׾� ���� ������ ��� ��� string�� append�ϴ� �Լ�
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
        // '<'�� ��쿡�� ��ȣ flag set ���ְ� stack�� ������ ��� ��� string�� append
        if(str[i] == '<')
        {
            flag = 1;
            print_stack(st);
            res += str[i];
        }
        // '>'�� ��쿡�� ��ȣ flag clear ���ְ� stack�� ������ ��� ��� string�� append
        else if(str[i] == '>')
        {
            flag = 0;
            print_stack(st);
            res += str[i];
        }
        // ' '�� ��쿡�� stack�� ������ ��� ��� string�� append
        else if(str[i] == ' ')
        {
            print_stack(st);
            res += str[i];
        }
        // �� �̿��� ������ ��쿡�� ��ȣ flag set �Ǿ� �ִٸ� �״�� ��� string�� append, ��ȣ flag clear �Ǿ� �ִٸ� stack�� ������ push
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

    // ��ȸ�� �� ������ stack�� ������ ��� ��� string�� append
    print_stack(st);

    cout << res << endl;
}