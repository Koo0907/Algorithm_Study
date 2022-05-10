#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int N;
    int x;
    int res = 0;
    int num = 0;
    vector<int> fear;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        fear.push_back(x);
    }

    // sort 메서드 이용해서 오름차순 정렬
    sort(fear.begin(), fear.end());

    for(vector<int>::iterator itr = fear.begin(); itr != fear.end(); itr++)
    {
        num++;  // 현재 그룹의 모험가 수 증가
        if(num >= *itr) // 현재 그룹의 모험가 수가 순회하고 있는 공포도 이상이라면 그룹으로 모험을 보낼 수 있음
        {
            res++;
            num = 0;    // 현재 그룹의 모험가 수 초기화
        }
    }

    cout << res << endl;
}