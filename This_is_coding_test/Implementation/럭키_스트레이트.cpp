#include<iostream>
#include<string>

using namespace std;

int main() {

    string str;
    int sum1 = 0;
    int sum2 = 0;

    cin >> str;

    // 왼쪽 부분의 각 자릿수의 합
    for(int i = 0; i < (str.size() / 2); i++)
    {
        sum1 += (str[i] - '0');
    }

    // 오른쪽 부분의 각 자릿수의 합
    for(int i = (str.size() / 2); i < str.size(); i++)
    {
        sum2 += (str[i] - '0');
    }

    // 각 합들이 같은지 검사
    if(sum1 == sum2)
    {
        cout << "LUCKY" << endl;
    }
    else
    {
        cout << "READY" << endl;
    }
}