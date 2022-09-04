#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
long long ans = 0;	// ����� ���� int���� ������ ���� �� �����Ƿ� long long Ÿ�� ����

// �༺���� �÷ο� ���� ��� �迭
int map[MAX][MAX];

// �θ� ���̺�
int parent[MAX];

// �༺ �� ��� ������ ����
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
	scanf("%d",&N);

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			scanf("%d", &map[i][j]);
			
			// j�� i���� ū ��쿡�� ��ȿ�� �ʿ� ��� �������̹Ƿ� ���Ϳ� �߰�
			if(j > i)
			{
				v.push_back({map[i][j], {i, j}});
			}
		}
	}

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// ��� �������� ����
	sort(v.begin(), v.end());

	for(int i = 0; i < v.size(); i++)
	{
		// cost�� �༺ ���� �÷ο� ���� ���
		// a,b�� �� �༺
		int cost = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// ��ȸ�ϴ� �� �༺�� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{
			// �� �༺ union ����
			union_parent(a, b);

			// ��� ����
			ans += cost;
		}
	}
		cout << ans << endl;
}