/* ���� ��ũ */
/* https://www.acmicpc.net/problem/14501 */
#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num1 = 0;
int num2 = 0;
int max_val = 0;

// dp[i] = i���� ������ ������ ������ �� �� �ִ� �ִ� ����
int dp[16];
vector<pair<int, int>> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num1 >> num2;
        vec.push_back({num1, num2});
    }

    // Dynamic Programming ����(Bottom-up ���)
    // ��� ����Ʈ�� �ڿ������� �Ųٷ� Ȯ���ϸ鼭 dp ���̺� ����
    // ex) n = 7 / 3, 10 / 5, 20 / 1, 10 / 1, 20 / 2, 15 / 4, 40 / 2, 200
    // dp[6] = 0 -> ��� �Ⱓ �ʰ�
    // dp[5] = 0 -> ��� �Ⱓ �ʰ�
    // dp[4] = 15(max(15 + dp[6], max_val(0))) / max_val = 15
    // dp[3] = 35(max(20 + dp[4], max_val(15))) / max_val = 35
    // dp[2] = 45(max(10 + dp[3], max_val(35))) / max_val = 45
    // dp[1] = 45(max(20 + dp[6], max_val(45))) / max_val = 45
    // dp[0] = 45(max(10 + dp[3], max_val(45))) / max_val = 45
    for (int i = (N - 1); i >= 0; i--)
    {
        int time = vec[i].first + i;

        // ����� �Ⱓ �ȿ� ������ ���� �Ʒ� ���� ����
        if (time <= N)
        {
            // ���� ��� ������ ���Ͱ� ���� ����� ��ģ ���ں����� �ִ� ������ ���� ���� ������ �ִ� ���Ͱ� ���ϰ� �ִ� ���� ����
            dp[i] = max(vec[i].second + dp[time], max_val);
            max_val = dp[i];
        }
        // ����� �Ⱓ�� ����� ���� ������ �ִ� �������� ����
        else
        {
            dp[i] = max_val;
        }
    }

    cout << max_val << endl;
}