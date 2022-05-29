#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> M >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 정렬을 해도 풀기에는 무방
    sort(vec.begin(), vec.end());

    // 사용할 최소값은 1
    int start = 1;

    // 사용할 최대값은 가장 긴 과자 길이
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;

        for(int i = 0; i < N; i++)
        {
            // 순회하는 과자를 mid 기준으로 나눴을때 몫(과자를 줄 수 있는 조카의 수와 동일)을 누적 증가
            cnt += (vec[i] / mid);
        }

        // 계산한 몫이 조카의 수보다 작다면 과자의 길이 기준이 길었다는 뜻이므로 범위를 감소
        if(cnt < M)
        {
            end = mid - 1;
        }
        // 계산한 몫이 조카의 수보다 같거나 크다면 길이를 늘려서 확인해봐야하므로 현재 mdi 값은 저장하고 범위를 증가
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}