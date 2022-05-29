#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int K = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> K;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ���ص� ���������� �� ���� �ּҰ��� �ִ밪�� ���ϱ� ���� ����
    sort(vec.begin(), vec.end());

    // �� ���� �ּҰ��� ���� ���� ���Ϳ��� ���� ���� ��
    int start = vec.front();

    // �� ���� �ִ밪�� ���� ���� ���Ϳ��� ���� ū ��
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;

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