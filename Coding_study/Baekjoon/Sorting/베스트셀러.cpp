#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
int max_val = 0;
string book;

// map은 key값에 대해서 자동으로 오름차순 정렬해주는 STL
map<string, int> book_shelf;

int main()
{
    cin >> N;

    // key 값인 책을 입력받고 동일한 책을 입력받으면 그 value값을 증가시켜줌
    // map[key] 하는 순간 value는 0이 들어감
    for(int i = 0; i < N; i++)
    {
        cin >> book;
        book_shelf[book]++;
    }

    // map 전체 순회하면서 가장 큰 value 값 탐색
    for(map<string, int>::iterator itr = book_shelf.begin(); itr != book_shelf.end(); ++itr)
    {
        if(itr->second > max_val)
        {
            max_val = itr->second;
        }
    }

    // 위에서 탐색한 최대 value값을 가진 key값을 찾았다면 책 이름 출력하고 종료
    for(map<string, int>::iterator itr = book_shelf.begin(); itr != book_shelf.end(); ++itr)
    {
        if(itr->second == max_val)
        {
            cout << itr->first << endl;
            break;
        }
    }
}