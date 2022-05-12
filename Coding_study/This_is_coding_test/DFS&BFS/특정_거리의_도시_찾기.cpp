#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int K = 0;
int X = 0;

// ��� ���Ḯ��Ʈ�� ���� vector
vector<int> vec[300001];

// �湮 Ȯ���� ���� �迭
bool visited[300001];

// ����� ����� vector
vector<int> res;

// ��� ��ȣ�� �ִܰŸ� ���� pair�� ������ queue
queue<pair<int, int>> path;

void find_path(int x)
{
    // �Լ� ȣ��Ǹ� �湮 Ȯ��
    visited[x] = true;

    path.push({ x, 0 });

    while (!path.empty())
    {
        int cur = path.front().first;
        int way = path.front().second;
        path.pop();

        // ���� Ȯ���ϴ� ����� �ִܰŸ� ���� K��� res vector�� �߰�
        if (way == K)
        {
            res.push_back(cur);
        }

        // ���� Ȯ���ϴ� ��忡 ����� ���� ��ȸ
        for (int i = 0; i < vec[cur].size(); i++)
        {
            int next_x = vec[cur][i];
            
            // ���� ��带 ���� �湮���� �ʾҴٸ� queue�� ����
            if (visited[next_x] == false)
            {
                // �湮 Ȯ��
                visited[next_x] = true;

                // ���� ���� �� ����� �ִܰŸ�(���� ����� �ִܰŸ� + 1)�� pair�� �߰�
                path.push({ next_x, way + 1 });
            }
        }
    }
}
int main()
{
    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vec[n1].push_back(n2);
    }

    find_path(X);

    // ������� �߰��� vector �������� ����
    sort(res.begin(), res.end());

    // res vector ����ִٸ� -1 ���. ���� �ִٸ� �ش� ��� ��ȣ ���
    if (res.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto itr = res.begin(); itr != res.end(); ++itr)
        {
            cout << *itr << endl;
        }
    }
}