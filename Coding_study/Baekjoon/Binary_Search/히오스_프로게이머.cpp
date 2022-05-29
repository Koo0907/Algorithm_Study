#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int K = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> K;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 안해도 무방하지만 팀 레벨 최소값과 최대값을 구하기 위해 정렬
    sort(vec.begin(), vec.end());

    // 팀 레벨 최소값은 현재 레벨 벡터에서 가장 작은 값
    int start = vec.front();

    // 팀 레벨 최대값은 현재 레벨 벡터에서 가장 큰 값
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 팀 레벨과 현재 순회중인 레벨의 차이를 누적으로 더하는 sum 변수를 long long으로 선언해야 함
        long long sum = 0;

        for(int i = 0; i < N; i++)
        {
            // 현재 순회중인 레벨이 팀 레벨보다 작다면 아래 로직 수행
            if(vec[i] < mid)
            {
                // sum 변수에 설정한 팀 레벨과 현재 순회중인 레벨의 차를 누적으로 더함
                sum += (mid - vec[i]);
            }
        }

        // 계산한 레벨의 차를 누적으로 더한 값이 입력받은 K보다 크다면 팀 레벨 설정을 너무 크게 했다는 뜻이므로 범위를 감소시킴
        if(sum > K)
        {
            end = mid - 1;
        }
        // 계산한 레벨의 차를 누적으로 더한 값이 입력받은 K보다 같거나 작다면 팀 레벨을 조금 높혀서 확인해봐야 하므로 현재 값을 저장하고 범위를 증가시킴
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}