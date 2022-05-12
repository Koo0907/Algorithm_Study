#include<iostream>
#include<queue>

#define MAX 201

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int M = 0;

int map[MAX][MAX] = {0};
queue<pair<int,int>> path;

void find_path(int x, int y)
{
    // 함수 호출되면 queue에 좌표 추가
    path.push({x, y});

    // queue가 비어질 때 까지 반복
    while(!path.empty())
    {
        // 현재 queue에 있는 좌표 추출하고 삭제
        x = path.front().first;
        y = path.front().second;
        path.pop();

        // 상,하,좌,우 네 방향에 대해서 BFS 호출 시도
        for(int i = 0; i < 4; i++)
        {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

            // 다음 좌표들이 Map을 벗어나지 않는지 확인
            if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
            {
                // 다음 좌표의 값이 1인지 확인(= 괴물이 없는지)
                if(map[next_x][next_y] == 1)
                {
                    // queue에 다음 좌표 추가
                    path.push({next_x, next_y});

                    // 다음 좌표의 값을 현재 좌표값의 +1하여 경로 횟수 추가
                    map[next_x][next_y] = map[x][y] + 1;
                }
            }
        }
    }
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 연속된 숫자에 대해서 1개씩만 입력 받도록 함
            // ex) 00110 -> 0, 0, 1, 1, 0
            scanf("%1d",&map[i][j]);
        }
    }

    find_path(0,0);

    cout << map[N - 1][M - 1] << endl;
}