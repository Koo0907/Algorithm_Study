#include<iostream>

using namespace std;

int main() {

    int N;
    int res = -1;
    int offset = 0;

    cin >> N;

    while(N >= 0)
    {
        // 5kg 가방으로 나누어 떨어지면 가장 적은 수
        if((N % 5) == 0)
        {
            res = (N / 5) + offset;
            break;
        }
        
        // 총 무게에서 3kg을 제외시키고, offset(3kg 가방의 수) 증가
        N -= 3;
        offset++;
    }

    cout << res << endl;
}