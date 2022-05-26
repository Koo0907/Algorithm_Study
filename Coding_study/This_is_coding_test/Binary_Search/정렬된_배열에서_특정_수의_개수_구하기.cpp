#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int x = 0;

vector<int> vec;

int Count_by_range(int target)
{
    // upper_bound �޼���� ����° �Ķ���� ���� �ʰ��ϴ� ���ڰ� ó�� �����ϴ� index�� ��ȯ
    // lower_bound �޼���� ����° �Ķ���� �� �̻��� ���ڰ� ó�� �����ϴ� index�� ��ȯ
    vector<int>::iterator max = upper_bound(vec.begin(), vec.end(), target);
    vector<int>::iterator min = lower_bound(vec.begin(), vec.end(), target);

    return max - min;
}

int main()
{
    int res = 0;

    cin >> N >> x;

    for(int i = 0; i < N; i++)
    {
        int num;

        cin >> num;
        vec.push_back(num);
    }

    res = Count_by_range(x);

    if(res == 0)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res << endl;
    }
}