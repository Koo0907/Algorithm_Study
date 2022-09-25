#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int K = 0;
int ans = 0;
int cnt = 0;

// ������ �����͸� ��� ����
vector<pair<int, pair<int, int>>> graph;

// �θ� ���̺� ����
int parent[MAX];

// find ����
int find_parent(int a)
{
    // a�� �θ� ��尡 a��� �״�� a ���
    if(a == parent[a])
    {
        return a;
    }
    // a�� �θ� ��尡 a�� �ƴ϶�� �θ� ���̺� ����
    else
    {
        return parent[a] = find_parent(parent[a]);
    }
}

// union ����
void union_parent(int a, int b)
{
    // a, b�� �θ� ��� Ȯ��
    a = find_parent(a);
    b = find_parent(b);

    // �� ���� ���� �θ� ��尡 �ǵ��� ����
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
    // ����, ����, �� �� �Է�
    scanf("%d %d %d", &N, &M, &K);

    // ���� ���� �Է�
    for(int i = 1; i <= M; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        graph.push_back({i, {a, b}});
    }

    // ������ ����ġ �������� ����
    sort(graph.begin(), graph.end());

    // ���� �� ��ŭ �ݺ�
    for(int Tc = 0; Tc < K; Tc++)
    {
        // �θ� ���̺� �ʱ�ȭ
        for(int i = 1; i <= N; i++)
        {
            parent[i] = i;
        }

        // ����� ���� �ʱ�ȭ
        ans = 0;
        cnt = 0;

        // ������ �� ��ŭ ��ȸ
        for(int i = 0; i < graph.size(); i++)
        {
            // a, b�� ����Ǿ� �ִ� ���
            // cost�� �� ��带 �մ� ����� ����ġ
            int a = graph[i].second.first;
            int b = graph[i].second.second;
            int cost = graph[i].first;

            // a�� b�� ���� ���� �θ� ��带 ������ ���� �ʴٸ�(=Cycle�� �̷��� �ʴ´ٸ�) �Ʒ� ���� ����
            if(find_parent(a) != find_parent(b))
            {
                // union ����
                union_parent(a, b);

                // ������ ������ �� ����
                cnt++;

                // ��� ����
                ans += cost;
            }
        }

        // �� ���� ����ǰ� ������ ������ ���� ������ ������ 1 �� ������ MST �ϼ�
        if(cnt == N - 1)
        {
            printf("%d ", ans);
        }
        else
        {
            printf("0 ");
        }

        // �������� ���������Ƿ� ù��° ��Ұ� ���� ����ġ�� ���� ����̹Ƿ� ����
        graph.erase(graph.begin());
    }
}