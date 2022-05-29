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
    int sum = 0;

    cin >> N >> M;
    
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        sum += num;
        vec.push_back(num);
    }

    // ����� �뵷�� �ּҰ��� �뵷 ������ �ִ밪
    int start = *max_element(vec.begin(), vec.end());

    // ����� �뵷�� �ִ밪�� �뵷 ���� ������ ����
    int end = sum;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        // ������ Ƚ���� 1���� ����
        int cnt = 1;
        int temp = 0;

        for(int i = 0; i < N; i++)
        {
            // ������� ���� temp ���� ������ ����� �뵷�� ���� ���� mid ������ ������ �۰ų� ���ٸ� ����ؼ� �ѹ� ������ ������ ���
            if(temp + vec[i] <= mid)
            {
                temp += vec[i];
            }
            // ������� ���� temp ���� ������ ����� �뵷�� ���� ���� mid ������ Ŀ���� �ȴٸ� ������ Ƚ���� ������Ű�� ���Ӱ� ���      
            else
            {
                cnt++;
                temp = vec[i];
            }
        }

        // ������ Ƚ���� �Է¹��� M ������ ũ�ٸ� ���� �ݾ��� �ʹ� �۰� ���� ���̹Ƿ� ������ ������Ŵ
        if(cnt > M)
        {
            start = mid + 1;
        }
        // ������ Ƚ���� �Է¹��� M ������ ���ų� �۴ٸ� ���� �ݾ��� �ٿ��� Ȯ���� �ʿ䰡 �����Ƿ� ���� �ݾ��� �����ϰ� ������ ���ҽ�Ŵ
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}