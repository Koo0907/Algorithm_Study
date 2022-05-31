#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int num = 0;

vector<int> vec;

// 10001�� Ư�� �ݾ��� ���� �� �ִ� ȭ�� ������ �������� �ʴٴ� �ǹ�
vector<int> memo(10001, 10001);

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    memo[0] = 0;

    // Dynamic Programming ����(Bottom-up ���)
    // �ݾ� i���� ���� �� �ִ� �ּ����� ȭ�� ������ a[i]��� ��
    // �� ȭ���� ������ k��� ��
    // �� ȭ�� ������ k�� �ϳ��� Ȯ���ϸ鼭 �Ʒ��� ������ üũ
    // i-k���� ���� �� �ִٸ�(= a[i-k]�� ��ȿ�� ���̶��), i���� ���� �� ������ �׶��� ȭ�� ������ min(a[i], a[i-k]+1)�� ��
    // i-k���� ���� �� ���ٸ�(= a[i-k]�� ��ȿ���� ���� ���̶��) i���� ���� �� �����Ƿ� a[i]�� INF ���� ��
    for(int i = 0; i < N; i++)
    {
        // ��ȸ ���� ȭ���� �������� ��ȸ�ϱ� ����
        for(int j = vec[i]; j <= M; j++)
        {
            // a[i-k]���� ��ȿ�� ������ üũ
            if(memo[j - vec[i]] != 10001)
            {
                // a[i-k]���� ��ȿ�ϴٸ� ������ a[i] ���� a[i-k]+1 �� ���Ͽ� �ּҰ����� ����
                memo[j] = min(memo[j], memo[j - vec[i]] + 1);
            }
        }
    }

    // ��ȸ�� ���´µ��� a[M]�� ��ȿ�� ������ üũ�ϰ� ���
    if(memo[M] != 10001)
    {
        cout << memo[M] << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}