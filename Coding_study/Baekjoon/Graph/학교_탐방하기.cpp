#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int A = 0;
int B = 0;
int C = 0;
int cnt = 0;
int max_val = 0;
int min_val = 0;

// �θ� ���̺�
int parent[MAX];

// �б� �ǹ� ������ ����
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

// �������� ������ ���� cmp �Լ�
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first > b.first;
}

// MST ���ϱ� ���� ũ�罺Į �˰��� ���� �Լ�
int kruskal(void)
{
	for(int i = 0; i < v.size(); i++)
	{
		// tired�� 0(������), 1(������)���� Ȯ��
		// a, b�� �� �ǹ�
		int tired = v[i].first;
		int a = v[i].second.first;
		int b = v[i].second.second;

		// ��ȸ�ϴ� �� �ǹ��� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{
			// �� �ǹ� union ����
			union_parent(a, b);

			// �� �ǹ��� �մ� ��ΰ� 0(������)�̸� cnt ����
			if(tired == 0)
			{
				cnt++;
			}
		}
	}

	// �Ƿε� ��ȯ
	return (cnt * cnt);
}
int main()
{
	scanf("%d %d",&N, &M);

	for(int i = 0; i < M + 1; i++)
	{
		scanf("%d %d %d", &A, &B, &C);
		v.push_back({C, {A, B}});
	}

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	// ��� �������� ����
	sort(v.begin(), v.end());

	// ������������ ���������Ƿ� �Ƿε��� ���� ���� �ڽ�
	max_val = kruskal();

	// cnt �ʱ�ȭ
	cnt = 0;

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 0; i <= N; i++)
	{
		parent[i] = i;
	}

	// ��� �������� ����
	sort(v.begin(), v.end(), cmp);
	
	// ������������ ���������Ƿ� �Ƿε��� ���� ���� �ڽ�
	min_val = kruskal();

	// �� �ڽ��� ���� ���
	cout << max_val - min_val << endl;
}