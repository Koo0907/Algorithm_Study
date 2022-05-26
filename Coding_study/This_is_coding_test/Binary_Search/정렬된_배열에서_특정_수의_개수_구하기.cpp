#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int x = 0;

vector<int> vec;

int Count_by_range(int target)
{
    // upper_bound 메서드는 세번째 파라미터 값을 초과하는 숫자가 처음 등장하는 index를 반환
    // lower_bound 메서드는 세번째 파라미터 값 이상의 숫자가 처음 등장하는 index를 반환
    vector<int>::iterator max = upper_bound(vec.begin(), vec.end(), target);
    vector<int>::iterator min = lower_bound(vec.begin(), vec.end(), target);

    return max - min;
}

int main()
{
    int res = 0;

    cin >> N >> x;

    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        vec.push_back(num);
    }

    res = Count_by_range(x);

    if(res == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
}