#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int num = 0;

priority_queue<int> pq;

// 이번 문제는 시간 제한과 메모리 제한이 키포인트
// 너무 많은 push를 통해서 메모리를 잡고 있어도 안되고
// 너무 많은 시간을 쓰게하는 함수를 호출해서도 안됨
// 그래서 이 문제에서는 기본적으로 cin, cout 함수대신 더 빠른 scnaf, printf를 사용함
int main()
{
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &num);
            pq.push(-1 * num);
        }

        // N번째 큰 수만 구하면 되므로 N개 이상의 데이터를 큐에 담고있을 필요가 없음
        // 우선순위 큐이기 때문에 어차피 정렬됨
        while(pq.size() > N)
        {
            pq.pop();
        }
    }

    printf("%d", (pq.top() * -1));
}