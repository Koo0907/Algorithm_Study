#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int K = 0;
int num = 0;
int ans = 0;

vector<long long> vec;

int main()
{
    cin >> N >> K;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // �� ���� �ּҰ��� 0
    long long start = 0;

    // �� ���� �ִ밪�� 1e10
    long long end = 1e10;

    while(start <= end)
    {
        long long mid = (start + end) / 2;

        // �� ������ ���� ��ȸ���� ������ ���̸� �������� ���ϴ� sum ������ long long���� �����ؾ� ��
        long long sum = 0;

        for(int i = 0; i < N; i++)
        {
            // ���� ��ȸ���� ������ �� �������� �۴ٸ� �Ʒ� ���� ����
            if(vec[i] < mid)
            {
                // sum ������ ������ �� ������ ���� ��ȸ���� ������ ���� �������� ����
                sum += (mid - vec[i]);
            }
        }

        // ����� ������ ���� �������� ���� ���� �Է¹��� K���� ũ�ٸ� �� ���� ������ �ʹ� ũ�� �ߴٴ� ���̹Ƿ� ������ ���ҽ�Ŵ
        if(sum > K)
        {
            end = mid - 1;
        }
        // ����� ������ ���� �������� ���� ���� �Է¹��� K���� ���ų� �۴ٸ� �� ������ ���� ������ Ȯ���غ��� �ϹǷ� ���� ���� �����ϰ� ������ ������Ŵ
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}