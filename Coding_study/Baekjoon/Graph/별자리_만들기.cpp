#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 100

using namespace std;

// ����� ���� �ʱ�ȭ
int n = 0;
double x = 0;
double y = 0;
double ans = 0;

// �θ� ���̺�
int parent[MAX];

// ������ ��ǥ ����
vector<pair<double, double>> v;

// ���� ������ �Ÿ� ����
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

int main()
{
	scanf("%d", &n);

	// ������ ��ǥ �Է�
	for(int i = 0; i < n; i++)
	{
		scanf("%lf %lf",&x, &y);
		v.push_back({x, y});
	}

	// ���� ������ �Ÿ� ����ϰ� vv ���Ϳ� �߰�
	for(int i = 0; i < n; i++)
	{
		double a = v[i].first;
		double b = v[i].second;

		for(int j = i + 1; j < n; j++)
		{
			double aa = v[j].first;
			double bb = v[j].second;
			double path = sqrt(pow(aa - a, 2) + pow(bb - b, 2));

			vv.push_back({path, {i, j}});
		}
	}

	// �θ� ���̺� �ʱ�ȭ
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	// ������ �Ÿ� �������� ����
	sort(vv.begin(), vv.end());

	for(int i = 0; i < vv.size(); i++)
	{
		// dis�� �� ���� ������ �Ÿ�
		// x,y�� �� ���� ��ȣ
		double dis = vv[i].first;
		x = vv[i].second.first;
		y = vv[i].second.second;

		// ��ȸ�ϴ� �� ���� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(x) != find_parent(y))
		{
			// �� �� union ����
			union_parent(x, y);

			// �Ÿ� ����
			ans += dis;
		}
	}

	printf("%.2lf\n", ans);
}