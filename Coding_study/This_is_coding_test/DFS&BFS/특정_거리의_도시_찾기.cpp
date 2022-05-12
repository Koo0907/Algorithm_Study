#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int K = 0;
int X = 0;

// 노드 연결리스트를 위한 vector
vector<int> vec[300001];

// 방문 확인을 위한 배열
bool visited[300001];

// 결과값 출력할 vector
vector<int> res;

// 노드 번호와 최단거리 수를 pair로 저장한 queue
queue<pair<int, int>> path;

void find_path(int x)
{
    // 함수 호출되면 방문 확인
    visited[x] = true;

    path.push({ x, 0 });

    while (!path.empty())
    {
        int cur = path.front().first;
        int way = path.front().second;
        path.pop();

        // 현재 확인하는 노드의 최단거리 수가 K라면 res vector에 추가
        if (way == K)
        {
            res.push_back(cur);
        }

        // 현재 확인하는 노드에 연결된 노드들 순회
        for (int i = 0; i < vec[cur].size(); i++)
        {
            int next_x = vec[cur][i];
            
            // 다음 노드를 아직 방문하지 않았다면 queue에 삽입
            if (visited[next_x] == false)
            {
                // 방문 확인
                visited[next_x] = true;

                // 다음 노드와 그 노드의 최단거리(현재 노드의 최단거리 + 1)를 pair로 추가
                path.push({ next_x, way + 1 });
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vec[n1].push_back(n2);
    }

    find_path(X);

    // 결과값을 추가한 vector 오름차순 정렬
    sort(res.begin(), res.end());

    // res vector 비어있다면 -1 출력. 값이 있다면 해당 노드 번호 출력
    if (res.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto itr = res.begin(); itr != res.end(); ++itr)
        {
            cout << *itr << endl;
        }
    }
}