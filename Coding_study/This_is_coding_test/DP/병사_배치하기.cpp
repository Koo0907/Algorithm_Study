/* ���� ��ũ */
/* https://www.acmicpc.net/problem/18353 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

int memo[2000];
vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ������ ����� '���� �� �����ϴ� ����(LIS)' �˰����� ����
    reverse(vec.begin(), vec.end());

    // Dynamic Programming�� ���� DP ���̺� �ʱ�ȭ
    for(int i = 0; i < N; i++)
    {
        memo[i] = 1;
    }

    // 1 ~ N���� ��ȸ�ϱ� ����
    for(int i = 1; i < N; i++)
    {
        // 0 ~ i���� ��ȸ�ϱ� ����
        for(int j = 0; j < i; j++)
        {
            // i��° ���� j��° ���� ũ�ٸ� dp ���̺� ����
            if(vec[i] > vec[j])
            {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }

    // ���� �� ������ ���� ����
    int max_val = 0;
    for(int i = 0; i < N; i++)
    {
        max_val = max(max_val, memo[i]);
    }

    cout << N - max_val << endl;
}