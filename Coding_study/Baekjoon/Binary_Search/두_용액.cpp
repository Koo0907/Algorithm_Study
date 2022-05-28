#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

vector<int> vec;
vector<int> ans(2);

void search_liquid(int start, int end)
{
    int res = 2e9;

    while(start < end)
    {
        int temp_res = vec[start] + vec[end];

        // ���� ���� Ư������ ���밪�� ������ Ư������ ���밪���� �۴ٸ� ���� ����
        // ���ÿ� ���� ������ ���� �Բ� ����  
        if(abs(temp_res) < res)
        {
            res = abs(temp_res);
            ans[0] = vec[start];
            ans[1] = vec[end];

            // ����� Ư������ 0�̸� �״�� ����
            if(temp_res == 0)
            {
                return;
            }
        }

        // ����� Ư������ 0���� ������ ���� ��꿡�� 0�� �� �� �ִ��� Ȯ���غ��� ���� start��(���� ���� ��)�� ������ ������Ŵ
        if(temp_res < 0)
        {
            start++;
        }
        // ����� Ư������ 0���� ũ�� ���� ��꿡�� 0�� �� �� �ִ��� Ȯ���غ��� ���� end��(���� ū ��)�� ������ ���ҽ�Ŵ
        else
        {
            end--;
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // �������� ����
    sort(vec.begin(), vec.end());

    search_liquid(0, (vec.size() - 1));
    
    // ���� ���� ��ҵ� ���
    cout << ans[0] << " " << ans[1] << endl;
}