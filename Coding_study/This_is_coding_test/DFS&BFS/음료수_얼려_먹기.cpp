#include<iostream>

#define MAX 1000

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int M = 0;
int N = 0;
int cnt = 0;

int ice[MAX][MAX];

void dfs(int x, int y)
{
    // 함수 호출 시에 해당 인덱스 방문 표시
    ice[x][y] = 1;

    // 상,하,좌,우 네 방향에 대해서 DFS 함수 호출 시도
    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // 다음 좌표들이 Map을 벗어나지 않는지 확인
        if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < M))
        {
            // 다음 좌표에 아직 방문하지 않았다면 DFS 함수 호출
            if(ice[next_x][next_y] == 0)
            {
                dfs(next_x, next_y);
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
            scanf_s("%1d", &ice[i][j]);
        }
    }

    // 전체 좌표 탐색
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            // 해당 좌표에 아직 방문하지 않았다면 DFS 함수 호출
            if(ice[i][j] == 0)
            {
                dfs(i, j);
                cnt++;
            }
        }
    }

    cout << cnt << endl;
}