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
        // ���ĺ� �빮�ڶ�� vector v�� �߰�
        if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            v.push_back(str[i]);
        }
        // ���ڰ� �ѹ��̶� ���Դٸ� flag set�ϰ� �� ���
        else
        {
            if(flag == 0)
            {
                flag = 1;
            }
            n += (str[i] - '0');
        }
    }
   
    // ���ĺ� �빮�� �������� ����
    sort(v.begin(), v.end());

    // ���ĺ� �빮�� ���
    for(vector<char>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr;
    }

    // �ջ� �� ���
    if(flag == 1)
    {
        cout << n;
    }
}