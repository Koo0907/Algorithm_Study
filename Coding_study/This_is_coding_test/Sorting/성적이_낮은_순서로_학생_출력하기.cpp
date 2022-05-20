#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 이름과 성적을 저장할 클래스
class Student {
public:
    string name;
    int score;

    Student(string name, int score) {
        this->name = name;
        this->score = score;
    }
};

// 사용할 변수 초기화
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

    // left 값과 right 값이 엇갈릴 때 까지 반복
    while(left <= right)
    {
        // arr[left] 값이 arr[pivot] 값보다 클 때 까지 left 값 증가
        while((left <= end) && (arr[left].score <= arr[pivot].score))
        {
            left++;
        }

        // arr[right] 값이 arr[pivot] 값보다 작을 때 까지 right 값 감소
        while((right > start) && (arr[right].score >= arr[pivot].score))
        {
            right--;
        }

        // right 값과 left 값이 엇갈린다면 작은 값(arr[right])을 arr[pivot] 값과 swap
        if(right < left)
        {
            Student temp = arr[right];
            arr[right] = arr[pivot];
            arr[pivot] = temp;
        }
        // arr[left] 값과 arr[right] 값 swap
        else
        {
            Student temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }

    // arr[pivot] 값 기준으로 나눠진 영역 중 왼쪽 영역에 대해서 재귀 함수 호출
    quick_sort(arr, start, right - 1);
    
    // arr[pivot] 값 기준으로 나눠진 영역 중 오른쪽 영역에 대해서 재귀 함수 호출
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

    // 퀵 정렬 함수 호출
    quick_sort(vec, 0, vec.size() - 1);

    for(int i = 0; i < N; i++)
    {
        cout << vec[i].name << " ";
    }
}