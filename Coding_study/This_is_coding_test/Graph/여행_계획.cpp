#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int path = 0;
int trip = 0;
bool flag = true;

// �θ� ���̺�
int parent[501];

// ���� ��ȹ
vector<int> plan;

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
    // �������� ���� ��ȹ�� �������� �� �Է�
    cin >> N >> M;

    // �θ� ���̺� �ʱ�ȭ(�θ� �ڱ� �ڽ�����)
    for(int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    // ���������� ��� ���� �Է¹޾Ƽ� ��ΰ� ����Ǿ� �ִٸ� �� �׷����� ����
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            cin >> path;

            if(path == 1)
            {
                union_parent(i, j);
            }
        }
    }

    // ���� ��ȹ ���� �Է�
    for(int i = 0; i < M; i++)
    {
        cin >> trip;
        plan.push_back(trip);
    }

    // ���� ��ȹ�� �ִ� ���������� �θ� ��带 ��
    for(int i = 0; i < (M - 1); i++)
    {
        // ���������� �θ� ��尡 �ٸ��ٸ� ����Ǿ� ���� �����Ƿ� ���� flag�� false�� �ٲ�
        if(find_parent(plan[i]) != find_parent(plan[i + 1]))
        {
            flag = false;
        }
    }

    // ���
    if(flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}