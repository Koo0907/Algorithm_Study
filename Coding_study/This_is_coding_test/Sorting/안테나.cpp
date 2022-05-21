/* 백준 링크 */
/* https://www.acmicpc.net/problem/18310 */
#include<iostream>
#include<vector>
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

    // 중간 값의 집 위치를 선택하는 것이 최소값이 된다는 아이디어를 이용
    // 중간 값의 집 위치에서 좌,우로 벌어질수록 계산값은 커질 수 밖에 없음
    cout << vec[(N-1) / 2] << endl;
}