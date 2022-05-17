#include<iostream>

using namespace std;

// 사용할 변수들 초기화
int N = 0;
int num[100];
int op[4];

// 최대값과 최소값 초기값 설정
int max_val = -1000000000;
int min_val = 1000000000;

void dfs(int idx, int cur_num)
{
    // 호출한 함수의 index 인자가 연산자 수와 같으면 최대값 및 최소값 판단
    if(idx == (N - 1))
    {
        if(cur_num > max_val)
        {
            max_val = cur_num;
        }

        if(cur_num < min_val)
        {
            min_val = cur_num;
        }
    }
    else
    {
        // 각 연산자에 맞춰서 완전 탐색
        if(op[0] > 0)
        {
            op[0]--;
            dfs(idx + 1, cur_num + num[idx + 1]);
            op[0]++;
        }
        if(op[1] > 0)
        {
            op[1]--;
            dfs(idx + 1, cur_num - num[idx + 1]);
            op[1]++;
            
        }
        if(op[2] > 0)
        {
            op[2]--;
            dfs(idx + 1, cur_num * num[idx + 1]);
            op[2]++;

        }
        if(op[3] > 0)
        {
            op[3]--;
            dfs(idx + 1, cur_num / num[idx + 1]);
            op[3]++;
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int temp_num;
        cin >> temp_num;
        num[i] = temp_num;
    }
    
    for(int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    dfs(0, num[0]);

    cout << max_val << endl << min_val << endl;
}