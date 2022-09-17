#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 10001

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int cnt = 0;
int max_val = 0;

// ��ǻ�͵��� �ŷڵ� �����͸� ��� ����
vector<int> vec[MAX];

// ��� ����
vector<int> ans;

// �湮 ó���� ���� �迭
bool visited[MAX];

// DFS �Լ� ȣ��
int dfs(int node)
{
    // �ش� ��� �湮 ó��
    visited[node] = true;

    // ��ŷ�� ��ǻ�� �� ����
    cnt++;

    // �ش� ���� �ŷ��ϴ� ������ ��ǻ�͵� ��ȸ
    for(int i = 0; i < vec[node].size(); i++)
    {
        // ���� ��� ����
        int next_node = vec[node][i];

        // ���� ����� ���� �湮���� �ʾҴٸ� DFS �Լ� ȣ��
        if(visited[next_node] == false)
        {
            dfs(next_node);
        }
    }

    // ��ŷ�� ��ǻ�� �� ��ȯ
    return cnt;
}

int main()
{
    // ��ǻ�� ��, �ŷ� ������ �� �Է�
    scanf("%d %d", &N, &M);

    // ��ǻ�͵��� �ŷڵ� ������ �Է�
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d",&a, &b);
        // �ܹ������� ����

        vec[b].push_back(a);
    }

    // ��� ��ǻ�͵� ��ȸ
    for(int i = 1; i <= N; i++)
    {
        // �湮 ó�� �迭 �ʱ�ȭ
        fill(visited, visited + MAX, false);

        // ��ŷ�� ��ǻ�� �� �ʱ�ȣ
        cnt = 0;

        // i�� ��ǻ�͸� ���� ��ŷ�� �� �ִ� ��ǻ���� �� ��ȯ
        int res = dfs(i);

        // res ���� ���ݱ��� ��꿡���� �ִ밪���� ũ�ٸ� �Ʒ� ���� ����
        if(res > max_val)
        {
            // ��� ���� �ʱ�ȭ
            ans.clear();

            // �ִ밪 ����
            max_val = res;

            // ��� ���Ϳ� �� �߰�
            ans.push_back(i);
        }
        // res ���� ���ݱ��� ��꿡���� �ִ밪�� ���ٸ� �Ʒ� ���� ����
        else if(res == max_val)
        {
            // ��� ���Ϳ� �߰�
            ans.push_back(i);
        }
        // �� �ܿ� ���� pass
        else
        {
            /// do nothing...
        }
    }

    // ��� ���� �������� ����
    sort(ans.begin(), ans.end());

    // ��� ���� ���
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%d\n", ans[i]);
    }
}