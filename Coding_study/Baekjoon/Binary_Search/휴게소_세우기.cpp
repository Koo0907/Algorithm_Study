#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0; 
int L = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> M >> L;

    // 첫번째 위치(0) 추가
    vec.push_back(0);

    // 휴게소 설치
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 마지막 위치(L) 추가
    vec.push_back(L);

    // 오름차순 정렬
    sort(vec.begin(), vec.end());

    int start = 1;
    int end = L - 1;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0;
        for(int i = vec.size() - 1; i > 0; i--)
        {
            // 휴게소 끼리의 거리(+ 양 끝점과 휴게소의 거리)
            int len = vec[i] - vec[i - 1];

            // 두 휴게소 사이에 설치 가능한 휴게소의 개수
            sum += (len / mid);

            // % 연산으로 나머지가 없다면 휴게소의 위치가 중복이라는 의미이므로 휴게소의 개수 감소
            if(len % mid == 0)
            {
                sum--;
            }
        }

        // 설치한 휴게소가 M개보다 많다면 휴게소와의 거리를 늘림
        if(sum > M)
        {
            start = mid + 1;
        }
        // 설치한 휴게소가 M개보다 같거나 적다면 휴게소와의 거리를 줄임
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}