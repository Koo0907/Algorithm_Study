#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

priority_queue<int> pq;

// �̹� ������ �ð� ���Ѱ� �޸� ������ Ű����Ʈ
// �ʹ� ���� push�� ���ؼ� �޸𸮸� ��� �־ �ȵǰ�
// �ʹ� ���� �ð��� �����ϴ� �Լ��� ȣ���ؼ��� �ȵ�
// �׷��� �� ���������� �⺻������ cin, cout �Լ���� �� ���� scnaf, printf�� �����
int main()
{
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &num);
            pq.push(-1 * num);
        }

        // N��° ū ���� ���ϸ� �ǹǷ� N�� �̻��� �����͸� ť�� ������� �ʿ䰡 ����
        // �켱���� ť�̱� ������ ������ ���ĵ�
        while(pq.size() > N)
        {
            pq.pop();
        }
    }

    printf("%d", (pq.top() * -1));
}