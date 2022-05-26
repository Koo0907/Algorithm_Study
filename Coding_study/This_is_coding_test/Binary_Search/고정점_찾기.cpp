#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int num = 0;

vector<int> vec;

int binary_search(int start, int end)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 중앙값의 인덱스와 그 인덱스의 요소값이 같다면 해당 인덱스 반환
        if(mid == vec[mid])
        {
            return mid;
        }
        // 중앙값의 인덱스보다 그 인덱스의 요소값이 크다면 중앙값 기준으로 좌측에서 다시 탐색
        else if(mid < vec[mid])
        {
            end = mid - 1;
        }
        // 중앙값의 인덱스보다 그 인덱스의 요소값이 작다면 중앙값 기준으로 우측에서 다시 탐색
        else
        {
            start = mid + 1;
        }
    }

    // 해당 조건을 만족하는 수를 찾지 못하면 -1 반환
    return -1;
}

int main()
{
    int res = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 이진 탐색 함수 호출
    res = binary_search(0, vec.size() - 1);

    cout << res << endl;
}