/* ���� ��ũ */
/* https://www.acmicpc.net/problem/10825 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// �̸��� ������ ������ Ŭ����
class Student {
public:
    string name;
    int score_k;
    int score_e;
    int score_m;

    Student(string name, int score_k, int score_e, int score_m) {
        this->name = name;
        this->score_k = score_k;
        this->score_e = score_e;
        this->score_m = score_m;
    }
};

// sort �Լ����� ����ϴ� compare �Լ�
bool compare(Student &st1, Student &st2)
{
    // ���� ������ ���� �ʴٸ� ��������
    if(st1.score_k != st2.score_k)
    {
        return st1.score_k > st2.score_k;
    }
    else
    {
        // ���� ������ ���� �ʴٸ� ��������
        if(st1.score_e != st2.score_e)
        {
            return st1.score_e < st2.score_e;
        }
        else
        {
            // ���� ������ ���� �ʴٸ� ��������
            if(st1.score_m != st2.score_m)
            {
                return st1.score_m > st2.score_m;
            }
            // ��� ������ ���ٸ� �̸� ���� ��
            else
            {
                return st1.name < st2.name;    
            }
        }
    }
}

// ����� ���� �ʱ�ȭ
int N = 0;
string name;
int score_k;
int score_e;
int score_m;

vector<Student> stu;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> name >> score_k >> score_e >> score_m;

        stu.push_back(Student(name, score_k, score_e, score_m));
    }

    // cofiguration�� compare �Լ� �̿��Ͽ� sort �Լ� ȣ��
    sort(stu.begin(), stu.end(), compare);

    // ��½ÿ� �ٹٲ��� ���� 'endl' Ű���带 ���� �ð��ʰ�
    // 'endl' Ű����� �Է� ���۸� flush �ϴ� ��ɵ� �ֱ� ������
    // ���� ����� �ϴ� ���� '\n'�� ����ϴ� ���� ����
    for(int i = 0; i < N; i++)
    {
        cout << stu[i].name << '\n';
    }
}