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
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            res += arr[j];
        }
    }

    cout << res << endl;
}