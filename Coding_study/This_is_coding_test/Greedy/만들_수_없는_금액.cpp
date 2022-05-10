#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int N;
    int x;
    int res = 1;
    vector<int> arr;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    // 오름차순 정렬
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++)
    {
        // 확인해야하는 수가 다음에 순회하는 수보다 작다면 그 수는 만들어 질 수 없음
        // ex. 3,2,1,1,9
        // 오름차순 정렬 : 1,1,2,3,9
        // [1] -> 1 조합 가능
        // [1,1] -> 2 조합 가능
        // [1,1,2] -> 3,4 조합 가능
        // [1,1,2,3] -> 5,6,7 조합 가능
        // [1,1,2,3,9] -> 순회하는 9가 확인해야하는 수(8)보다 크므로 8은 조합 불가능
        if(res < arr[i])
        {
            break;
        }
        res += arr[i];
    }

   cout << res << endl;
}