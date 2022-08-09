#include<iostream>
#include<algorithm>

using namespace std;

int A_arr[50];
int B_arr[50];
int new_A_arr[50];
int ind = 0;
int res = 0;

int main()
{
	cin >> ind;

	for(int i = 0; i < ind; i++)
	{
		cin >> A_arr[i];
	}

	for(int i = 0; i < ind; i++)
	{
		cin >> B_arr[i];
	}

	// A 배열을 오름차순 정렬
	sort(A_arr, A_arr + ind);

	// B 배열을 내림차순 정렬
	sort(B_arr, B_arr + ind, greater<>());

	for(int i = 0; i < ind; i++)
	{
		res += (A_arr[i] * B_arr[i]);
	}

	cout << res << endl;
}