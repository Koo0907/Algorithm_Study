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
    int sum = 0;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        vec.push_back(num);
    }

    // 사용할 용돈의 최소값은 용돈 벡터의 최대값
    int start = *max_element(vec.begin(), vec.end());

    // 사용할 용돈의 최대값은 용돈 벡터 값들의 총합
    int end = sum;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 인출한 횟수는 1부터 시작
        int cnt = 1;
        int temp = 0;

        for(int i = 0; i < N; i++)
        {
            // 현재까지 계산된 temp 값과 다음날 사용할 용돈을 더한 값이 mid 값보다 여전히 작거나 같다면 계속해서 한번 인출한 돈으로 사용
            if(temp + vec[i] <= mid)
            {
                temp += vec[i];
            }
            // 현재까지 계산된 temp 값과 다음날 사용할 용돈을 더한 값이 mid 값보다 커지게 된다면 인출한 횟수를 증가시키고 새롭게 계산      
            else
            {
                cnt++;
                temp = vec[i];
            }
        }

        // 인출한 횟수가 입력받은 M 값보다 크다면 인출 금액을 너무 작게 잡은 것이므로 범위를 증가시킴
        if(cnt > M)
        {
            start = mid + 1;
        }
        // 인출한 횟수가 입력받은 M 값보다 같거나 작다면 인출 금액을 줄여서 확인할 필요가 있으므로 현재 금액을 저장하고 범위를 감소시킴
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}