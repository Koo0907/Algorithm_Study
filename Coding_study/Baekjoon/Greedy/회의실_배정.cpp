#include<iostream>
#include<algorithm>

using namespace std;

int N = 0;
int res_cnt = 0;
pair<int, int> meet_time[100000];

bool cmp(pair<int, int> A, pair<int, int> B)
{
	if(A.second == B.second)
	{
		// ȸ�� ���� �ð��� ���ٸ� ���� �ð��� ���� ������ ����
		return A.first < B.first;
	}
	else
	{
		// ȸ�� ���� �ð��� ���� ������ ����
		return A.second < B.second;
	}
}

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		cin >> meet_time[i].first >> meet_time[i].second;
	}

	sort(meet_time, meet_time + N, cmp);

	int standard_time = 0;	// ���� ȸ�� ���� �ð����� ���� ���ǰ� ���۵Ǵ� �ð��� ����
	int cnt = 0;	// ȸ�� ��
	for(int i = 0; i < N; i++)
	{
		// ���� ȸ���� ���� �ð����� ��ȸ���� ȸ���� ���� �ð��� �� ũ�ٸ� cnt ���� 
		if(standard_time <= meet_time[i].first)
		{
			standard_time = meet_time[i].second;	// ȸ�� ���� �ð� ����
			cnt++;	// ȸ�� �� ����
		}
	}

	cout << cnt << endl;
}