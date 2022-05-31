#include<iostream>
#include<vector>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int num = 0;

vector<int> vec;

// 10001은 특정 금액을 만들 수 있는 화폐 구성이 가능하지 않다는 의미
vector<int> memo(10001, 10001);

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    memo[0] = 0;

    // Dynamic Programming 적용(Bottom-up 방식)
    // 금액 i원을 만들 수 있는 최소한의 화폐 개수를 a[i]라고 함
    // 각 화폐의 단위를 k라고 함
    // 각 화폐 단위인 k를 하나씩 확인하면서 아래의 로직을 체크
    // i-k원을 만들 수 있다면(= a[i-k]가 유효한 값이라면), i원도 만들 수 있으며 그때의 화폐 개수는 min(a[i], a[i-k]+1)이 됨
    // i-k원을 만들 수 없다면(= a[i-k]가 유효하지 않은 값이라면) i원도 만들 수 없으므로 a[i]는 INF 값이 됨
    for(int i = 0; i < N; i++)
    {
        // 순회 중인 화폐의 단위부터 순회하기 시작
        for(int j = vec[i]; j <= M; j++)
        {
            // a[i-k]값이 유효한 값인지 체크
            if(memo[j - vec[i]] != 10001)
            {
                // a[i-k]값이 유효하다면 현재의 a[i] 값과 a[i-k]+1 값 비교하여 최소값으로 갱신
                memo[j] = min(memo[j], memo[j - vec[i]] + 1);
            }
        }
    }

    // 순회를 끝냈는데도 a[M]이 유효한 값인지 체크하고 출력
    if(memo[M] != 10001)
    {
        cout << memo[M] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}