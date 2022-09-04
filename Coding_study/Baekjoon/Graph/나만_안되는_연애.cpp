#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1000

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
char S = 0;
int u = 0;
int v = 0;
int d = 0;
int cnt = 0;
int ans = 0;

// �θ� ���̺�
int parent[MAX];

// ����,���� ���̺�
char ManWoman[MAX];

// ��� ������ ����
vector<pair<int, pair<int, int>>> vec;

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
	scanf("%d %d",&N, &M);

	for(int i = 1; i <= N; i++)
	{
		cin.ignore();		// �Է� ���� ����
		scanf("%c", &S);	// ����, ���� ���� �Է�
		ManWoman[i] = S;	// ����, ���� ���̺� ����
		parent[i] = i;		// �θ� ���̺� �ʱ�ȭ
	}

	// ��� ������ �Է�
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &d);
		vec.push_back({d, {u, v}});
	}

	// ��� �������� ����
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++)
	{
		// dist�� �� �б��� ��� ����
		// a�� b�� �� �б�
		int dist = vec[i].first;
		int a = vec[i].second.first;
		int b = vec[i].second.second;

		// ����Ǿ� �ִ� �� �б��� �ٸ� ���� ������ �ִٸ� �Ʒ� ���� ����
		if(ManWoman[a] != ManWoman[b])
		{
			// ��ȸ�ϴ� �� �б��� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
			if(find_parent(a) != find_parent(b))
			{
				// �� ��� union ����
				union_parent(a, b);
				
				// ��� ����
				ans += dist;

				// ��� �� ����
				cnt++;
			}
		}
	}

	// ��� ���� N-1����� ��� �б� �������� �ǹ�
	if(cnt == N - 1)
	{
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}