#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // �������� ����
    sort(vec.begin(), vec.end());

    // N�� Ȧ���̸� ��� ��� ���
    // N�� ¦���̸� ��� ��ҿ��� �ϳ� �� ���� ��� ���
    if((N % 2) == 0)
    {
        cout << vec[(N / 2) - 1] << endl;
    }
    else
    {
        cout << vec[N / 2] << endl;
    }
}