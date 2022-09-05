#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

#define MAX 101

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
int a = 0;
int b = 0;
int m = 0;
int x = 0;
int y = 0;
int ans = -1;

// �̼��� ��Ÿ���� ���� ����Ʈ ����
vector<int> v[MAX];

// �湮 ó���� ���� �迭
bool visited[MAX];

// DFS ���� �Լ�
void dfs(int depth, int p, int c)
{
	// p ��� �湮 ó��
	visited[p] = true;

	// p�� c�� ���ٸ�(�̼��� ����� �� �ִٸ�) �Ʒ� ���� ����
	if(p == c)
	{
		// ������ �̼��� ans ����
		ans = depth;
	}

	// p ����� ���� ��ȸ
	for(int i = 0; i < v[p].size(); i++)
	{
		// ���� ����� ���� �湮���� �ʾҴٸ� �Ʒ� ���� ����
		if(visited[v[p][i]] == false)
		{
			// �̼��� 1 ������Ű�� DFS �Լ� ȣ��
			dfs((depth + 1), v[p][i], c);
		}
	}
}

int main()
{
	// ����� �� �Է�
	scanf("%d", &n);

	// �̼��� ����Ϸ��� �� ��� �Է�
	scanf("%d %d", &a, &b);

	// �̼� ������ �� �Է�
	scanf("%d", &m);

	// �̼� ������ �Է�
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);

		v[x].push_back(y);
		v[y].push_back(x);
	}

	// DFS �Լ� ȣ��
	dfs(0, a, b);

	// ans ���
	printf("%d\n", ans);

}