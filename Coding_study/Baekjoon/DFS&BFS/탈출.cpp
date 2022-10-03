#include<iostream>
#include<vector>
#include<queue>

#define MAX 50

using namespace std;

// 네 방향의 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int R = 0;
int C = 0;
int cnt = 0;
bool move_flag = false;
bool escape_flag = false;

// 맵의 데이터를 담는 배열
char map[MAX][MAX];

// 물이 차는 동작을 수행하는 함수
void water_fall(void)
{
    // 큐 선언
    queue<pair<int, int>> water_q;

    // 현재 맵 순회하여 물이 있는 구역 탐색
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            // 물이 있는 구역이 있다면 아래 로직 수행
            if(map[i][j] == '*')
            {
                // 큐에 좌표 추가
                water_q.push({i, j});
            }
        }
    }

    // 큐가 빌 때까지 순회
    while(!water_q.empty())
    {
        // 큐에서 좌표 데이터 추출 및 삭제
        int x = water_q.front().first;
        int y = water_q.front().second;
        water_q.pop();

        // 상,하,좌,우 네 방향 순회
        for(int i = 0; i < 4; i++)
        {
            // 다음 좌표 영역 계산
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 좌표 영역이 맵 상에 있는지 확인
            if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
            {
                // 다음 좌표 영역이 빈칸(.)이라면 아래 로직 수행
                if(map[next_x][next_y] == '.')
                {
                    // 다음 좌표 영역 물이 있는 구역(*)으로 갱신
                    map[next_x][next_y] = '*';
                }
            }
        }
    }
}

// 고슴도치가 이동하는 동작을 수행하는 함수
void escape(void)
{
    // 큐 선언
    queue<pair<int, int>> escape_q;

    // 현재 맵 순회하여 고슴도치가 이동한 구역 탐색
    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            // 고슴도치가 이동한 흔적이 있는 구역(S)이 있다면 아래 로직 수행
            if(map[i][j] == 'S')
            {
                // 큐에 좌표 추가
                escape_q.push({i, j});
            }
        }
    }

    // 고슴도치가 이동을 최소 한번 했다는 의미를 가지는 flag 초기화
    move_flag = false;

    // 큐가 빌 때까지 순회
    while(!escape_q.empty())
    {
        // 큐에서 좌표 데이터 추출 및 삭제
        int x = escape_q.front().first;
        int y = escape_q.front().second;
        escape_q.pop();

        // 상,하,좌,우 네 방향 순회
        for(int i = 0; i < 4; i++)
        {
            // 다음 좌표 영역 계산
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 좌표 영역이 맵 상에 있는지 확인
            if((next_x >= 0) && (next_x < R) && (next_y >= 0) && (next_y < C))
            {
                // 다음 좌표 영역이 비버의 굴(D)이라면 아래 로직 수행
                if(map[next_x][next_y] == 'D')
                {
                    // 굴에 도착했으므로 이동 확인 flag는 초기화
                    move_flag = false;

                    // 탈출 성공 확인 flag는 set
                    escape_flag = true;

                    // 함수 종료
                    return;
                }
                // 다음 좌표 영역이 빈칸(.)이라면 아래 로직 수행
                else if(map[next_x][next_y] == '.')
                {
                    // 다음 좌표 영역 고슴도치가 이동할 수 있는 구역이므로 S로 갱신
                    map[next_x][next_y] = 'S';

                    // 이동 확인 flag set
                    move_flag = true;
                }
                // 그 외의 영역은 아무 동작 하지 않음
                else
                {
                    // do nothing...
                }
            }
        }
    }
}

int main()
{
    // R, C 데이터 입력
    scanf("%d %d", &R, &C);

    // 맵 데이터 입력
    for(int i = 0; i < R; i++)
    {
        cin.ignore();
        for(int j = 0; j < C; j++)
        {
            scanf("%c",&map[i][j]);
        }
    }

    while(1)
    {
        // 물이 차는 동작 먼저 수행
        water_fall();

        // 고슴도치가 이동하는 동작 수행
        escape();

        // 이동한 횟수 증가
        cnt++;

        // 이동 확인 flag가 false 상태라면 무한반복문 탈출
        if(move_flag == false)
        {
            break;
        }
    }

    // 탈출 확인 flag가 true라면 아래 로직 수행
    if(escape_flag == true)
    {
        // 탈출 성공을 의미하므로 지금까지 이동한 횟수 출력
        printf("%d\n", cnt);
    }
    else
    {
        // 탈출 실패를 의미하므로 KAKTUS 출력
        printf("KAKTUS\n");
    }
}
