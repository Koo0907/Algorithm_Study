#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int tot = 0;
int res = 0;
int x = 0;
int y = 0;
int z = 0;
int cost = 0;

// �θ� ���̺�
int parent[200001];

// ��� ����
vector<pair<int, pair<int, int>>> path;

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
    cin >> N >> M;

    // �θ� ���̺� �ʱ�ȭ(�θ� �ڱ� �ڽ�����)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // ���� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y >> z;
        path.push_back({z, {x, y}});
        
        // ��� ������ ������ ���
        tot += z;
    }

    // ������ ������ ������������ ����
    sort(path.begin(), path.end());

    for(int i = 0; i < M; i++)
    {
        cost = path[i].first;
        x = path[i].second.first;
        y = path[i].second.second;

        // x�� ���� y�� ���� �� �׷����� ��� ����Ŭ�� �߻����� �ʴ� ��쿡�� �Ʒ� ���� ����
        if(find_parent(x) != find_parent(y))
        {
            union_parent(x, y);

            // �ּ� ������ ���
            res += cost;
        }
    }

    // ��� ������ �����񿡼� �ּ� �������� ���� ���
    cout << tot - res << endl;
}