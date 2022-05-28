#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
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

        // 현재 계산된 특성값의 절대값이 이전의 특성값의 절대값보다 작다면 새로 갱신
        // 동시에 정답 벡터의 값도 함께 갱신  
        if(abs(temp_res) < res)
        {
            res = abs(temp_res);
            ans[0] = vec[start];
            ans[1] = vec[end];

            // 계산한 특성값이 0이면 그대로 종료
            if(temp_res == 0)
            {
                return;
            }
        }

        // 계산한 특성값이 0보다 작으면 다음 계산에서 0이 될 수 있는지 확인해보기 위해 start쪽(값이 작은 쪽)의 범위를 증가시킴
        if(temp_res < 0)
        {
            start++;
        }
        // 계산한 특성값이 0보다 크면 다음 계산에서 0이 될 수 있는지 확인해보기 위해 end쪽(값이 큰 쪽)의 범위를 감소시킴
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

    // 오른차순 정렬
    sort(vec.begin(), vec.end());

    search_liquid(0, (vec.size() - 1));
    
    // 정답 벡터 요소들 출력
    cout << ans[0] << " " << ans[1] << endl;
}