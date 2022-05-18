/* 백준 링크 */
/* https://www.acmicpc.net/problem/18428 */

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 6

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int cnt = 0;
bool check_flag = true;

// 초기 주어지는 학생들과 선생님들의 위치 map
char map[MAX][MAX];

// 장애물 세 개를 설치한 뒤의 학생들과 선생님들의 위치 map
char temp[MAX][MAX];

// dir 인수에 따라 한 방향으로 탐색하여 학생이 있는지 확인하는 함수
void check_direction(int x, int y, int dir)
{
    int next_x = x + dx[dir];
    int next_y = y + dy[dir];

    // 다음 영역이 map을 벗어나지 않는다면 그 방향에 학생이 있는지 확인
    if(next_x >= 0 && next_x < N && next_y >=0 && next_y < N)
    {
        // 다음 영역이 빈 영역이라면 재귀호출
        if(temp[next_x][next_y] == 'X')
        {
            check_direction(next_x, next_y, dir);
        }
        // 다음 영역에 학생이 있다면 flag를 clear
        else if(temp[next_x][next_y] == 'S')
        {
            check_flag = false;
        }
        // 다음 영역이 장애물('O')라면 재귀호출하지 않을테니 따로 확인하지 않아도 무방함
    }
}

// 선생님('T')이 있는 위치에서 상,하,좌,우 방향으로 map 끝까지 학생이 있는 확인하는 함수
void check(int x, int y)
{
    for(int i = 0; i < 4; i++)
    {
        // 현재 영역을 기준으로 각 방향에 학생이 있는지 확인하는 함수 호출
        check_direction(x, y, i);
    }
}

// 장애물 설치 함수
void obstacle(void)
{
    // 장애물을 모두 설치했다면 아래 로직 수행
    if(cnt == 3)
    {
        // 장애물이 설치된 경우마다 감시 영역이 있는지 확인해야 하므로 확인 전에 flag set
        check_flag = true;

        // 원본 map의 내용을 temp map에 복사
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                temp[i][j] = map[i][j];
            }
        }

        // 선생님이 있는 영역을 확인되면 상,하,좌,우 방향에 학생들이 있는지 확인하는 함수 호출
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(temp[i][j] == 'T')
                {
                    check(i, j);
                }
            }
        }

        // 이번 장애물이 설치된 경우에 flag가 clear되지 않았다면 감시 영역이 존재한다는 의미므로 return
        if(check_flag == true)
        {
            return;
        }
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(map[i][j] == 'X')
                {
                    map[i][j] = 'O';
                    cnt++;

                    // 장애물 설치 함수 호출
                    obstacle();

                    // 장애물을 모두 설치하고 모든 체크가 끝난 이후에도 flag가 clear되지 않았다면 감시 영역이 존재한다는 의미므로 return
                    if(check_flag == true)
                    {
                        return;
                    }

                    // 장애물 설치 후 모든 체크가 종료됐다면 설치한 장애물 초기화
                    map[i][j] = 'X';
                    cnt--;
                }
            }
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    // 장애물 설치 함수 호출
    obstacle();

    // 감시 영역의 유무를 의미하는 flag 값에 따라 출력
    if(check_flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}