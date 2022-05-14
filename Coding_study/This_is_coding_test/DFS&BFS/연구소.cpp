#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 8

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int M = 0;
int cnt = 0;
int res = 0;
int real_res = 0;

// 초기 연구소 맵
int map[MAX][MAX];

// 벽 세운 뒤의 연구소 맵
int temp[MAX][MAX];

// 안전 영역 계산
void count_safety(void)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(temp[i][j] == 0)
            {
                res++;
            }
        }
    }
}

// 바이러스 확산 함수
void spread_virus(int x, int y)
{
    // 바이러스가 확산된 지역은 3으로 표시하여 방문했다는 것을 체크
    temp[x][y] = 3;

    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        // 바이러스가 있는 영역에서 인접한 영역이 0인지 확인
        if(temp[next_x][next_y] == 0)
        {
            // 다음 영역이 map을 벗어나지 않았다면 함수 호출
            if(next_x >= 0 && next_x < N && next_y >= 0 && next_y < M)
            {
                spread_virus(next_x, next_y);
            }
        }
    }
}

// 벽 세우는 함수
void wall(void)
{
    // 벽을 모두 세웠다면 아래 로직 수행
    if(cnt == 3)
    {
        // 원본 map의 내용을 temp map에 복사
        for(int i = 0; i < N; i++)
        {
            for(int j =0; j < M; j++)
            {
                temp[i][j] = map[i][j];
            }
        }

        // 바이러스가 있는 영역이 확인되면 바이러스 확산 함수 호출
        for(int i = 0; i < N; i++)
        {
            for(int j =0; j < M; j++)
            {
                if(temp[i][j] == 2)
                {
                    spread_virus(i, j);
                }
            }
        }

        // 안전 영역 계산
        count_safety();

        // 현재 계산된 안전 영역이 현재 저장되어 있는 값보다 크다면 갱신
        if(res > real_res)
        {
            real_res = res;
        }

        res = 0;
    }
    else
    {
        for(int i = 0; i< N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                if(map[i][j] == 0)
                {
                    map[i][j] = 1;
                    cnt++;

                    // 벽 세우는 함수 호출
                    wall();
                    
                    // 벽 세우는 과정이 한번 종료됐다면 세운 벽 초기화
                    map[i][j] = 0;
                    cnt--;
                }
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> map[i][j];
        }
    }

    // 벽 세우는 함수 호출
    wall();

    cout << real_res << endl;
}