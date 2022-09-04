#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define MAX 10001

using namespace std;

// ����� ���� �ʱ�ȭ
int V = 0;
int E = 0;
int A = 0;
int B = 0;
int C = 0;
int ans = 0;

// �θ� ���̺�
int parent[MAX];

// ��� ������ ����
vector<pair<int, pair<int, int>>> v;

// find ����
int find_parent(int a)
{
	// a�� �θ� a��� ��Ʈ����� �ǹ�
	if(a == parent[a])
	{
		return a;
	}
	// a�� �θ� a�� �ƴ϶�� �θ� ���̺� ���� �� ���ȣ��
	else
	{
		return parent[a] = find_parent(parent[a]);
	}
}

// union ����
void union_parent(int a, int b)
{
	// a,b�� �θ� ã��
	a = find_parent(a);
	b = find_parent(b);

	// �� ���� ���� �θ� �ǵ��� ����
	if(a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

int main()
{
	scanf("%d %d",&V, &E);

	for(int i = 0; i < E; i++)
	{
		scanf("%d %d %d",&A, &B, &C);
		v.push_back({C, {A, B}});
	}

	// �θ� ���̺��� �ڽ����� �ʱ�ȭ
	for(int i = 1; i <= V; i++)
	{
		parent[i] = i;
	}

	// ��� �������� ����
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		// cost�� �� ��带 �մ� ���
		// a�� b�� �� ���
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// ��ȸ�ϴ� �� ����� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{
			// �� ��� union ����
			union_parent(a, b);

			// ��� ����
			ans += cost;
		}
	}

	cout << ans << endl;
}