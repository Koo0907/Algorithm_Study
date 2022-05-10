#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int solution(string s);

int main() {

    string str;

    cin >> str;

    cout << solution(str) << endl;
}
int solution(string s) {

    // �ʱ� answer ���� s�� size
    int answer = s.size();
    
    // 1���� s�� ���� �������� ���̱��� step ���� Ȯ��
    for(int step = 1; step <= (s.size() / 2); step++)
    {
        string compare_str = "";
        
        // step���� ������ �Ǵ� ���ڿ�
        string stand_str = s.substr(0,step);
        int cnt = 1;

        // step ��ŭ i ����
        for(int i = step; i < s.size(); i += step)
        {
            // ���� ���ڿ��� �������� �ִٸ� cnt ����
            if(stand_str == s.substr(i, step))
            {
                cnt++;
            }
            // ���� ���ڿ��� �������� ���ٸ� cnt ���� ���� �� ���ڿ��� append (cnt�� 1�� ���� ���� ����)
            else
            {
                if(cnt >= 2)
                {
                    compare_str = compare_str + to_string(cnt) + stand_str;
                }
                else
                {
                    compare_str = compare_str + stand_str;
                }
                
                // ���� ���ڿ� �����ϰ� �̾ ��ȸ
                stand_str = s.substr(i,step);
                // cnt�� 1�� �ʱ�ȭ
                cnt = 1;
            }
        }

        // step ���� ��ȸ�� �������� ������ ���ڿ��� ���ؼ� �� ���ڿ��� append
        if(cnt >= 2)
        {
            compare_str = compare_str + to_string(cnt) + stand_str;
        }
        else
        {
            compare_str = compare_str + stand_str;
        }

        // answer ���� �� ���ڿ��� size �� ���Ͽ� ���� ������ answer ����
        answer = min(answer, (int)compare_str.size());
    }

    return answer;
}