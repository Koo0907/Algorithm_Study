#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 50

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int total = 0;
int cnt = 0;
int ans = 0;

// ���� ���� �����͸� ��� ����
vector<pair<int, pair<int, int>>> graph;

// ���� ���� �����͸� ��� �迭
char map[MAX][MAX];

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

// ���� ���� ��ȯ �Լ�
int convert_value(char ch)
{
    // ���� ���̰� �ҹ����� ���
    if((ch >= 'a') && (ch <= 'z'))
    {
        return ch - 'a' + 1;
    }
    // ���� ���̰� �빮���� ���
    else if((ch >= 'A') && (ch <= 'Z'))
    {
        return ch - 'A' + 27;
    }
    // ���� ���̰� 0�� ���
    else
    {
        return 0;
    }
}

int main()
{
    // ���� �� �Է�
    scanf("%d", &N);

    // ��ǻ���� ���� ������ �Է�
    for(int i = 0; i < N; i++)
    {
        cin.ignore();
        for(int j = 0; j < N; j++)
        {
            scanf("%c", &map[i][j]);

            // �־����� ���� ���̸� ��� �ջ�
            total += convert_value(map[i][j]);
        }
    }

    // �� ��ǻ�͵鿡 ���� ���� ���� Ȯ�� �� �ּ� ���� ����
    for(int i = 0; i < N; i++)
    {
        for(int j = i; j < N; j++)
        {
            // i�� j�� ���� ���ų�, i�� ��ǻ�Ϳ� j�� ��ǻ�� ������ ���� ���̰� ��� 0���� �־����� ���� ����
            if((i == j) || (map[i][j] == '0') && (map[j][i] == '0'))
            {
                continue;
            }

            // ���� ���� �ʱ�ȭ
            int cost = 0;

            // i�� ��ǻ�Ϳ� j�� ��ǻ���� ���� ���̰� ��� 0�� �ƴ� ��쿡�� �� ���� ���� ���̸� ����
            if((map[i][j] != '0') && (map[j][i] != '0'))
            {
                cost = min(convert_value(map[i][j]), convert_value(map[j][i]));
            }
            // i�� ��ǻ�Ϳ��� j�� ��ǻ�ͱ����� ���� ���̰� 0������, j�� ��ǻ�Ϳ��� i�� ��ǻ�ͱ����� �������̰� 0�� �ƴ϶�� �ش� ���� ���̸� ����
            else if((map[i][j] == '0') && (map[j][i] != '0'))
            {
                cost = convert_value(map[j][i]);
            }
            // j�� ��ǻ�Ϳ��� i�� ��ǻ�ͱ����� ���� ���̰� 0������, i�� ��ǻ�Ϳ��� j�� ��ǻ�ͱ����� �������̰� 0�� �ƴ϶�� �ش� ���� ���̸� ����
            else
            {
                cost = convert_value(map[i][j]);
            }

            // ���Ϳ� ������ ���� ���̿� �� ��ǻ�� ���� ����
            graph.push_back({cost, {i, j}}); 
        }
    }

    // �θ� ���̺� �ʱ�ȭ
    for(int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    // ���� ���� �������� ����
    sort(graph.begin(), graph.end());

    // ������ ������ �� ��ŭ ��ȸ
    for(int i = 0; i < graph.size(); i++)
    {
        // a, b�� ��ǻ���� ��ȣ
        // lan�� �� ��ǻ�͸� �����ϴ� ���� ����
        int a = graph[i].second.first;
        int b = graph[i].second.second;
        int lan = graph[i].first;

        // ��ȸ�ϴ� �� ����� �θ� ��尡 �ٸ��ٸ�(=cycle�� �������� �ʴ´ٸ�) �Ʒ� ���� ����
        if(find_parent(a) != find_parent(b))
        {
            // �� ��� union ����
            union_parent(a, b);

            // ���� �� ����
            cnt++;

            // �� ���� ���� ����
            ans += lan;
        }
    }

    // ������ ���� ��ǻ���� ������ 1 �۴ٸ� MST ����
    if(cnt == N - 1)
    {
        // ��ü ���� ���̿��� MST�� ���Ǵ� ���� ���̸� �� ���̰� ���
        printf("%d\n", total - ans);   
    }
    else
    {
        // -1 ���
        printf("-1\n");
    }
}