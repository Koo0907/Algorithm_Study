/* 백준 링크 */
/* https://www.acmicpc.net/problem/1715 */
#include<iostream>
#include<queue>

using namespace std;

// 사용할 변수 초기화
int N = 0;

// 우선순위 큐를 사용하여 요소를 추가할 때 마다 정렬되도록 함
priority_queue<int> pq;

int main()
{
    int num = 0;
    int sum = 0;
    int temp_sum = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;

        // 입력받은 수들에 대해서 항상 가장 작은 크기의 두 카드 묶음을 합쳤을 때 최적의 해가 나옴
        // 우선순위 큐는 내림차순으로 정렬을 해주기 때문에 입력받은 카드 묶음 값에 -1을 곱하여 추가함
        // ex) 10, 20, 40
        // ex) 일반적인 우선순위 큐 : 40, 20, 10
        // ex) -1을 곱하고 추가한 우선순위 큐 : -10, -20, -40
        pq.push(num * -1);
    }

    // 우선순위 큐에 요소가 1개가 남을 때 까지 반복
    while(pq.size() > 1)
    {
        // 맨 앞의 값을 꺼내오면서 -1을 다시 곱해줌
        int a = pq.top() * -1;
        pq.pop();

        // 맨 앞의 값을 꺼내오면서 -1을 다시 곱해줌
        int b = pq.top() * -1;
        pq.pop();

        // 두 카드 묶음 값들을 비교하여 temp_sum 변수에 저장
        temp_sum = a + b;

        // 두 카드 묶음 값들을 비교한 값인 temp_sum을 sum 변수에 누적으로 저장
        sum += temp_sum;

        // 두 카드 묶음을 비교한 temp_sum 값을 우선순위 큐에 추가
        // 이때도 -1을 곱하여 추가
        pq.push(temp_sum * -1);
    }

    cout << sum << endl;
}