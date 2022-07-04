#include<iostream>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int op = 0;
int x = 0;
int y = 0;

// �θ� ���̺� �ʱ�ȭ
int parent[100001];

int find_parent(int x)
{
    // ��Ʈ�����(�ڱ� �ڽŰ� �θ��� ���� ���ٸ�) �� ��ȯ
    if(x == parent[x])
    {
        return x;
    }
    // ��Ʈ��尡 �ƴ϶�� ã�� �� ���� �θ����̺� �����ϸ鼭 ���ȣ��
    else
    {
        return parent[x] = find_parent(parent[x]);
    }
}

void union_parent(int x, int y)
{
    // x�� y�� ��Ʈ��� Ž��
    x = find_parent(x);
    y = find_parent(y);
    
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

    // M�� ���� ����
    for(int i = 0; i < M; i++)
    {
        // �Է�
        cin >> op >> x >> y;

        // op�� 0�̶�� '�� ��ġ��' �Լ� ����
        if(op == 0)
        {
            union_parent(x, y);
        }
        // op�� 0�� �ƴ϶�� '���� �� ���� Ȯ��' �Լ� ����
        else
        {
            // �� ���� ��Ʈ��尡 ���ٸ�(���� ���̶��) 'YES' ��� 
            if(find_parent(x) == find_parent(y))
            {
                cout << "YES" << endl;
            }
            // �� ���� ��Ʈ��尡 �ٸ��ٸ� 'NO' ���
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}