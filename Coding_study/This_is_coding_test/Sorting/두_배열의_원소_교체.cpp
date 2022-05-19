#include<iostream>
#include<vector>
using namespace std;

// 사용할 변수 초기화
int N = 0;
int K = 0;
int sum = 0;

vector<int> a,b;

// 올림차순 퀵정렬
void q_sort_incre(vector<int>& arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    // left 값과 right 값이 엇갈릴 때 까지 반복
    while(left <= right)
    {
        // arr[left] 값이 arr[pivot] 값보다 클 때 까지 left 값 증가
        while((left <= end) && (arr[left] <= arr[pivot]))
        {
            left++;
        }

        // arr[right] 값이 arr[pivot] 값보다 작을 때 까지 right 값 감소
        while((right > start) && (arr[right] >= arr[pivot]))
        {
            right--;
        }

        // right 값과 left 값이 엇갈린다면 작은 값(arr[right])을 arr[pivot] 값과 swap
        if(right < left)
        {
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] 값과 arr[right] 값 swap
        else
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }

    // arr[pivot] 값 기준으로 나눠진 영역 중 왼쪽 영역에 대해서 재귀 함수 호출
    q_sort_incre(arr, start, right - 1);

    // arr[pivot] 값 기준으로 나눠진 영역 중 오른쪽 영역에 대해서 재귀 함수 호출
    q_sort_incre(arr, left, end);
}

// 내림차순 퀵정렬
void q_sort_decre(vector<int>& arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    // left 값과 right 값이 엇갈릴 때 까지 반복
    while(left <= right)
    {
        // arr[left] 값이 arr[pivot] 값보다 작을 때 까지 left 값 증가
        while((left <= end) && (arr[left] >= arr[pivot]))
        {
            left++;
        }

        // arr[right] 값이 arr[pivot] 값보다 클 때 까지 right 값 감소
        while((right > start) && (arr[right] <= arr[pivot]))
        {
            right--;
        }

        // right 값과 left 값이 엇갈린다면 큰 값(arr[right])을 arr[pivot] 값과 swap
        if(right < left)
        {
            int temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] 값과 arr[right] 값 swap
        else
        {
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }
    // arr[pivot] 값 기준으로 나눠진 영역 중 왼쪽 영역에 대해서 재귀 함수 호출
    q_sort_decre(arr, start, right - 1);

    // arr[pivot] 값 기준으로 나눠진 영역 중 오른쪽 영역에 대해서 재귀 함수 호출
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

    // a 벡터는 오름차순 정렬
    q_sort_incre(a, 0, a.size() - 1);

    // b 벡터는 내림차순 정렬
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