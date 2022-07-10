#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

// ����� ���� �ʱ�ȭ
int m = 0;
int n = 0;
int x = 0;
int y = 0;
int z = 0;
int res = 0;
int total = 0;

// �θ� ���̺�
int parent[200001];

// ��� ����
vector<pair<int, pair<int, int>>> graph;

int find_parent(int a)
{
    // ��Ʈ�����(�ڱ� �ڽŰ� �θ��� ���� ���ٸ�) �� ��ȯ
    if(parent[a] == a)
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
    a = find_parent(a);
    b = find_parent(b);

    // �� ���� ���� ū ���� �θ� �ǵ��� ����
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
    while(true)
    {
        cin >> m >> n;

        // ���� �ݺ��� Ż�� ���� �Ǵ�
        if((m == 0) && (n == 0))
        {
            break;
        }

        // ���� �׽�Ʈ ���̽��� ���� ���� �ʱ�ȭ
        graph.clear();
        memset(parent, 0, sizeof(parent));
        res = 0;
        total = 0;

        // �θ� ���̺� �ʱ�ȭ(�θ� �ڱ� �ڽ�����)
        for(int i = 0; i < m; i++)
        {
            parent[i] = i;
        }

        // ���� ��� �Է�
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y >> z;
            graph.push_back({z, {x, y}});
            total += z;
        }

        // ���ε��� ������ ������ �������� ����
        sort(graph.begin(), graph.end());

        for(int i = 0; i < n; i++)
        {
            int cost = graph[i].first;
            int a = graph[i].second.first;
            int b = graph[i].second.second;

            // a, b�� �� �׷����� ��� ����Ŭ�� �߻����� �ʴ� ��쿡�� �Ʒ� ���� ����
            if(find_parent(a) != find_parent(b))
            {
                // �� �׷����� ����
                union_parent(a, b);

                // ��� ����
                res += cost;
            }
        }

        // ��� ���
        cout << total - res << endl;
    }
}