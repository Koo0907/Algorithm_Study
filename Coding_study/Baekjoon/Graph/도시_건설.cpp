#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 101010

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;
long long all_path = 0;
long long minimum_path = 0;
int cnt = 0;

// �θ� ���̺�
int parent[MAX];

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
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);  // ��� ������ �Է�
        vec.push_back({c, {a, b}});     // ��� ������ ����
        all_path += c;                  // ��� ��� ���� ���
    }

    for(int i = 1; i <= N; i++)
    {
        // �θ� ���̺� �ʱ�ȭ
        parent[i] = i;
    }

    // ��� �������� ����
    sort(vec.begin(), vec.end());

    // ��ε� ��ȸ
    for(int i = 0; i < vec.size(); i++)
    {
        // a, b�� �ǹ�
        // dis�� �� �ǹ��� ����
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        int dis = vec[i].first;

        // ��ȸ�ϴ� �� �ǹ��� �θ� ���̺��� �ٸ��ٸ�(����Ŭ�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
        if(find_parent(a) != find_parent(b))
        {
            // �� �ǹ� union ����
            union_parent(a, b);

            // �ּ� ��� ����
            minimum_path += dis;

            // ��� �� ����
            cnt++;
        }
    }

    // ��� ���� N-1����� ��� �ǹ��� �������� �ǹ�
    if(cnt == (N - 1))
    {
        printf("%lld\n", all_path - minimum_path);
    }
    else
    {
        printf("-1\n");
    }
}