/* ���� ��ũ */
/* https://www.acmicpc.net/problem/2110 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int C = 0;
int num = 0;

vector<int> vec;

bool check_gap(int gap)
{
    // ù��° ������ �׻� �����⸦ ��ġ�ϰ� �������� ���� 1�� �ʱ�ȭ �� ����
    int prev = vec[0];
    int cnt = 1;

    // ù��° ���� ��ġ �����ϰ� ��ȸ
    for(int i = 1; i < N; i++)
    {
        // ������ �����⸦ ��ġ�� ��ġ���� gap��ŭ ���̸� �� ���� �ִٸ� �����⸦ ��ġ�ϰ� count ����
        if((vec[i] - prev) >= gap)
        {
            prev = vec[i];
            cnt++;
        }
    }

    // ��ȸ�� �� ��ġ�� ��ġ�� �������� ���� �Է¹��� C �̻��̶�� ������ �����ϹǷ� true ��ȯ
    if(cnt >= C)
    {
        return true;
    }
    // ������ �������� ���ϹǷ� false ��ȯ
    else
    {
        return false;
    }

}

int binary_search(int start, int end)
{
    int temp_res = 0;

    while(start <= end)
    {
        int gap = (start + end) / 2;

        // ������ gap �̻��� ������ �ΰ� �Է��� �������� ���� ������ �� �ִ��� Ȯ��
        if(check_gap(gap))
        {
            // �������� ���� �����Ѵٸ� �ӽ� ���� ������ temp_res�� ���� gap ����
            temp_res = gap;

            // ���� gap������ ������ ���������Ƿ� gap�� ���� �� �÷����� ������ �����ϴ��� Ȯ���ϱ� ���� gap ����
            start = gap + 1;
        }
        else
        {
            // �������� ���� �������� ���ߴٸ� gap�� �ʹ� �Ǵٴ� ���̹Ƿ� gap ����
            end = gap - 1;
        }
    }

    // ��� ��ȸ�� ������ �������� ����� �ӽ� ���� ��ȯ
    return temp_res;
}

int main()
{
    int res = 0;

    cin >> N >> C;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    // ���� Ž���� ���� �������� ����
    sort(vec.begin(), vec.end());

    res = binary_search(1, vec[N - 1] - vec[0]);

    cout << res << endl;
}