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
        // ���ڰ� ���ڰ� �ƴ϶�� ���ݱ��� ���� ���ڸ� ���
        if(str[i] == '-' || str[i] == '+' || i == str.size())
        {
            // '-' ���ڰ� �ѹ��̶� ���Դٸ� ����
            if(flag)
            {
                res = res - stoi(num);
                num = "";
            }
            // '-' ���ڰ� ���� ������ �ʾҴٸ� ����
            else
            {
                res = res + stoi(num);
                num = "";
            }
        }
        // ���ڰ� ���ڶ�� string�� append
        else
        {
            num += str[i];
        }

        // '-' ���ڰ� ���Դٸ� flag set
        if(str[i] == '-')
        {
            flag = 1;
        }
    }

    cout << res << endl;
}