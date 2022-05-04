#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N;
    int K;
    int num;
    int cnt = 0;
    vector<int> coin;

    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        coin.push_back(num);
    }

    int idx = coin.size();
    
    // ���� ū ������ �������� �����鼭 �� ���� ������ ��, �������� ���� �ݾ����� ���
    while(idx != 0)
    {
        cnt += (K / coin[idx -1]);
        K %= coin[idx - 1];
        idx--;
    }

    cout << cnt << endl;
}