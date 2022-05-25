#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int len = 0;
int sum = 0;

vector<int> ttuk;

int binary_search(int start, int end, int want_len)
{
    // 떡의 최대 길이가 1000000000이므로 잘린 떡의 길이를 합하는 변수는 long long 타입으로 초기화
    long long res = 0;

    // 이진 탐색 수행
    while(start <= end)
    {
        int mid = (start + end) / 2;

        // mid 값을 절단기의 높이라고 할 때의 손님이 가져갈 수 있는 떡의 길이 계산
        for(int i = 0; i < N; i++)
        {
            if(ttuk[i] > mid)
            {
                sum += (ttuk[i] - mid);
            }
        }

        // 손님이 원하는 길이보다 짧다면 절단기의 높이를 낮춤 -> 이진 탐색에서 end 값을 mid - 1 값으로 변경
        if(sum < want_len)
        {
            end = mid - 1;
        }
        // 손님이 원하는 길이 이상이라면 그 때의 절단기의 높이(mid)를 저장하고 절단기의 높이를 높혀서 다시 체크
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

    // 가장 긴 길이의 떡을 알기 위해 정렬함
    sort(ttuk.begin(), ttuk.end());

    res = binary_search(0, ttuk[N - 1], M);

    cout << res << endl;
}