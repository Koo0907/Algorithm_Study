#include<iostream>
#include<string>

using namespace std;

int main() {
    
    string str;
    int res = 0;

    cin >> str;
    res = str[0] - '0'; // ù ��° ���� �������� �ݺ��� ����
    
    for(int i = 1; i < str.length(); i++)
    {
        // ��ȸ�ϴ� ��, Ȥ�� ���� ��갪�� 2 �����̸� + ����
        if((str[i] == '0') || (str[i] == '1') || (res < 2))
        {
            res += (str[i] - '0');
        }
        // �� �̿ܿ��� * ����
        else
        {
            res *= (str[i] - '0');
        }
    }

    cout << res << endl;
}