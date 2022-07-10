#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;
int res = 0;

// �θ� ���̺�
int parent[1001];

// ��Ʈ��ũ ���� ����
vector<pair<int, pair<int, int>>> graph;

int find_parent(int a)
{
    // ��Ʈ�����(�ڱ� �ڽŰ� �θ��� ���� ���ٸ�) �� ��ȯ
    if(a == parent[a])
    {
        return a;
    }
    // ��Ʈ��尡 �ƴ϶�� ã�� �� ���� �θ����̺� �����ϸ鼭 ���ȣ��
    else
    {
        return parent[a] = find_parent(parent[a]);
    }
}

void union_parent(int a, int b)
{
    // a�� b�� ��Ʈ��� Ž��
    int x = find_parent(a);
    int y = find_parent(b);

    // �� ���� ���� ū ���� �θ� �ǵ��� ����
    if(x < y)
    {
        parent[y] = x;
    }
    else
    {
        parent[x] = y;
    }
}


int main()
{
    cin >> N >> M;

    // �θ� ���̺� �ʱ�ȭ(�θ� �ڱ� �ڽ�����)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // ��Ʈ��ũ ���� �Է�
    for(int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        graph.push_back({c, {a, b}});
    }

    // ����� ������ ������ �������� ����
    sort(graph.begin(), graph.end());

    for(int i = 0; i < M; i++)
    {
        int cost = graph[i].first;
        int x = graph[i].second.first;
        int y = graph[i].second.second;

        // x, y�� �� �׷����� ��� ����Ŭ�� �߻����� �ʴ� ��쿡�� �Ʒ� ���� ����
        if(find_parent(x) != find_parent(y))
        {
            // �� �׷����� ����
            union_parent(x, y);

            // ��� ����
            res += cost;
        }
    }

    cout << res << endl;
}