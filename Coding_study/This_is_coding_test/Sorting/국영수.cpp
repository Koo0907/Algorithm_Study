/* 백준 링크 */
/* https://www.acmicpc.net/problem/10825 */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 이름과 성적을 저장할 클래스
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

// sort 함수에서 사용하는 compare 함수
bool compare(Student &st1, Student &st2)
{
    // 국어 점수가 같지 않다면 내림차순
    if(st1.score_k != st2.score_k)
    {
        return st1.score_k > st2.score_k;
    }
    else
    {
        // 영어 점수가 같지 않다면 오름차순
        if(st1.score_e != st2.score_e)
        {
            return st1.score_e < st2.score_e;
        }
        else
        {
            // 수학 점수가 같지 않다면 내림차순
            if(st1.score_m != st2.score_m)
            {
                return st1.score_m > st2.score_m;
            }
            // 모든 점수가 같다면 이름 사전 순
            else
            {
                return st1.name < st2.name;    
            }
        }
    }
}

// 사용할 변수 초기화
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

    // cofiguration한 compare 함수 이용하여 sort 함수 호출
    sort(stu.begin(), stu.end(), compare);

    // 출력시에 줄바꿈을 위한 'endl' 키워드를 쓰면 시간초과
    // 'endl' 키워드는 입력 버퍼를 flush 하는 기능도 있기 때문에
    // 많은 출력을 하는 경우는 '\n'을 사용하는 것을 지향
    for(int i = 0; i < N; i++)
    {
        cout << stu[i].name << '\n';
    }
}