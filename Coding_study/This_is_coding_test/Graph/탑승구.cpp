#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int g = 0;
int p = 0;
int p_num = 0;
int root = 0;
int res = 0;

// �θ� ���̺�
int parent[100001];

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
    // ž�±��� ����� ���� �Է�
    cin >> g >> p;

    // �θ� ���̺� �ʱ�ȭ(�θ� �ڱ� �ڽ�����)
    for(int i = 1; i <= g; i++)
    {
        parent[i] = i;
    }

    for(int i = 0; i < p; i++)
    {
        cin >> p_num;

        // ���� ������� ž�±��� �θ� ��� Ȯ��
        root = find_parent(p_num);

        // �θ� ��尡 0�̶�� ���̻� ��ŷ�� �Ұ����ϹǷ� ���� ���� ����
        if(find_parent(root) == 0)
        {
            break;
        }

        // �θ� ��尡 0�� �ƴ϶�� �ٷ� ������ ���հ� ��ġ��
        union_parent(root, root - 1);
        res++;
    }

    cout << res << endl;
}