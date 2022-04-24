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

    // 내림차순 정렬
    sort(arr.begin(), arr.end(), greater<int>());
    
    // 가장 큰 수와 다음 큰 수 사용
    fir_val = arr[0];
    sec_val = arr[1];

    for(int i = 0; i < M; i++)
    {
        if(conti >= K)  // K번 연속했다면 두 번째 큰수 연산
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