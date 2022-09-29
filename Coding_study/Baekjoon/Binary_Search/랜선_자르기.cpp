#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// 사용할 변수 초기화
int K = 0;
int N = 0;
int len = 0;
int ans = 0;

// 이미 가지고 있는 랜선 길이를 담는 벡터
vector<int> Lan_line;

int main()
{
    // K와 N 입력
    scanf("%d %d", &K, &N);

    // K만큼 가지고 있는 랜선 길이 입력
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &len);
        Lan_line.push_back(len);
    }

    // 랜선 길이의 최소값은 0
    long long start = 0;

    // 랜선 길이의 최대값은 2^31 - 1
    long long end = pow(2, 31) - 1;

    while(start <= end)
    {
        // 랜선 길이의 값은 이분 탐색으로 설정
        long long mid = (start + end) / 2;

        // 만들어지는 랜선 수 초기화
        int total = 0;

        // 가지고 있는 랜선 순회
        for(int i = 0; i < Lan_line.size(); i++)
        {
            // 가지고 있는 랜선에서 새로 만들 수 있는 랜선의 수만큼 누적
            total += (Lan_line[i] / mid);
        }

        // 새로 만들 수 있는 랜선의 수가 N보다 작다면 랜선 길이를 너무 크게 설정했다는 뜻이므로 범위를 감소시킴
        if(total < N)
        {
            end = mid - 1;
        }
        // 새로 만들 수 있는 랜선의 수가 N보다 같거나 크다면 조건을 만족하므로 현재 랜선 길이를 저장하고 랜선 길이를 짧게하여 확인해봐야 하므로 범위를 증가시킴
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    // 최종적으로 저장된 랜선 길이 출력
    printf("%d\n", ans);
}
