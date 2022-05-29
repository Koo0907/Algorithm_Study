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
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    cin >> M;

    // ���ص� ���������� ������ �ִ밪�� ���ϱ� ���� ����
    sort(vec.begin(), vec.end());

    // ������ �ּҰ��� 0
    // �䱸�� ������� �� �������� �й��� �� ���� ��쿡�� ������ 0�� ����
    // �������� ���� ��õǾ� ���� �ʾƼ� ���ڰ� ��̴� �κ�
    int start = 0;

    // ������ �ִ밪�� ���� �䱸 ���� ������ ���� ū ��
    int end = vec.back();

    while(start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0;

        for(int i = 0; i < N; i++)
        {
            // �䱸 ������ ������ ���꺸�� ũ�ٸ� ������ �������� ���
            if(vec[i] > mid)
            {
                sum += mid;
            }
            // �䱸 ������ ������ ���꺸�� �۰ų� ���ٸ� �䱸 �������� ���
            else
            {
                sum += vec[i];
            }
        }

        // ����� �� ������ �Է¹��� M���� ũ�ٸ� ������ �ʹ� ũ�� ���� ���̹Ƿ� ������ ���ҽ�Ŵ
        if(sum > M)
        {
            end = mid - 1;
        }
        // ����� �� ������ �Է¹��� M���� �۰ų� ���ٸ� ������ �÷��� Ȯ���ؾߺ��� �ϹǷ� ���� ���� �����ϰ� ������ ������Ŵ
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    cout << ans << endl;
}