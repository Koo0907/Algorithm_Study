#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int K = 0;
int u = 0;
int v = 0;
int w = 0;
int ans = 0;

// �θ� ���̺�
int parent[MAX];

// ������ ���� �迭
int generation[MAX];

// ��� ������ ����
vector<pair<int, pair<int, int>>> vec;

// ��� ������ �θ��尡 ������ ���õ��� �θ������� Ȯ��
bool check_generation(void)
{
	for(int i = 1; i <= N; i++)
	{
		if(parent[i] != 0)
		{
			return false;
		}
	}
	
	return true;
}

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
	scanf("%d %d %d", &N, &M, &K);

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// ������ ���� �Է�
	for(int i = 0; i < K; i++)
	{
		scanf("%d",&generation[i]);

		// ������ ���õ��� �̸� �ֻ��� �켱������ 0���� �θ��带 �����ؼ� union ������
		parent[generation[i]] = 0;
	}

	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &w);
		vec.push_back({w, {u, v}});
	}

	// ��� �������� �迭
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++)
	{
		// cost�� �� ������ ��� ����
		// a,b�� �� ����
		int cost = vec[i].first;
		int a = vec[i].second.first;
		int b = vec[i].second.second;

		// ��ȸ�ϴ� �� ������ �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{
			// �� ���� union ����
			union_parent(a, b);
			
			// ��� ����
			ans += cost;
		}

		// ��ȸ�� ���������� ��� ������ �θ��尡 ������ ������ �θ���� ������ Ȯ��
		if(check_generation())
		{
			break;
		}
	}

	cout << ans << endl;
}