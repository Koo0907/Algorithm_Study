#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 100000

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int x = 0;
int y = 0;
int z = 0;
int ans = 0;

// �θ� ���̺�
int parent[MAX];

// �༺ x,y,z ������ ��ǥ ����
vector<pair<int, int>> v[3];

// �༺���� �Ÿ� ����
vector<pair<int, pair<int, int>>> vv;

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
	scanf("%d", &N);

	// �༺���� x,y,z ���� ��ǥ �Է�
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d %d",&x, &y, &z);
		v[0].push_back({x, i});
		v[1].push_back({y, i});
		v[2].push_back({z, i});
		parent[i] = i;
	}

	// �༺���� x,y,z ���� ��ǥ �������� ����
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	// �༺���� x,y,z ���� ��ǥ�� ������ �༺�� ��ǥ�� ���Ͽ� vv ���Ϳ� ����
	// ������ ��ǥ�� �ּ� �Ÿ��̹Ƿ� �� �̿��� ��ǥ�� Ȯ���� �ʿ� ����
	// ��� ��ǥ�� �� Ȯ���ϸ� �޸� �ʰ� �߻�
	// x���� �Ÿ��� y���� �Ÿ��� z���� �Ÿ� �߿��� ���� �ּҰ��� �༺�� �մ� ������� ����
	for(int i = 0; i < (N - 1); i++)
	{
		vv.push_back({abs(v[0][i].first - v[0][i + 1].first), {v[0][i].second, v[0][i + 1].second}});
		vv.push_back({abs(v[1][i].first - v[1][i + 1].first), {v[1][i].second, v[1][i + 1].second}});
		vv.push_back({abs(v[2][i].first - v[2][i + 1].first), {v[2][i].second, v[2][i + 1].second}});
	}

	// �༺���� �Ÿ� �������� ����
	sort(vv.begin(), vv.end());

	for(int i = 0; i < vv.size(); i++)
	{
		// dis�� �� �༺�� ������ �Ÿ�
		// x,y�� �� �༺�� ��ȣ
		int dis = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;

		// ��ȸ�ϴ� �� �༺�� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
		if(find_parent(a) != find_parent(b))
		{
			// �� �༺ union ����
			union_parent(a, b);

			// �Ÿ� ����
			ans += dis;
		}
	}

	printf("%d\n", ans);
}