#include<iostream>

using namespace std;

int main() {

    int N;
    int res = -1;
    int offset = 0;

    cin >> N;

    while(N >= 0)
    {
        // 5kg �������� ������ �������� ���� ���� ��
        if((N % 5) == 0)
        {
            res = (N / 5) + offset;
            break;
        }
        
        // �� ���Կ��� 3kg�� ���ܽ�Ű��, offset(3kg ������ ��) ����
        N -= 3;
        offset++;
    }

    cout << res << endl;
}