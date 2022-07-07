#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int lec_time = 0;
int op = 0;

// �������� �� ���̺�
int deg[501];

// �������� ������ ��� ���� vector
vector<int> vec[501];

// �� ���� �ð��� ��� ���� �迭
int times[501];

// �� ���Ǹ� �����ϱ� ���� ��ü �ð��� ��� ���� �迭
int res[501];

void topology_sort()
{
    // ť ����
    queue<int> que;

    // res �迭�� times �迭�� �ʱ�ȭ
    for(int i = 1; i <= N; i++)
    {
        res[i] = times[i];
    }

    // ���� ������ 0�� ���� ����
    for(int i = 1; i <= N; i++)
    {
        if(deg[i] == 0)
        {
            que.push(i);
        }
    }

    // ť�� �� ������ �ݺ�
    while(!que.empty())
    {
        int now = que.front();
        que.pop();

        // ���� ���Ǹ� ������������ �ϴ� ���ǰ� �ִ��� Ȯ��
        for(int i = 0; i < vec[now].size(); i++)
        {
            // next_lec�� ���� ���Ǹ� ������������ ��
            int next_lec = vec[now][i];
            res[next_lec] = max(res[next_lec], res[now] + times[next_lec]);
            deg[next_lec]--;
            
            // ���� ������ 0�� �ȴٸ� ť�� �߰�
            if(deg[next_lec] == 0)
            {
                que.push(next_lec);
            }
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        // ������ �ð� �迭�� �Է�
        cin >> lec_time;
        times[i] = lec_time;

        while(true)
        {
            cin >> op;

            // '-1'�� �Էµɶ� ���� �ݺ��ϸ鼭 ���Ḯ��Ʈ ����
            if(op < 0)
            {
                break;
            }
            deg[i]++;
            vec[op].push_back(i);
        }

    }

    // ���� ���� ����
    topology_sort();

    // ����� ���
    for(int i = 1; i <= N; i++)
    {
        cout << res[i] << endl;
    }
}