#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int len = 0;
int sum = 0;

vector<int> ttuk;

int binary_search(int start, int end, int want_len)
{
    // ���� �ִ� ���̰� 1000000000�̹Ƿ� �߸� ���� ���̸� ���ϴ� ������ long long Ÿ������ �ʱ�ȭ
    long long res = 0;

    // ���� Ž�� ����
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // mid ���� ���ܱ��� ���̶�� �� ���� �մ��� ������ �� �ִ� ���� ���� ���
        for(int i = 0; i < N; i++)
        {
            if(ttuk[i] > mid)
            {
                sum += (ttuk[i] - mid);
            }
        }

        // �մ��� ���ϴ� ���̺��� ª�ٸ� ���ܱ��� ���̸� ���� -> ���� Ž������ end ���� mid - 1 ������ ����
        if(sum < want_len)
        {
            end = mid - 1;
        }
        // �մ��� ���ϴ� ���� �̻��̶�� �� ���� ���ܱ��� ����(mid)�� �����ϰ� ���ܱ��� ���̸� ������ �ٽ� üũ
        else
        {
            res = mid;
            start = mid + 1;
        }

        sum = 0;
    }

    return res;
}

int main(void)
{
    long long res = 0;
    
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> len;
        ttuk.push_back(len);
    }

    // ���� �� ������ ���� �˱� ���� ������
    sort(ttuk.begin(), ttuk.end());

    res = binary_search(0, ttuk[N - 1], M);

    cout << res << endl;
}