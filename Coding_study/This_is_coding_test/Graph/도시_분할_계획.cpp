/* ���� ��ũ */
/* https://www.acmicpc.net/problem/1647 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int x = 0;
int y = 0;
int cost = 0;
int res = 0;
int last_val = 0;

vector<pair<int, pair<int, int>>> path;
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

    // ��� ���� �Է�
    for(int i = 0; i < M; i++)
    {
        cin >> x >> y >> cost;
        path.push_back({cost, {x, y}});
    }

    // ����� ������ ������ �������� ����
    sort(path.begin(), path.end());

    for(int i = 0; i < M; i++)
    {
        cost = path[i].first;
        x = path[i].second.first;
        y = path[i].second.second;

        // x, y�� �� �׷����� ��� ����Ŭ�� �߻����� �ʴ� ��쿡�� �Ʒ� ���� ����
        if(find_parent(x) != find_parent(y))
        {
            // �� �׷����� ����
            union_parent(x, y);
            
            // ������ ����
            res += cost;

            // ������ �� ����
            last_val = cost;
        }
    }

    // �������� �� �տ��� ������ last_val ���� ��
    // ���� ������ �������� �ۼ��� �ּ� ���� Ʈ������ ���� ū ������ ���� ��θ� ����
    // �ڿ������� �� ������ �������鼭 �ּ��� ������� ��θ� �����ϰ� ����.
    cout << res - last_val << endl;
}