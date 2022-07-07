#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int lec_time = 0;
int op = 0;

// 선수과목 수 테이블
int deg[501];

// 선수과목 정보를 담기 위한 vector
vector<int> vec[501];

// 각 강의 시간을 담기 위한 배열
int times[501];

// 각 강의를 수강하기 위한 전체 시간을 담기 위한 배열
int res[501];

void topology_sort()
{
    // 큐 선언
    queue<int> que;

    // res 배열을 times 배열로 초기화
    for(int i = 1; i <= N; i++)
    {
        res[i] = times[i];
    }

    // 진입 차수가 0인 강의 선택
    for(int i = 1; i <= N; i++)
    {
        if(deg[i] == 0)
        {
            que.push(i);
        }
    }

    // 큐가 빌 때까지 반복
    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        // 현재 강의를 선수과목으로 하는 강의가 있는지 확인
        for(int i = 0; i < vec[now].size(); i++)
        {
            // next_lec은 현재 강의를 선수과목으로 함
            int next_lec = vec[now][i];
            res[next_lec] = max(res[next_lec], res[now] + times[next_lec]);
            deg[next_lec]--;
            
            // 진입 차수가 0이 된다면 큐에 추가
            if(deg[next_lec] == 0)
            {
                que.push(next_lec);
            }
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        // 강의의 시간 배열에 입력
        cin >> lec_time;
        times[i] = lec_time;

        while(true)
        {
            cin >> op;

            // '-1'이 입력될때 까지 반복하면서 연결리스트 갱신
            if(op < 0)
            {
                break;
            }
            deg[i]++;
            vec[op].push_back(i);
        }

    }

    // 위상 정렬 수행
    topology_sort();

    // 결과값 출력
    for(int i = 1; i <= N; i++)
    {
        cout << res[i] << endl;
    }
}