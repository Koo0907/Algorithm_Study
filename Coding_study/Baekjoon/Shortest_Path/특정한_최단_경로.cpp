#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9 // ������ �ǹ��ϴ� ������ 10���� ����

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int E = 0;
int a = 0;
int b = 0;
int c = 0;
int v1 = 0;
int v2 = 0;
int ans = 0;

// ���� ������ ������ pair ��ҷ� �����ϴ� ���� �迭
vector<pair<int, int>> graph[801];

// �ִܰŸ� ���̺�
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
	// �ִܰŸ� ���̺� �ʱ�ȭ
	clear_graph();

	// {�Ÿ�, �������} pair�� ��ҷ� ������ �ּ� �� �켱���� ť ����
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// ���۳�忡 ���� ��� ����
	pq.push({0, start});

	// �ִܰŸ� ���̺� ����
	dis[start] = 0;

	// ť�� �� ������ �ݺ�
	while(!pq.empty())
	{
		// cost�� �켱���� ť���� ���� ª�� �Ÿ�
		// node�� �켱���� ť���� �Ÿ��� ���� ª�� pair�� ���
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// cost ���� ���� �ִܰŸ� ���̺� ����� ������ ũ�ٸ� �ش� ���� �湮�� �Ͱ� ����
		if(cost > dis[node])
		{
			continue;
		}

		// �����忡 ����Ǿ� �ִ� ���� ��ȸ
		for(int i = 0; i < graph[node].size(); i++)
		{
			// next_node�� �����忡�� ����Ǿ� �ִ� ���
			// next_cost�� ���۳�忡�� ����������� �Ÿ��� �����忡�� ����Ǿ� �ִ� �������� �Ÿ��� ��
			int next_node = graph[node][i].first;
			int next_cost = cost + graph[node][i].second;

			// next_cost�� �ִܰŸ� ���̺��� ������ �۴ٸ� �Ʒ� ���� ����
			if(next_cost < dis[next_node])
			{
				// �ִܰŸ� ���̺� ����
				dis[next_node] = next_cost;

				// �켱���� ť�� ����
				pq.push({next_cost, next_node});
			}
		}
	}
}

// �Ķ���� ������� �ִܰŸ� ���
int find_path(int start, int through1, int through2, int end)
{
	int path = 0;

	dijkstra(start);
	path += dis[through1];
	// �ִܰŸ��� INF �̻��̶�� -1 ��ȯ
	if(path >= INF)
	{
		return -1;
	}

	dijkstra(through1);
	path += dis[through2];
	// �ִܰŸ��� INF �̻��̶�� -1 ��ȯ
	if(path >= INF)
	{
		return -1;
	}

	dijkstra(through2);
	path += dis[end];
	// �ִܰŸ��� INF �̻��̶�� -1 ��ȯ
	if(path >= INF)
	{
		return -1;
	}
	
	// ������ �ִܰŸ��� �� ��ȯ
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

	// 1->v1->v2->N�� �ִܰŸ��� 1->v2->v1->N�� �ִܰŸ� �� ���� �� ����
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