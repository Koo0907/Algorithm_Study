#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

// 사용할 변수 초기화
int N = 0;
string file;
string temp_file;

// map은 key값에 대해서 자동으로 오름차순 정렬해주는 STL
map<string, int> descriptor;

int main()
{
    cin >> N;

    // N개의 file 명에서 '.' 이후 확장자 문자열만 map에 추가
    for(int i = 0; i < N; i++)
    {
        cin >> file;
        temp_file = file.substr(file.find(".") + 1);
        descriptor[temp_file]++;
    }

    // map은 자동으로 key값에 따라 오름차순 해주므로 그대로 출력
    for(map<string, int>::iterator itr = descriptor.begin(); itr != descriptor.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}