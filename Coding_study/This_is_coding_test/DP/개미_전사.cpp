#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

int memo[100];

vector<int> vec;

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // Dynamic Programming ����(Bottom-up ���)
    memo[0] = vec[0];
    memo[1] = max(vec[0], vec[1]);

    for(int i = 2; i < N; i++)
    {
        memo[i] = max(memo[i - 2] + vec[i], memo[i - 1]);
    }
    
    cout << memo[N - 1] << endl;
}