#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

// ����� ���� �ʱ�ȭ
int K = 0;
int N = 0;
int len = 0;
int ans = 0;

// �̹� ������ �ִ� ���� ���̸� ��� ����
vector<int> Lan_line;

int main()
{
    // K�� N �Է�
    scanf("%d %d", &K, &N);

    // K��ŭ ������ �ִ� ���� ���� �Է�
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &len);
        Lan_line.push_back(len);
    }

    // ���� ������ �ּҰ��� 0
    long long start = 0;

    // ���� ������ �ִ밪�� 2^31 - 1
    long long end = pow(2, 31) - 1;

    while(start <= end)
    {
        // ���� ������ ���� �̺� Ž������ ����
        long long mid = (start + end) / 2;

        // ��������� ���� �� �ʱ�ȭ
        int total = 0;

        // ������ �ִ� ���� ��ȸ
        for(int i = 0; i < Lan_line.size(); i++)
        {
            // ������ �ִ� �������� ���� ���� �� �ִ� ������ ����ŭ ����
            total += (Lan_line[i] / mid);
        }

        // ���� ���� �� �ִ� ������ ���� N���� �۴ٸ� ���� ���̸� �ʹ� ũ�� �����ߴٴ� ���̹Ƿ� ������ ���ҽ�Ŵ
        if(total < N)
        {
            end = mid - 1;
        }
        // ���� ���� �� �ִ� ������ ���� N���� ���ų� ũ�ٸ� ������ �����ϹǷ� ���� ���� ���̸� �����ϰ� ���� ���̸� ª���Ͽ� Ȯ���غ��� �ϹǷ� ������ ������Ŵ
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }

    // ���������� ����� ���� ���� ���
    printf("%d\n", ans);
}
