#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int start_time = 0;
int end_time = 0;

vector<pair<int, int>> class_time;

// vector<int> 인자와 greater<int> 인자를 추가 선언하여 내림차순으로 정렬되는 우선순위 큐 이용
priority_queue<int, vector<int>, greater<int>> class_room;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> start_time >> end_time;
        class_time.push_back({start_time, end_time});
    }

    // 수업시간들을 오름차순으로 정렬
    // 시작시간이 똑같다면 종료시간이 낮은 순으로 정렬
    sort(class_time.begin(), class_time.end());

    // 우선순위 큐에 가장 일찍 시작하고 가장 일찍 끝나는 첫번째 요소의 종료시간 삽입
    class_room.push(class_time[0].second);

    // 두번째 수업부터 순회
    for(int i = 1; i < class_time.size(); i++)
    {
        // 순회하는 수업의 시작시간이 현재 우선순위 큐에 들어있는 가장 빠른 종료시간보다 같거나 크다면 강의를 같은 강의실에서 이어서 할 수 있음
        if(class_room.top() <= class_time[i].first)
        {
            // 이어할 수 있다면 가장 빠른 종료시간 데이터 삭제
            class_room.pop();
        }

        // 순회하는 수업의 종료시간 삽입
        class_room.push(class_time[i].second);
    }

    // 우선순위 큐의 크기가 강의실의 수와 동일함
    cout << class_room.size() << endl;;
}