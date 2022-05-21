/* 프로그래머스 링크 */
/* https://programmers.co.kr/learn/courses/30/lessons/42889 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stage와 실패율을 함께 처리하기 위한 struct 정의
struct Fail_per
{
    int stage;
    double fail;
};

// sort 함수 이용을 위한 compare 함수
bool compare(struct Fail_per &a, struct Fail_per &b)
{
    // 실패율이 같다면 stage의 수 오름차순
    if(a.fail == b.fail)
    {
        return a.stage < b.stage;
    }

    // 실패율이 다르다면 기본적으로 내림차순
    return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    // 반환할 answer vector
    vector<int> answer;

    // stage와 실패율의 데이터를 담는 struct vecotr
    vector<Fail_per> res;

    // 전달받은 stages vector의 크기를 통해서 사용자의 수 복사
    int users = stages.size();

    // stage 수 만큼 반복
    for(int i = 1; i <= N; i++)
    {
        int temp_cnt = 0;

        // 사용자 수 만큼 반복
        for(int j = 0; j < stages.size(); j++)
        {
            // 사용자가 진행하고 있는 stage가 현재 순회중인 stage(i)와 같다면 사용자 수 count
            if(stages[j] == i)
            {
                temp_cnt++;
            }
        }

        // 실패율 초기화
        double temp_fail = 0;

        // 현재 stage에 도달한 사용자가 없는 경우에는 실패율 0으로 정의
        // 현재 stage에 도달한 사용자가 있다면 실패율 계산
        if(users > 0)
        {
            temp_fail = (double)temp_cnt / users;
        }

        // res vecotr에 stage와 실패율 struct 데이터 추가
        res.push_back({i, temp_fail});

        // 앞서 계산된 사용자들은 앞으로의 실패율 계산에서 제외시켜야 하므로 counting 된 수 만큼 전체 사용자 수에서 제외
        users -= temp_cnt;
    }

    // configuration compare 함수를 이용한 sort 함수 호출
    sort(res.begin(), res.end(), compare);

    // sorting된 순서대로 answer vector에 stage만 추가
    for(int i = 0; i < N; i++)
    {
        answer.push_back(res[i].stage);
    }

    return answer;
}

int main()
{
    int N = 0;
    int num = 0;
    vector<int> vec;
    vector<int> res;

    cin >> N;

    // 입출력 예시#1 적용(N = 5, stages = [2, 1, 2, 6, 2, 4, 3, 3])
    for(int i = 0; i < 8; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    res = solution(N, vec);

    for(int i = 0; i < N; i++)
    {
        cout << res[i] << endl;
    }
}