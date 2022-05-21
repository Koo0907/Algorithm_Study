/* ���α׷��ӽ� ��ũ */
/* https://programmers.co.kr/learn/courses/30/lessons/42889 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// stage�� �������� �Բ� ó���ϱ� ���� struct ����
struct Fail_per
{
    int stage;
    double fail;
};

// sort �Լ� �̿��� ���� compare �Լ�
bool compare(struct Fail_per &a, struct Fail_per &b)
{
    // �������� ���ٸ� stage�� �� ��������
    if(a.fail == b.fail)
    {
        return a.stage < b.stage;
    }

    // �������� �ٸ��ٸ� �⺻������ ��������
    return a.fail > b.fail;
}

vector<int> solution(int N, vector<int> stages) {
    // ��ȯ�� answer vector
    vector<int> answer;

    // stage�� �������� �����͸� ��� struct vecotr
    vector<Fail_per> res;

    // ���޹��� stages vector�� ũ�⸦ ���ؼ� ������� �� ����
    int users = stages.size();

    // stage �� ��ŭ �ݺ�
    for(int i = 1; i <= N; i++)
    {
        int temp_cnt = 0;

        // ����� �� ��ŭ �ݺ�
        for(int j = 0; j < stages.size(); j++)
        {
            // ����ڰ� �����ϰ� �ִ� stage�� ���� ��ȸ���� stage(i)�� ���ٸ� ����� �� count
            if(stages[j] == i)
            {
                temp_cnt++;
            }
        }

        // ������ �ʱ�ȭ
        double temp_fail = 0;

        // ���� stage�� ������ ����ڰ� ���� ��쿡�� ������ 0���� ����
        // ���� stage�� ������ ����ڰ� �ִٸ� ������ ���
        if(users > 0)
        {
            temp_fail = (double)temp_cnt / users;
        }

        // res vecotr�� stage�� ������ struct ������ �߰�
        res.push_back({i, temp_fail});

        // �ռ� ���� ����ڵ��� �������� ������ ��꿡�� ���ܽ��Ѿ� �ϹǷ� counting �� �� ��ŭ ��ü ����� ������ ����
        users -= temp_cnt;
    }

    // configuration compare �Լ��� �̿��� sort �Լ� ȣ��
    sort(res.begin(), res.end(), compare);

    // sorting�� ������� answer vector�� stage�� �߰�
    for(int i = 0; i < N; i++)
    {
        answer.push_back(res[i].stage);
    }

    return answer;
}

int main()
{
    int N = 0;
    int num = 0;
    vector<int> vec;
    vector<int> res;

    cin >> N;

    // ����� ����#1 ����(N = 5, stages = [2, 1, 2, 6, 2, 4, 3, 3])
    for(int i = 0; i < 8; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    res = solution(N, vec);

    for(int i = 0; i < N; i++)
    {
        cout << res[i] << endl;
    }
}