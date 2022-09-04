#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int cnt = 0;

// �湮 üũ �迭
bool visited[MAX];

// �׷����� ���� ����Ʈ ����
vector<int> vec[MAX];

// DFS ���� �Լ�
void dfs(int x)
{
	// x ���� �湮ó��
	visited[x] = true;

	// x ������ ����Ǿ� �ִ� ���� �� ��ŭ ��ȸ
	for(int i = 0; i < vec[x].size(); i++)
	{
		// ���� ���� Ž��
		int next_x = vec[x][i];

		// ���� ������ ���� �湮���� �ʾҴٸ� DFS ����
		if(visited[next_x] == false)
		{
			dfs(next_x);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);

		// ������ �׷����̹Ƿ� �� �ʿ� ��� ���� �߰�
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	// �湮 �迭 �ʱ�ȭ
	memset(visited, false, MAX);

	for(int i = 1; i <= N; i++)
	{
		// ������ ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
		if(visited[i] == false)
		{
			// DFS ����
			dfs(i);

			// ���� ��� �� ����
			cnt++;
		}
	}

	cout << cnt << endl;
}