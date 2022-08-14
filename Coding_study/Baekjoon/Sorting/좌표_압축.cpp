#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ������ �ʱ�ȭ
int N = 0;
vector<int> vec;
vector<int> vec_cmp;

int main()
{
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		int num = 0;
		scanf("%d",&num);
		vec.push_back(num);		// ���� ����
		vec_cmp.push_back(num);	// �񱳸� ���� ������ ����
	}

	// �񱳸� ���� ���� �������� ����
	sort(vec_cmp.begin(), vec_cmp.end());

	// unique �޼��带 ���ؼ� �ߺ������� ������ �ڿ� �����Ⱚ�� �����ϴ� ��ġ�� ��ȯ
	// vector.erase �޼��带 ���ؼ� �����Ⱚ�� ����
	vec_cmp.erase(unique(vec_cmp.begin(), vec_cmp.end()), vec_cmp.end());

	for(int i = 0; i < vec.size(); i++)
	{
		vector<int>::iterator itr;

		// lower_bound �޼��带 ���ؼ� key �� �̻��� ���� ó�� ������ idx�� ���� 
		itr = lower_bound(vec_cmp.begin(), vec_cmp.end(), vec[i]);
		cout << itr - vec_cmp.begin() << " ";
	}
}