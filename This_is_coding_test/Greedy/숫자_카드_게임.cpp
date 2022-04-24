#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    
    int N;
    int M;
    int x;
    int min_val;
    int max_val = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        min_val = 10001;    // 각 행을 순회하기 전에 최소값을 조건 상 가장 큰 수로 초기화
        for(int j = 0; j < M; j++)
        {
            cin >> x;
            if(min(min_val, x) < min_val)   // 현재 최소값과 입력받은 값을 비교하여 최소값 갱신
            {
                min_val = x;
            }
        }
        max_val = max(max_val, min_val);    // 각 행의 순회를 마친 후에 최대값 추적
    }

    cout << max_val << endl;
}