#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int N;
    int res = 0;
    vector<int> arr;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    // ATM 이용 시간 오름차순 정렬
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            res += arr[j];  // 2중 반복 이용해서 누적 시간 계산
        }
    }

    cout << res << endl;
}