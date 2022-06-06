#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int num = 0;

// dp ���̺�
int dp[301];

vector<int> vec;

int main()
{
    cin >> n;

    // ����� ���� �Է¹޴� ������ ù��° ���� 0���� ���� �� �Է¹���
    vec.push_back(0);

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 3�� �������� ����� ���� �� �����Ƿ� �ι�° ��ܱ����� �ʱⰪ�� �̸� ������
    dp[0] = vec[0];
    dp[1] = vec[1];
    dp[2] = vec[1] + vec[2];

    // 3��° ��ܺ��� �ش� ���� ����
    // ���� ��ȸ���� ��ܿ��� ������ ����� ��� ���� ����� ��� ��쿡�� dp[i - 3] + vec[i - 1] + vec[i]
    // ���� ��ȸ���� ��ܿ��� ������ ����� ��� ���� ����� ��� ��쿡�� dp[i - 2] + vec[i]
    for(int i = 3; i <= n; i++)
    {
        dp[i] = max(dp[i - 3] + vec[i - 1], dp[i - 2]) + vec[i];
    }

    // n��° ����� ����� ���� �ִ밪 ���
    cout << dp[n] << endl;
}