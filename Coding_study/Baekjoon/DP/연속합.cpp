#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int num = 0;
int max_val = 0;

// dp ���̺�
int dp[100001];

vector<int> vec;

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // dp ���̺��� ù��° ���� ������ ù��° ������ �ʱ�ȭ
    dp[0] = vec[0];

    // �ִ밪�� dp ���̺��� ù��° ������ �ʱ�ȭ
    max_val = dp[0];

    for(int i = 1; i < n; i++)
    {
        // ������ �� �ϳ��� ���ϸ鼭 �κ����� �ִ밪�� �Ǵ�
        // ���� ��ȸ���� ���� ���ؼ� ���� ������ ���������� �����ϴ� ��쿡�� dp[i-1] + vec[i]
        // ���� ��ȸ���� ���� ���ؼ� ���� ���� �����ϰ� ��ȸ�ϴ� ���� �����ϴ� ��쿡�� vec[i]
        // ������ ����� �� ū ���� ����
        dp[i] = max(dp[i - 1] + vec[i], vec[i]);

        // �ѹ��� ��ȸ�� �ִ밪 �Ǵ��� ������ �ִ밪 �� �� ����
        if(dp[i] > max_val)
        {
            max_val = dp[i];
        }
    }

    // �ִ밪 ���
    cout << max_val << endl;
}