#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
int M = 0;
int S = 0;
int E = 0;
int res = 2e9;
vector<int> A;

int main()
{
	cin >> N >> M;

	for(int i = 0; i < N; i++)
	{
		int num = 0;
		cin >> num;
		A.push_back(num);
	}

	// ���� �������� ����
	sort(A.begin(), A.end());

	// �� ������ ����Ͽ� S �ε����� E �ε����� ������ ����� �ʴ´ٸ� �Ʒ� ���� ����
	while((S < A.size()) && (E < A.size()))
	{
		// �� ���� ���� ���ذ��� M �̻��� �ƴ϶�� E �ε��� ����
		if(A[E] - A[S] < M)
		{
			E++;
		}
		// �� ���� ���� ���ذ��� M �̻��̶�� �ּҰ� ���� �� S �ε��� ����
		else
		{
			res = min(res, A[E] - A[S]);
			S++;
		}
	}

	cout << res << endl;
}