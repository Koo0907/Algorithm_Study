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
        // �ε����� �켱������ pair�� �����ϴ� queue
        queue<pair<int, int>> print_wait;
        // �켱������ �����ϴ� priority_queue
        priority_queue<int> prior;
        cin >> print_case >> tar;
        for(int idx = 0; idx < print_case; idx++)
        {
            int pri;
            cin >> pri;
            // �ε����� �켱������ pair�� ����(�Ϲ� queue)
            print_wait.push({idx,pri});
            // �켱���� ����(�켱���� queue)
            prior.push(pri);
        }
        
        while(!print_wait.empty())
        {
            // queue�� �� ���� �ִ� �ε����� �켱���� read �� �ش� ������ pop
            int idx = print_wait.front().first;
            int pri = print_wait.front().second;
            print_wait.pop();

            // read�� �켱������ ������������ ���ĵ� �켱������ �����ϴٸ� �Ʒ� ���� Ž
            if(pri == prior.top())
            {
                prior.pop();
                cnt++;
                // read�� �������� �ε����� ã������ �ϴ� �ε����� �����ϸ� �Ʒ� ���� Ž
                if(idx == tar)
                {
                    // vector�� ����� ����
                    res.push_back(cnt);
                    break;
                }
            }
            else
            {
                // �������� ������ queue�� �� �ڷ� ������ push
                print_wait.push({idx,pri});
            }
        }
    }

    for(vector<int>::iterator itr = res.begin(); itr != res.end(); itr++)
    {
        cout << *itr << endl;
    }
}