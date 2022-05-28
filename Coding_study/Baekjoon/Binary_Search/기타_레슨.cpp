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
    // 블루레이 크기의 최대값을 구하기 위한 변수 선언
    int sum = 0;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        vec.push_back(num);
    }

    // 블루레이 크기의 최소값은 강의의 길이 중에 가장 큰 값
    // 그래야 적어도 한 블루레이에 모든 강의를 최소 하나씩 담을 수 있기 때문
    // 그런데 이진 탐색한다고 오름차순 정렬하면 안됌
    // 문제 조건에 '강의의 순서가 바뀌면 안 된다'라는 조건이 있음
    // 필자도 오름차순으로 자연스럽게 정렬해서 풀다가 몇 시간 헤맴
    int start = *max_element(vec.begin(), vec.end());

    // 블루레이 크기의 최대값은 모든 강의의 길이를 더한 값
    int end = sum;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 블루레이 개수는 1부터 시작
        int cnt = 1;
        int temp = 0;

        for(int i = 0; i < N; i++)
        {
            // 현재까지 계산된 temp 값과 다음 강의의 길이를 더한 값이 mid 값보다 여전히 작거나 같다면 계속해서 같은 블루레이에 추가 
            if(temp + vec[i] <= mid)
            {
                temp += vec[i];
            }
            // 현재까지 계산된 temp 값과 다음 강의의 길이를 더한 값이 mid 값보다 커지게 된다면 블루레이 개수를 증가시키고 새롭게 계산
            else
            {
                cnt++;
                temp = vec[i];
            }
        }

        // 블루레이 수가 입력받은 M 값보다 크다면 블루레이 크기를 너무 작게 잡은 것이므로 범위를 증가시킴
        if(cnt > M)
        {
            start = mid + 1;
        }
        // 블루레이 수가 입력받은 M 값보다 같거나 작다면 블루레이 크기를 한번 줄여서 확인할 필요가 있으므로 현재 크기를 저장하고 범위를 감소시킴
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}