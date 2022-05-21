#include<iostream>
#include<map>
#include<string>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int max_val = 0;
string book;

// map�� key���� ���ؼ� �ڵ����� �������� �������ִ� STL
map<string, int> book_shelf;

int main()
{
    cin >> N;

    // key ���� å�� �Է¹ް� ������ å�� �Է¹����� �� value���� ����������
    // map[key] �ϴ� ���� value�� 0�� ��
    for(int i = 0; i < N; i++)
    {
        cin >> book;
        book_shelf[book]++;
    }

    // map ��ü ��ȸ�ϸ鼭 ���� ū value �� Ž��
    for(map<string, int>::iterator itr = book_shelf.begin(); itr != book_shelf.end(); ++itr)
    {
        if(itr->second > max_val)
        {
            max_val = itr->second;
        }
    }

    // ������ Ž���� �ִ� value���� ���� key���� ã�Ҵٸ� å �̸� ����ϰ� ����
    for(map<string, int>::iterator itr = book_shelf.begin(); itr != book_shelf.end(); ++itr)
    {
        if(itr->second == max_val)
        {
            cout << itr->first << endl;
            break;
        }
    }
}