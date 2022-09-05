#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 100001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int a = 0;
int b = 0;

// ���� ����Ʈ�� ���� ����
vector<int> vec[MAX];

// �湮 ó���� ���� �迭
bool visited[MAX];

// �θ� ��� �迭
int parent[MAX];

// DFS ���� �Լ�
void dfs(int x)
{
	// �Ķ���� x �� �湮 ó��
	visited[x] = true;

	// x�� ����Ǿ� �ִ� ���� ��ȸ
	for(int i = 0; i < vec[x].size(); i++)
	{
		// ���� ��� Ž��
		int next_x = vec[x][i];

		// ���� ��带 ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
		if(visited[next_x] == false)
		{
			// DFS �Լ� ȣ��
			dfs(next_x);

			// �θ� ��� ����
			parent[next_x] = x;
		}
	}
}

int main()
{
	scanf("%d",&N);

	for(int i = 0; i < (N - 1); i++)
	{
		scanf("%d %d", &a, &b);
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	// ��Ʈ ����� 1���� DFS �Լ� ȣ��
	dfs(1);

	// �θ� ��� ���
	for(int i = 2; i <= N; i++)
	{
		printf("%d\n",parent[i]);
	}
}