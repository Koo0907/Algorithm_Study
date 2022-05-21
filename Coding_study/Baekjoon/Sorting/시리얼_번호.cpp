#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
string serial;

vector<string> vec;

bool compare(string &a, string &b)
{
    // A�� B�� ���̰� �ٸ��� ª�� ���� ���� ���ĵǵ��� ��
    if(a.size() != b.size())
    {
        return a.size() < b.size();
    }
    // A�� B�� ���̰� ������ �Ʒ� ���� ����
    else
    {
        int sum_a = 0;
        int sum_b = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
            {
                sum_a += a[i] - '0';
            }

            if(b[i] >= '0' && b[i] <= '9')
            {
                sum_b += b[i] - '0';
            }
        }

        // A�� B�� ���ڿ����� �ڸ����� ���ؼ� ���� ���� ���� ���ĵǵ��� ��
        if(sum_a != sum_b)
        {
            return sum_a < sum_b;
        }
        // �յ� ���ٸ� ���� ������ ���ĵǵ��� ��
        else
        {
            return a < b;
        }
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> serial;
        vec.push_back(serial);
    }

    // configuration�� compare �Լ� �̿��Ͽ� sort �Լ� ȣ��
    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < N; i++)
    {
        cout << vec[i] << endl;
    }
}