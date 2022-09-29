#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int max_val = 0;
int cnt = 0;
int ans = 0;

// 보석의 데이터를 담는 벡터
vector<int> jewel;

int main()
{
    // N와 M 입력
    scanf("%d %d", &N, &M);

    // M만큼 보석의 수 입력
    for(int i = 0; i < M; i++)
    {
        // 임시 변수 선언
        int temp = 0;
        
        // 보석 수 입력
        scanf("%d", &temp);
        
        // 벡터 저장
        jewel.push_back(temp);

        // 가장 보석이 많은 수 갱신
        max_val = max(max_val, temp);
    }

    // 질투심의 최소값은 1
    int start = 1;

    // 질투심의 최대값은 가장 많은 수의 보석
    int end = max_val;

    while(start <= end)
    {
        // 질투심은 이분 탐색으로 설정
        int mid = (start + end) / 2;

        // cnt 값 초기화
        cnt = 0;

        // 보석의 수만큼 순회
        for(int i = 0; i < jewel.size(); i++)
        {
            // 순회중인 색의 보석을 질투심으로 나눈 몫이 해당 보석을 줄 수 있는 학생의 수를 의미
            cnt += (jewel[i] / mid);

            // 순회중인 색의 보석을 질투심으로 나눈 나머지만큼 한 명에 학생에게 줄 수 있으므로 cnt 증가
            if((jewel[i] % mid) != 0)
            {
                cnt++;
            }
        }

        // 구한 cnt 값이 N보다 크다면 질투심을 너무 작게 설정했다는 뜻이므로 범위를 증가시킴
        if(cnt > N)
        {
            start = mid + 1;
        }
        // 구한 cnt 값이 N보다 작거나 같다면 조건을 만족하므로 현재 질투심을 저장하고 질투심을 작게하여 확인해봐야 하므로 범위를 감소시킴
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    // 최종적으로 저장된 질투심 출력
    printf("%d\n", ans);
}
