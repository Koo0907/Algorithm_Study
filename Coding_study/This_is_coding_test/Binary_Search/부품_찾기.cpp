#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int num = 0;

vector<int> store;
vector<int> customer;

// 이진 탐색 함수
bool binary_search(int start, int end, int target)
{
    // 이진 탐색 함수 수행
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // 가운데 값이 taget과 동일하다면 true 반환
        if(store[mid] == target)
        {
            return true;
        }
        // 가운데 값이 target보다 작다면 가운데 기준으로 우측에서 다시 탐색
        else if(store[mid] < target)
        {
            start = mid + 1;
        }
        // 가운데 값이 target보다 크다면 가운데 기준으로 좌측에서 다시 탐색
        else
        {
            end = mid - 1;
        }
    }

    // target을 찾지 못하면 false 반환
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

    // 이진 탐색을 위한 오름차순 정렬
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