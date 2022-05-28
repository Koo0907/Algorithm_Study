#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
long long N = 0;
long long M = 0;
long long num = 0;
long long ans = 0;

vector<int> vec;

int main()
{
    cin >> N >> M;

    for(int i = 0; i < N; i++)
    {
        cin >> num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    // �ּ� �ð��� 1, �ִ� �ð��� �ð��� ���� ���� �ɸ� �ɻ�� * ��� ��
    long long start = 1;
    long long end = vec.back() * M;

    while(start <= end)
    {
        long long mid = (start + end) / 2;
        long long sum = 0;
        
        // ���� �ð����� ����� �Ա��ɻ縦 �� �� �ִ��� Ȯ���ϸ鼭 ������Ŵ
        for(int i = 0; i < N; i++)
        {
            sum += (mid / vec[i]);
        }

        // ����� ����� ���� M���� �۴ٸ� ����� �ð��� �����ߴٴ� �ǹ��̹Ƿ� �ð� ������ �ø�
        if(sum < M)
        {
            start = mid + 1;
        }
        // ����� ����� ���� M���� ũ�ٸ� ����� �ð��� ����ߴٴ� �ǹ��̹Ƿ� �ð� ������ ����
        else
        {
            ans = mid;
            end = mid - 1;
        }
    }
    
    cout << ans << endl;
}