#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {

    int N;
    int step = 0;
    int idx = 0;
    int score = 0;
    string ox;
    vector<int> v;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ox;

        // ���ڿ� ������ ��ȸ
        while(ox[step] != '\0')
        {
            if(ox[step] == 'O')
            {
                // ���� ������ ���� ���� �ջ�
                idx++;
                score += idx;
            }
            else
            {
                // ���� ���� �ʱ�ȭ
                idx = 0;
            }
            step++;
        }
        // vector�� ���� �߰� �� ����� ������ �ʱ�ȭ
        v.push_back(score);
        idx = 0;
        step = 0;
        score = 0;
    }

    // �߰��� ������ ���
    for(vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
    {
        cout << *itr << endl;
    }

}