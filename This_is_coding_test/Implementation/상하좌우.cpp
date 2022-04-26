#include<iostream>
#include<string>

using namespace std;

int x = 1;  // �ʱ� x ��ǥ
int y = 1;  // �ʱ� y ��ǥ
int dx[4] = {0, 0, -1, 1};  // L-R-U-D ������ x�� �̵� ����
int dy[4] = {-1, 1, 0, 0};  // L-R-U-D ������ y�� �̵� ����

int main() {

    int N;
    char ch;
    string plan;

    cin >> N;
    cin.ignore();   // �Է� ���� ����
    getline(cin, plan); // ������ ������ ���ڿ� �Է�

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