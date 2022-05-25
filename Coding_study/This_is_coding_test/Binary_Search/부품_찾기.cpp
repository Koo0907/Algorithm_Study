#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int num = 0;

vector<int> store;
vector<int> customer;

// ���� Ž�� �Լ�
bool binary_search(int start, int end, int target)
{
    // ���� Ž�� �Լ� ����
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // ��� ���� taget�� �����ϴٸ� true ��ȯ
        if(store[mid] == target)
        {
            return true;
        }
        // ��� ���� target���� �۴ٸ� ��� �������� �������� �ٽ� Ž��
        else if(store[mid] < target)
        {
            start = mid + 1;
        }
        // ��� ���� target���� ũ�ٸ� ��� �������� �������� �ٽ� Ž��
        else
        {
            end = mid - 1;
        }
    }

    // target�� ã�� ���ϸ� false ��ȯ
    return false;
}

int main(void)
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        store.push_back(num);
    }

    cin >> M;

    for(int i = 0; i < M; i++)
    {
        cin >> num;
        customer.push_back(num);
    }

    // ���� Ž���� ���� �������� ����
    sort(store.begin(), store.end());

    for(int i = 0; i < M; i++)
    {
        if(binary_search(0, N - 1, customer[i]))
        {
            cout << "YES ";
        }
        else
        {
            cout << "NO ";
        }
    }
}