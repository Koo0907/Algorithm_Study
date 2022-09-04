#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;
double ans = 0;

// �θ� ���̺�
int parent[MAX];

// ��ǥ ����
vector<pair<int, int>> v;

// �̹� ����� �ŵ��� ����
vector<pair<int, int>> alv;

// �ŵ���� �Ÿ� ����
vector<pair<double, pair<int, int>>> vv;

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

// �̹� ����� �ŵ鿡 ���ؼ� union ����
void union_already()
{
	for(int i = 0; i < alv.size(); i++)
	{
		// ��ȸ�ϴ� �� �ŵ��� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(alv[i].first) != find_parent(alv[i].second))
		{
			// �� �ŵ� union ����
			union_parent(alv[i].first, alv[i].second);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	// �ŵ��� ��ǥ �Է�
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}

	// �̹� ����Ǿ� �ִ� �ŵ� �Է�
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		alv.push_back({a, b});
	}

	// �ŵ��� ��� ���� ����ϰ� vv ���Ϳ� �߰�
	for(int i = 0; i < N; i++)
	{
		double a = v[i].first;
		double b = v[i].second;

		for(int j = i + 1; j < N; j++)
		{
			double aa = v[j].first;
			double bb = v[j].second;
			double dis = sqrt(pow(aa - a, 2) + pow(bb - b, 2));

			vv.push_back({dis,{i + 1, j + 1}});
		}
	}

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// ��� ���� �������� ����
	sort(vv.begin(), vv.end());

	// �̹� ����� �ŵ��� �̸� union ���� ����
	union_already();

	for(int i = 0; i < vv.size(); i++)
	{
		// path�� �� �ŵ��� ��� ����
		// a, b�� �� �ŵ�
		double path = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;

		// ��ȸ�ϴ� �� �ŵ��� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{

			// �� �ŵ� union ����
			union_parent(a, b);

			// ���� ����
			ans += path;
		}
	}

	printf("%.2lf\n", ans);
}