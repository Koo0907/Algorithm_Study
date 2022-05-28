#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0; 
int L = 0;
int num = 0;
int ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> M >> L;

    // ù��° ��ġ(0) �߰�
    vec.push_back(0);

    // �ްԼ� ��ġ
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ������ ��ġ(L) �߰�
    vec.push_back(L);

    // �������� ����
    sort(vec.begin(), vec.end());

    int start = 1;
    int end = L - 1;
    
    while(start <= end)
    {
        int mid = (start + end) / 2;

        int sum = 0;
        for(int i = vec.size() - 1; i > 0; i--)
        {
            // �ްԼ� ������ �Ÿ�(+ �� ������ �ްԼ��� �Ÿ�)
            int len = vec[i] - vec[i - 1];

            // �� �ްԼ� ���̿� ��ġ ������ �ްԼ��� ����
            sum += (len / mid);

            // % �������� �������� ���ٸ� �ްԼ��� ��ġ�� �ߺ��̶�� �ǹ��̹Ƿ� �ްԼ��� ���� ����
            if(len % mid == 0)
            {
                sum--;
            }
        }

        // ��ġ�� �ްԼҰ� M������ ���ٸ� �ްԼҿ��� �Ÿ��� �ø�
        if(sum > M)
        {
            start = mid + 1;
        }
        // ��ġ�� �ްԼҰ� M������ ���ų� ���ٸ� �ްԼҿ��� �Ÿ��� ����
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    cout << ans << endl;
}