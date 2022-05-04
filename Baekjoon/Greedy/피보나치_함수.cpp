#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int n0[41] = {1, 0};
int n1[41] = {0, 1};

int main() {

    int test_case;
    int N;
    vector<pair<int, int>> res;

    cin >> test_case;

    // 피보나치 수열은 n = (n-1) + (n-2)의 규칙이므로 동일하게 적용
    for(int i = 2; i <= 40; i++)
    {
        n0[i] = n0[i - 2] + n0[i - 1];
        n1[i] = n1[i - 2] + n1[i - 1];
    }

    for(int i = 0; i < test_case; i++)
    {
        cin >> N;
        res.push_back({n0[N], n1[N]});
    }

    for(vector<pair<int,int>>::iterator itr = res.begin(); itr != res.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}