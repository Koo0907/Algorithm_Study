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

    // ��ǥ�� �ʱⰪ (0,0)���� ����
    y = idx[0] - 'a';
    x = idx[1] - '1';

    for(int i = 0; i < 8; i++)
    {
        next_x = x + dx[i];
        next_y = y + dy[i];
        
        // 8x8 ����� ������ ����� ��찡 �ִٸ� ����� �� �ϳ� ����
        if((next_x < 0) || (next_x > 7) || (next_y < 0) || (next_y > 7))
        {
            cnt--;
        }
    }

    cout << cnt << endl;
}