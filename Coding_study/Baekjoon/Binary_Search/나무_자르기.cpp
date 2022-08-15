#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
long long M = 0;
long long ans = 0;
vector<long long> vec;

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		long long num = 0;
		cin >> num;
		vec.push_back(num);
	}

	// ���ܱ� ������ �ּҰ��� 0
	long long start = 0;

	// ���ܱ� ������ �ִ밪�� 2e10
	long long end = 2e10;

	while(start <= end)
	{
		long long sum = 0;

		// ���ܱ� ������ ���� �̺� Ž������ ����
		long long mid = (start + end) / 2;

		for(int i = 0; i < N; i++)
		{
			// ������ ���̰� ���ܱ� ���̺��� ũ�ٸ� �Ʒ� ���� ����
			if(vec[i] > mid)
			{
				// ������ ���̿� ���ܱ� ������ ���� ���ؼ� �������� ����
				sum += (vec[i] - mid);
			}
		}

		// �������� ���� ���� M���� �۴ٸ� ���ܱ� ���̸� �ʹ� ���� �����ߴٴ� ���̹Ƿ� ������ ���ҽ�Ŵ
		if(sum < M)
		{
			end = mid - 1;
		}
		// �������� ���� ���� M �̻��̶�� ������ �����ϹǷ� ���� ���ܱ� ���̸� �����ϰ� ���ܱ� ���̸� ���� ������ Ȯ���غ��� �ϹǷ� ������ ������Ŵ
		else
		{
			ans = mid;
			start = mid + 1;
		}
	}

	cout << ans << endl;
}