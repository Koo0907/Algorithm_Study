#include<iostream>
#include<vector>
using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int K = 0;
int sum = 0;

vector<int> a,b;

// �ø����� ������
void q_sort_incre(vector<int>& arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    // left ���� right ���� ������ �� ���� �ݺ�
    while(left <= right)
    {
        // arr[left] ���� arr[pivot] ������ Ŭ �� ���� left �� ����
        while((left <= end) && (arr[left] <= arr[pivot]))
        {
            left++;
        }

        // arr[right] ���� arr[pivot] ������ ���� �� ���� right �� ����
        while((right > start) && (arr[right] >= arr[pivot]))
        {
            right--;
        }

        // right ���� left ���� �������ٸ� ���� ��(arr[right])�� arr[pivot] ���� swap
        if(right < left)
        {
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] ���� arr[right] �� swap
        else
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }

    // arr[pivot] �� �������� ������ ���� �� ���� ������ ���ؼ� ��� �Լ� ȣ��
    q_sort_incre(arr, start, right - 1);

    // arr[pivot] �� �������� ������ ���� �� ������ ������ ���ؼ� ��� �Լ� ȣ��
    q_sort_incre(arr, left, end);
}

// �������� ������
void q_sort_decre(vector<int>& arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    // left ���� right ���� ������ �� ���� �ݺ�
    while(left <= right)
    {
        // arr[left] ���� arr[pivot] ������ ���� �� ���� left �� ����
        while((left <= end) && (arr[left] >= arr[pivot]))
        {
            left++;
        }

        // arr[right] ���� arr[pivot] ������ Ŭ �� ���� right �� ����
        while((right > start) && (arr[right] <= arr[pivot]))
        {
            right--;
        }

        // right ���� left ���� �������ٸ� ū ��(arr[right])�� arr[pivot] ���� swap
        if(right < left)
        {
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] ���� arr[right] �� swap
        else
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    // arr[pivot] �� �������� ������ ���� �� ���� ������ ���ؼ� ��� �Լ� ȣ��
    q_sort_decre(arr, start, right - 1);

    // arr[pivot] �� �������� ������ ���� �� ������ ������ ���ؼ� ��� �Լ� ȣ��
    q_sort_decre(arr, left, end);
}

int main()
{
    cin >> N >> K;

    for(int i = 0; i< N; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }

    for(int i = 0; i< N; i++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }

    // a ���ʹ� �������� ����
    q_sort_incre(a, 0, a.size() - 1);

    // b ���ʹ� �������� ����
    q_sort_decre(b, 0, b.size() - 1);

    for(int i = 0; i < K; i++)
    {
        if(a[i] < b[i])
        {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
        else
        {
            break;
        }
    }

    for(int i = 0; i < N; i++)
    {
        sum += a[i];
    }

    cout << sum << endl;
}