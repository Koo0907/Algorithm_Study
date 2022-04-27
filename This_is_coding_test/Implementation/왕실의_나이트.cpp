#include<iostream>
#include<string.h>

using namespace std;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {

    string idx;
    int x;
    int y;
    int next_x;
    int next_y;
    int cnt = 8;

    cin >> idx;

    // 좌표의 초기값 (0,0)으로 설정
    y = idx[0] - 'a';
    x = idx[1] - '1';

    for(int i = 0; i < 8; i++)
    {
        next_x = x + dx[i];
        next_y = y + dy[i];
        
        // 8x8 행렬의 범위를 벗어나는 경우가 있다면 경우의 수 하나 감소
        if((next_x < 0) || (next_x > 7) || (next_y < 0) || (next_y > 7))
        {
            cnt--;
        }
    }

    cout << cnt << endl;
}