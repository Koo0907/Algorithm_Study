#include<iostream>
#include<queue>
#include<vector>
#include<utility>

using namespace std;

int main() {

    int N;
    int print_case;
    int tar;
    vector<int> res;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int cnt = 0;
        // 인덱스와 우선순위를 pair로 저장하는 queue
        queue<pair<int, int>> print_wait;
        // 우선순위를 저장하는 priority_queue
        priority_queue<int> prior;
        cin >> print_case >> tar;
        for(int idx = 0; idx < print_case; idx++)
        {
            int pri;
            cin >> pri;
            // 인덱스와 우선순위를 pair로 저장(일반 queue)
            print_wait.push({idx,pri});
            // 우선순위 저장(우선순위 queue)
            prior.push(pri);
        }
        
        while(!print_wait.empty())
        {
            // queue의 맨 앞의 있는 인덱스와 우선순위 read 후 해당 데이터 pop
            int idx = print_wait.front().first;
            int pri = print_wait.front().second;
            print_wait.pop();

            // read한 우선순위와 내림차순으로 정렬된 우선순위가 동일하다면 아래 로직 탐
            if(pri == prior.top())
            {
                prior.pop();
                cnt++;
                // read한 데이터의 인덱스와 찾으려고 하는 인덱스가 동일하면 아래 로직 탐
                if(idx == tar)
                {
                    // vector에 결과값 저장
                    res.push_back(cnt);
                    break;
                }
            }
            else
            {
                // 동일하지 않으면 queue의 맨 뒤로 데이터 push
                print_wait.push({idx,pri});
            }
        }
    }

    for(vector<int>::iterator itr = res.begin(); itr != res.end(); itr++)
    {
        cout << *itr << endl;
    }
}