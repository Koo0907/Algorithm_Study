#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

vector<int> vec;

int binary_search(int start, int end)
{
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // �߾Ӱ��� �ε����� �� �ε����� ��Ұ��� ���ٸ� �ش� �ε��� ��ȯ
        if(mid == vec[mid])
        {
            return mid;
        }
        // �߾Ӱ��� �ε������� �� �ε����� ��Ұ��� ũ�ٸ� �߾Ӱ� �������� �������� �ٽ� Ž��
        else if(mid < vec[mid])
        {
            end = mid - 1;
        }
        // �߾Ӱ��� �ε������� �� �ε����� ��Ұ��� �۴ٸ� �߾Ӱ� �������� �������� �ٽ� Ž��
        else
        {
            start = mid + 1;
        }
    }

    // �ش� ������ �����ϴ� ���� ã�� ���ϸ� -1 ��ȯ
    return -1;
}

int main()
{
    int res = 0;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ���� Ž�� �Լ� ȣ��
    res = binary_search(0, vec.size() - 1);

    cout << res << endl;
}