#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 26

using namespace std;

// 상,하,좌,우에 대한 방향 벡터
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 사용할 변수 초기화
int N = 0;
int group_num = 0;
int group_cnt = 0;
vector<int> apt_group;

int apt[MAX][MAX];

void dfs(int x, int y)
{
    // 함수 호출 시에 해당 아파트 방문 표시
    apt[x][y] = 0;

    // 단지의 아파트 수 증가
    group_num++;

    // 상,하,좌,우 네 방향에 대해서 DFS 함수 호출 시도
    for(int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        
        // 다음 좌표들이 Map을 벗어나지 않는지 확인
        if((next_x >= 0) && (next_x < N) && (next_y >= 0) && (next_y < N))
        {
            // 다음 좌표에 아직 방문하지 않았다면 DFS 함수 호출
            if(apt[next_x][next_y] == 1)
            {
                dfs(next_x, next_y);
            }
        }
    }
}
int main() {

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 연속된 숫자에 대해서 1개씩만 입력 받도록 함
            // ex) 00110 -> 0, 0, 1, 1, 0
            scanf("%1d", &apt[i][j]);
        }
    }

    // 전체 좌표 탐색
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // 해당 좌표에 아직 방문하지 않았다면 DFS 함수 호출
            if(apt[i][j] == 1)
            {
                dfs(i, j);

                // 아파트 단지 표시
                group_cnt++;

                // dfs 함수를 통해 해당 단지의 아파트 수를 gorup_num에 저장하고 vector에 추가
                apt_group.push_back(group_num);

                // 다음 단지의 아파트 수 확인을 위해서 변수 clear
                group_num = 0;
            }
        }
    }

    // 단지의 아파트 수 오름차순 정렬
    sort(apt_group.begin(), apt_group.end());

    cout << group_cnt << endl;

    for(auto itr = apt_group.begin(); itr != apt_group.end(); ++itr)
    {
        cout << *itr << endl;
    }
}