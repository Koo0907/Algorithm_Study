#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int num = 0;

vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // 오름차순 정렬
    sort(vec.begin(), vec.end());

    // N이 홀수이면 가운데 요소 출력
    // N이 짝수이면 가운데 요소에서 하나 더 작은 요소 출력
    if((N % 2) == 0)
    {
        cout << vec[(N / 2) - 1] << endl;
    }
    else
    {
        cout << vec[N / 2] << endl;
    }
}