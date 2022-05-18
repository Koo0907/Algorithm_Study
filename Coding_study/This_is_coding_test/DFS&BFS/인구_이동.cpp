#include<iostream>
#include<queue>
#include<cstring>

#define MAX 50

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수들 초기화
int N = 0;
int L = 0;
int R = 0;
int cnt = 0;
int uni_cnt = 0;
int sum = 0;
unsigned char check_flag = 0;

int map[MAX][MAX];
int visited[MAX][MAX];

// 두 나라의 인구 차이를 구하는 함수
int abs(int x, int y)
{
    if(x > y)
    {
        return x - y;
    }
    else
    {
        return y - x;
    }
}

void move_popul(int x, int y)
{
    // 순회를 위한 큐
    queue<pair<int, int>> q;

    // 연합을 통한 인구 이동을 위한 큐
    queue<pair<int, int>> united_q;

    // 해당 함수 호출된다면 방문 처리
    visited[x][y] = 1;

    q.push({x, y});

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 상, 하, 좌, 우 방향으로 순회
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 영역이 map을 벗어나지 않는지 확인
            if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
            {
                // 다음 영역을 이미 방문했었는지 확인
                if(visited[next_x][next_y] == 0)
                {
                    int dif = abs(map[x][y], map[next_x][next_y]);

                    // 두 나라의 인구 차이가 L과 R 사이인지 확인
                    if((dif >= L) && (dif <= R))
                    {
                        // 다음 영역 방문 처리
                        visited[next_x][next_y] = 1;

                        // 큐 추가
                        q.push({next_x, next_y});

                        // 만일 최초로 발견된 연합이라면 기존의 영역(x, y)도 인구 이동을 위한 큐에 추가
                        // 인구 이동에 최초 순회한 영역의 인구 계산도 필요하기 때문
                        if(united_q.size() == 0)
                        {
                            united_q.push({x, y});
                            uni_cnt++;
                            sum += map[x][y];
                        }

                        // 다음 영역을 인구 이동을 위한 큐에 추가
                        united_q.push({next_x, next_y});

                        // 연합 수 및 총 인구수 계산
                        uni_cnt++;
                        sum += map[next_x][next_y];                     
                    }
                }
            }
        }
    }

    // 인구 이동을 위한 큐에 값이 존재한다면(=연합이 이루어졌다면) 아래 로직 추가
    if(united_q.size() > 0)
    {
        // 현재 영역에서 연합이 이루졌음을 체크하는 flag set
        // flag의 값을 누적시켜서 증가
        check_flag++;
        while(!united_q.empty())
        {
            int x = united_q.front().first;
            int y = united_q.front().second;
            united_q.pop();
            map[x][y] = (sum / uni_cnt);
        }

        // 인구 이동이 끝나면 연합 수와 총 인구수 clear
        uni_cnt = 0;
        sum = 0;
    }
}

int main()
{
    cin >> N >> L >> R;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    while(1)
    {
        // 순회를 하기 전에 방문 확인 배열 및 연합 유무 flag clear
        memset(visited, 0, sizeof(visited));
        check_flag = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j< N; j++)
            {
                if(visited[i][j] == 0)
                {
                    move_popul(i, j);
                }
            }
        }

        // 모든 영역들을 확인했음에도 한번도 연합이 이루어지지 않았다면 반복문 탈출
        if(check_flag == 0)
        {
            break;
        }

        cnt++;
    }

    cout << cnt << endl;
}