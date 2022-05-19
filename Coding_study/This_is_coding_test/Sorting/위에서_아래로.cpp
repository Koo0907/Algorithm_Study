#include<iostream>
#include<vector>
using namespace std;

// 사용할 변수 초기화
int N = 0;

vector<int> vec;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    // 삽입정렬 알고리즘 이용
    for(int i = 1; i < N; i++)
    {
        for(int j = i; j > 0; j--)
        {
            if(vec[j] > vec[j - 1])
            {
                int temp = vec[j];
                vec[j] = vec[j - 1];
                vec[j - 1] = temp;
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << vec[i] << " ";
    }
}