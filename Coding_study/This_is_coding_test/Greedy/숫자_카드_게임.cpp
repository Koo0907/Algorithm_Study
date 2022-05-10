#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    
    int N;
    int M;
    int x;
    int min_val;
    int max_val = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        min_val = 10001;    // �� ���� ��ȸ�ϱ� ���� �ּҰ��� ���� �� ���� ū ���� �ʱ�ȭ
        for(int j = 0; j < M; j++)
        {
            cin >> x;
            if(min(min_val, x) < min_val)   // ���� �ּҰ��� �Է¹��� ���� ���Ͽ� �ּҰ� ����
            {
                min_val = x;
            }
        }
        max_val = max(max_val, min_val);    // �� ���� ��ȸ�� ��ģ �Ŀ� �ִ밪 ����
    }

    cout << max_val << endl;
}