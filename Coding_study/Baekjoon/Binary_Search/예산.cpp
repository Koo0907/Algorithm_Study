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
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    cin >> M;

    // 안해도 무방하지만 예산의 최대값을 구하기 위해 정렬
    sort(vec.begin(), vec.end());

    // 예산의 최소값은 0
    // 요구한 예산들을 총 예산으로 분배할 수 없는 경우에는 예산은 0이 나옴
    // 문제에서 따로 명시되어 있지 않아서 필자가 헤맸던 부분
    int start = 0;

    // 예산의 최대값은 현재 요구 예산 벡터의 가장 큰 값
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0;

        for(int i = 0; i < N; i++)
        {
            // 요구 예산이 설정한 예산보다 크다면 설정한 예산으로 계산
            if(vec[i] > mid)
            {
                sum += mid;
            }
            // 요구 예산이 설정한 예산보다 작거나 같다면 요구 예산으로 계산
            else
            {
                sum += vec[i];
            }
        }

        // 계산한 총 예산이 입력받은 M보다 크다면 예산을 너무 크게 잡은 것이므로 범위를 감소시킴
        if(sum > M)
        {
            end = mid - 1;
        }
        // 계산한 총 예산이 입력받은 M보다 작거나 같다면 예산을 늘려서 확인해야봐야 하므로 현재 값을 저장하고 범위를 증가시킴
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}