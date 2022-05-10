#include<iostream>

using namespace std;

int main() {
    
    int N;
    int K;
    int cnt = 0;
    int idx = 0;
    int temp = 0;

    cin >> N >> K;

    while(1)
    {
        temp = N % K;
        idx += temp;    // idx = -1 연산의 수 +1
        N -= temp;
        if (N < K)  // N이 K보다 클 때 cnt + (idx - 1) 계산
        {
            cnt += (idx - 1);
            break;
        }
        N /= K;
        cnt++;  // cnt = N / K 연산의 수
    }

    cout << cnt << endl;
}