/* ���� ��ũ */
/* https://www.acmicpc.net/problem/18310 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int num = 0;

vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // �������� ����
    sort(vec.begin(), vec.end());

    // �߰� ���� �� ��ġ�� �����ϴ� ���� �ּҰ��� �ȴٴ� ���̵� �̿�
    // �߰� ���� �� ��ġ���� ��,��� ���������� ��갪�� Ŀ�� �� �ۿ� ����
    cout << vec[(N-1) / 2] << endl;
}