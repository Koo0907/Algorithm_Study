#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
string serial;

vector<string> vec;

bool compare(string &a, string &b)
{
    // A와 B의 길이가 다르면 짧은 것이 먼저 정렬되도록 함
    if(a.size() != b.size())
    {
        return a.size() < b.size();
    }
    // A와 B의 길이가 같으면 아래 로직 수행
    else
    {
        int sum_a = 0;
        int sum_b = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(a[i] >= '0' && a[i] <= '9')
            {
                sum_a += a[i] - '0';
            }

            if(b[i] >= '0' && b[i] <= '9')
            {
                sum_b += b[i] - '0';
            }
        }

        // A와 B의 문자열에서 자리수만 더해서 작은 합이 먼저 정렬되도록 함
        if(sum_a != sum_b)
        {
            return sum_a < sum_b;
        }
        // 합도 같다면 사전 순으로 정렬되도록 함
        else
        {
            return a < b;
        }
    }
}

int main()
{
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> serial;
        vec.push_back(serial);
    }

    // configuration한 compare 함수 이용하여 sort 함수 호출
    sort(vec.begin(), vec.end(), compare);

    for(int i = 0; i < N; i++)
    {
        cout << vec[i] << endl;
    }
}