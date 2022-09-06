#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 50

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int root = 0;
int exclude_node = 0;
int cnt = 0;

// ��� ���� ����Ʈ ����
vector<int> v[MAX];

// �湮 ó�� �迭
bool visited[MAX];

// DFS ���� �Լ�
void dfs(int node)
{
	// ��ȸ�ϴ� ��尡 ���� ����� �ٷ� return
	if(node == exclude_node)
	{
		return;
	}

	// ���� ��� �湮 ó��
	visited[node] = true;

	// ���� ��忡 ����Ǿ� �ִ� �ڽ� ��尡 ������ Ȯ��
	if(v[node].size() == 0)
	{
		// �ڽ� ��尡 ���ٸ� ���� ����̹Ƿ� cnt ����
		cnt++;
	}

	// ���� ��忡 ����Ǿ� �ִ� �ڽ� ��尡 1������ Ȯ��
	if(v[node].size() == 1)
	{
		// 1�� �ִ� �ڽ� ��尡 ���� ����� ���� ���� �ᱹ ���� ��尡 �ǹǷ� cnt ����
		if(v[node][0] == exclude_node)
		{
			cnt++;
		}
	}

	// �ڽ� ��� ��ȸ
	for(int i = 0; i < v[node].size(); i++)
	{
		int next_node = v[node][i];

		// �ڽ� ��带 ���� �湮���� �ʾҴٸ� DFS �Լ� ȣ��
		if(visited[next_node] == false)
		{
			dfs(next_node);
		}
	}
}

int main()
{
	scanf("%d",&N);

	for(int i = 0; i < N; i++)
	{
		int num;
		scanf("%d", &num);

		// -1�� �ԷµǴ� ��ȣ�� ��尡 ��Ʈ��Ʈ
		if(num == -1)
		{
			root = i;
		}
		else
		{
			// �θ�-�ڽ� �����̹Ƿ� �ܹ��� ����
			v[num].push_back(i);
		}
	}

	// ���� ��� �Է�
	scanf("%d", &exclude_node);

	// ��Ʈ��忡������ DFS �Լ� ȣ��
	dfs(root);

	cout << cnt << endl;
}