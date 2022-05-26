/* 백준 링크 */
/* https://www.acmicpc.net/problem/2110 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int C = 0;
int num = 0;

vector<int> vec;

bool check_gap(int gap)
{
    // 첫번째 집에는 항상 공유기를 설치하고 공유기의 수를 1로 초기화 후 진행
    int prev = vec[0];
    int cnt = 1;

    // 첫번째 집의 위치 제외하고 순회
    for(int i = 1; i < N; i++)
    {
        // 직전에 공유기를 설치한 위치에서 gap만큼 차이를 둔 집이 있다면 공유기를 설치하고 count 증가
        if((vec[i] - prev) >= gap)
        {
            prev = vec[i];
            cnt++;
        }
    }

    // 순회를 다 마치고 설치한 공유기의 수가 입력받은 C 이상이라면 조건을 만족하므로 true 반환
    if(cnt >= C)
    {
        return true;
    }
    // 조건을 만족하지 못하므로 false 반환
    else
    {
        return false;
    }

}

int binary_search(int start, int end)
{
    int temp_res = 0;

    while(start <= end)
    {
        int gap = (start + end) / 2;

        // 선택한 gap 이상의 간격을 두고도 입력한 공유기의 수를 만족할 수 있는지 확인
        if(check_gap(gap))
        {
            // 공유기의 수를 만족한다면 임시 정답 변수인 temp_res에 현재 gap 저장
            temp_res = gap;

            // 현재 gap에서는 조건을 만족했으므로 gap을 조금 더 늘려서도 조건을 부합하는지 확인하기 위해 gap 증가
            start = gap + 1;
        }
        else
        {
            // 공유기의 수를 만족하지 못했다면 gap이 너무 컸다는 뜻이므로 gap 감소
            end = gap - 1;
        }
    }

    // 모든 순회를 돌고나서 마지막에 저장된 임시 정답 반환
    return temp_res;
}

int main()
{
    int res = 0;

    cin >> N >> C;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 이진 탐색을 위한 오름차순 정렬
    sort(vec.begin(), vec.end());

    res = binary_search(1, vec[N - 1] - vec[0]);

    cout << res << endl;
}