#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
long long N = 0;
long long M = 0;
long long num = 0;
long long ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    // 최소 시간은 1, 최대 시간은 시간이 가장 오래 걸린 심사대 * 사람 수
    long long start = 1;
    long long end = vec.back() * M;

    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        
        // 계산된 시간에서 몇명이 입국심사를 볼 수 있는지 확인하면서 증가시킴
        for(int i = 0; i < N; i++)
        {
            sum += (mid / vec[i]);
        }

        // 계산한 사람의 수가 M명보다 작다면 계산한 시간이 부족했다는 의미이므로 시간 범위를 늘림
        if(sum < M)
        {
            start = mid + 1;
        }
        // 계산한 사람의 수가 M명보다 크다면 계산한 시간이 충분했다는 의미이므로 시간 범위를 줄임
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    
    cout << ans << endl;
}