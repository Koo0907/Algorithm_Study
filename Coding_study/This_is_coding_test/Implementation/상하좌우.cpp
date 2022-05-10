#include<iostream>
#include<string>

using namespace std;

int x = 1;  // 초기 x 좌표
int y = 1;  // 초기 y 좌표
int dx[4] = {0, 0, -1, 1};  // L-R-U-D 순서로 x축 이동 벡터
int dy[4] = {-1, 1, 0, 0};  // L-R-U-D 순서로 y축 이동 벡터

int main() {

    int N;
    char ch;
    string plan;

    cin >> N;
    cin.ignore();   // 입력 버퍼 제거
    getline(cin, plan); // 공백을 포함한 문자열 입력

    for(int i = 0; i < plan.length(); i++)
    {
        ch = plan[i];
        
        switch(ch)
        {
            case 'L':
            {
                if(y == 1)
                {
                    break;
                }
                x += dx[0];
                y += dy[0];
                break;
            }
            case 'R':
            {
                if(y == N)
                {
                    break;
                }
                x += dx[1];
                y += dy[1];
                break;
            }
            case 'U':
            {
                if(x == 1)
                {
                    break;
                }
                x += dx[2];
                y += dy[2];
                break;
            }
            case 'D':
            {
                if(x == N)
                {
                    break;
                }
                x += dx[3];
                y += dy[3];
                break;
            }
        }
    }
	
    cout << x <<" "<< y << endl;
}