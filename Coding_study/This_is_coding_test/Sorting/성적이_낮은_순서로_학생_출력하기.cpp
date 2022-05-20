#include<iostream>
#include<vector>
#include<string>

using namespace std;

// �̸��� ������ ������ Ŭ����
class Student {
public:
    string name;
    int score;

    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
};

// ����� ���� �ʱ�ȭ
int N = 0;

vector<Student> vec;

void quick_sort(vector<Student> &arr, int start, int end)
{
    if(start >= end)
    {
        return;
    }

    int pivot = start;
    int left = start + 1;
    int right = end;

    // left ���� right ���� ������ �� ���� �ݺ�
    while(left <= right)
    {
        // arr[left] ���� arr[pivot] ������ Ŭ �� ���� left �� ����
        while((left <= end) && (arr[left].score <= arr[pivot].score))
        {
            left++;
        }

        // arr[right] ���� arr[pivot] ������ ���� �� ���� right �� ����
        while((right > start) && (arr[right].score >= arr[pivot].score))
        {
            right--;
        }

        // right ���� left ���� �������ٸ� ���� ��(arr[right])�� arr[pivot] ���� swap
        if(right < left)
        {
            Student temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] ���� arr[right] �� swap
        else
        {
            Student temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }

    // arr[pivot] �� �������� ������ ���� �� ���� ������ ���ؼ� ��� �Լ� ȣ��
    quick_sort(arr, start, right - 1);
    
    // arr[pivot] �� �������� ������ ���� �� ������ ������ ���ؼ� ��� �Լ� ȣ��
    quick_sort(arr, left, end);
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        string str;
        int num;

        cin >> str >> num;

        vec.push_back(Student(str, num));
    }

    // �� ���� �Լ� ȣ��
    quick_sort(vec, 0, vec.size() - 1);

    for(int i = 0; i < N; i++)
    {
        cout << vec[i].name << " ";
    }
}