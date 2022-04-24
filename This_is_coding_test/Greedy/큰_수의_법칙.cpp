#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int N, M, K;
    int x;
    int fir_val;
    int sec_val;
    int res = 0;
    int conti = 0;
    vector<int> arr;

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    // �������� ����
    sort(arr.begin(), arr.end(), greater<int>());
    
    // ���� ū ���� ���� ū �� ���
    fir_val = arr[0];
    sec_val = arr[1];

    for(int i = 0; i < M; i++)
    {
        if(conti >= K)  // K�� �����ߴٸ� �� ��° ū�� ����
        {
            res += sec_val;
            conti = 0;
        }
        else
        {
            res += fir_val;
            conti++;
        }
    }

    cout << res << endl;
}