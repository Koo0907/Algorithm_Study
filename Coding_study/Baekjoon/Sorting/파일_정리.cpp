#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
string file;
string temp_file;

// map�� key���� ���ؼ� �ڵ����� �������� �������ִ� STL
map<string, int> descriptor;

int main()
{
    cin >> N;

    // N���� file ���� '.' ���� Ȯ���� ���ڿ��� map�� �߰�
    for(int i = 0; i < N; i++)
    {
        cin >> file;
        temp_file = file.substr(file.find(".") + 1);
        descriptor[temp_file]++;
    }

    // map�� �ڵ����� key���� ���� �������� ���ֹǷ� �״�� ���
    for(map<string, int>::iterator itr = descriptor.begin(); itr != descriptor.end(); ++itr)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}