#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// 사용할 변수들 초기화
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
		vec.push_back(num);		// 원본 벡터
		vec_cmp.push_back(num);	// 비교를 위해 정렬할 벡터
	}

	// 비교를 위한 벡터 오름차순 정렬
	sort(vec_cmp.begin(), vec_cmp.end());

	// unique 메서드를 통해서 중복값들을 제거한 뒤에 쓰레기값을 저장하는 위치를 반환
	// vector.erase 메서드를 통해서 쓰레기값들 삭제
	vec_cmp.erase(unique(vec_cmp.begin(), vec_cmp.end()), vec_cmp.end());

	for(int i = 0; i < vec.size(); i++)
	{
		vector<int>::iterator itr;

		// lower_bound 메서드를 통해서 key 값 이상의 값이 처음 나오는 idx를 구함 
		itr = lower_bound(vec_cmp.begin(), vec_cmp.end(), vec[i]);
		cout << itr - vec_cmp.begin() << " ";
	}
}