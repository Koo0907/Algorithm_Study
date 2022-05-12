#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 101

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int cnt = 0;

vector<int> virus[MAX];
bool visited[MAX];

void find_virus(int x)
{
    // 함수 호출 시 방문 체크
    visited[x] = true;

    // 해당 인덱스 vector에 연결되어 있는 간선 수(=vector.size())만큼 순회
    for(int i = 0; i < virus[x].size(); i++)
    {
        int next_x = virus[x][i];

        // 다음 노드에 대해서 방문하지 않았다면 dfs 함수 호출
        if(visited[next_x] == false)
        {
            find_virus(next_x);

            // 1번 노드와 연결되어 있다면 cnt 증가
            cnt++;
        }
    }

}
int main() {

    cin >> M >> N;

    for(int i = 0; i < N; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        virus[n1].push_back(n2);
        virus[n2].push_back(n1);
    }

    // 1번 노드에서부터 시작
    find_virus(1);

    cout << cnt << endl;
}