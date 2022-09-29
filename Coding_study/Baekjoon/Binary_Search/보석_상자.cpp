#include<iostream>
#include<vector>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int M = 0;
int max_val = 0;
int cnt = 0;
int ans = 0;

// ������ �����͸� ��� ����
vector<int> jewel;

int main()
{
    // N�� M �Է�
    scanf("%d %d", &N, &M);

    // M��ŭ ������ �� �Է�
    for(int i = 0; i < M; i++)
    {
        // �ӽ� ���� ����
        int temp = 0;
        
        // ���� �� �Է�
        scanf("%d", &temp);
        
        // ���� ����
        jewel.push_back(temp);

        // ���� ������ ���� �� ����
        max_val = max(max_val, temp);
    }

    // �������� �ּҰ��� 1
    int start = 1;

    // �������� �ִ밪�� ���� ���� ���� ����
    int end = max_val;

    while(start <= end)
    {
        // �������� �̺� Ž������ ����
        int mid = (start + end) / 2;

        // cnt �� �ʱ�ȭ
        cnt = 0;

        // ������ ����ŭ ��ȸ
        for(int i = 0; i < jewel.size(); i++)
        {
            // ��ȸ���� ���� ������ ���������� ���� ���� �ش� ������ �� �� �ִ� �л��� ���� �ǹ�
            cnt += (jewel[i] / mid);

            // ��ȸ���� ���� ������ ���������� ���� ��������ŭ �� �� �л����� �� �� �����Ƿ� cnt ����
            if((jewel[i] % mid) != 0)
            {
                cnt++;
            }
        }

        // ���� cnt ���� N���� ũ�ٸ� �������� �ʹ� �۰� �����ߴٴ� ���̹Ƿ� ������ ������Ŵ
        if(cnt > N)
        {
            start = mid + 1;
        }
        // ���� cnt ���� N���� �۰ų� ���ٸ� ������ �����ϹǷ� ���� �������� �����ϰ� �������� �۰��Ͽ� Ȯ���غ��� �ϹǷ� ������ ���ҽ�Ŵ
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }

    // ���������� ����� ������ ���
    printf("%d\n", ans);
}
