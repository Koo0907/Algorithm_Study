#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

    int N;
    int x;
    int res = 1;
    vector<int> arr;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    // �������� ����
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++)
    {
        // Ȯ���ؾ��ϴ� ���� ������ ��ȸ�ϴ� ������ �۴ٸ� �� ���� ����� �� �� ����
        // ex. 3,2,1,1,9
        // �������� ���� : 1,1,2,3,9
        // [1] -> 1 ���� ����
        // [1,1] -> 2 ���� ����
        // [1,1,2] -> 3,4 ���� ����
        // [1,1,2,3] -> 5,6,7 ���� ����
        // [1,1,2,3,9] -> ��ȸ�ϴ� 9�� Ȯ���ؾ��ϴ� ��(8)���� ũ�Ƿ� 8�� ���� �Ұ���
        if(res < arr[i])
        {
            break;
        }
        res += arr[i];
    }

   cout << res << endl;
}