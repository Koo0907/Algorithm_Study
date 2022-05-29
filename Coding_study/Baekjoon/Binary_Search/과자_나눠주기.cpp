#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> M >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ������ �ص� Ǯ�⿡�� ����
    sort(vec.begin(), vec.end());

    // ����� �ּҰ��� 1
    int start = 1;

    // ����� �ִ밪�� ���� �� ���� ����
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;
        int cnt = 0;

        for(int i = 0; i < N; i++)
        {
            // ��ȸ�ϴ� ���ڸ� mid �������� �������� ��(���ڸ� �� �� �ִ� ��ī�� ���� ����)�� ���� ����
            cnt += (vec[i] / mid);
        }

        // ����� ���� ��ī�� ������ �۴ٸ� ������ ���� ������ ����ٴ� ���̹Ƿ� ������ ����
        if(cnt < M)
        {
            end = mid - 1;
        }
        // ����� ���� ��ī�� ������ ���ų� ũ�ٸ� ���̸� �÷��� Ȯ���غ����ϹǷ� ���� mdi ���� �����ϰ� ������ ����
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}