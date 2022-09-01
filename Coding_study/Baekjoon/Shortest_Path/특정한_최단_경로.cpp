#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int E = 0;
int a = 0;
int b = 0;
int c = 0;
int v1 = 0;
int v2 = 0;
int ans = 0;

// 노드와 간선의 정보를 pair 요소로 저장하는 벡터 배열
vector<pair<int, int>> graph[801];

// 최단거리 테이블
int dis[801];

void clear_graph(void)
{
	for(int i = 1; i <= N; i++)
	{
		dis[i] = INF;
	}
}

void dijkstra(int start)
{
	// 최단거리 테이블 초기화
	clear_graph();

	// {거리, 도착노드} pair를 요소로 가지는 최소 힙 우선순위 큐 선언
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 시작노드에 대한 요소 삽입
	pq.push({0, start});

	// 최단거리 테이블 갱신
	dis[start] = 0;

	// 큐가 빌 때까지 반복
	while(!pq.empty())
	{
		// cost는 우선순위 큐에서 가장 짧은 거리
		// node는 우선순위 큐에서 거리가 가장 짧은 pair의 노드
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// cost 값이 현재 최단거리 테이블에 저장된 값보다 크다면 해당 노드는 방문한 것과 동일
		if(cost > dis[node])
		{
			continue;
		}

		// 현재노드에 연결되어 있는 노드들 순회
		for(int i = 0; i < graph[node].size(); i++)
		{
			// next_node는 현재노드에서 연결되어 있는 노드
			// next_cost는 시작노드에서 현재노드까지의 거리와 현재노드에서 연결되어 있는 노드까지의 거리의 합
			int next_node = graph[node][i].first;
			int next_cost = cost + graph[node][i].second;

			// next_cost가 최단거리 테이블의 값보다 작다면 아래 로직 수행
			if(next_cost < dis[next_node])
			{
				// 최단거리 테이블 갱신
				dis[next_node] = next_cost;

				// 우선순위 큐에 삽입
				pq.push({next_cost, next_node});
			}
		}
	}
}

// 파라미터 순서대로 최단거리 계산
int find_path(int start, int through1, int through2, int end)
{
	int path = 0;

	dijkstra(start);
	path += dis[through1];
	// 최단거리가 INF 이상이라면 -1 반환
	if(path >= INF)
	{
		return -1;
	}

	dijkstra(through1);
	path += dis[through2];
	// 최단거리가 INF 이상이라면 -1 반환
	if(path >= INF)
	{
		return -1;
	}

	dijkstra(through2);
	path += dis[end];
	// 최단거리가 INF 이상이라면 -1 반환
	if(path >= INF)
	{
		return -1;
	}
	
	// 구해진 최단거리의 합 반환
	return path;
}

int main()
{
	scanf("%d %d",&N, &E);

	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d",&a, &b, &c);
		graph[a].push_back({b, c});
		graph[b].push_back({a, c});
	}

	scanf("%d %d", &v1, &v2);

	// 1->v1->v2->N의 최단거리와 1->v2->v1->N의 최단거리 중 작은 값 추출
	ans = min(find_path(1, v1, v2, N), find_path(1, v2, v1, N));

	if(ans > INF)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
}