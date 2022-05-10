#include<iostream>
#include<vector>

using namespace std;

int main() {

    int N;
    int K;
    int num;
    int cnt = 0;
    vector<int> coin;

    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        coin.push_back(num);
    }

    int idx = coin.size();
    
    // 가장 큰 단위의 동전부터 나누면서 그 몫을 동전의 수, 나머지를 남은 금액으로 계산
    while(idx != 0)
    {
        cnt += (K / coin[idx -1]);
        K %= coin[idx - 1];
        idx--;
    }

    cout << cnt << endl;
}