#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 1001

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;
double ans = 0;

// 부모 테이블
int parent[MAX];

// 좌표 벡터
vector<pair<int, int>> v;

// 이미 연결된 신들의 벡터
vector<pair<int, int>> alv;

// 신들과의 거리 벡터
vector<pair<double, pair<int, int>>> vv;

// find 연산
int find_parent(int a)
{
	// a의 부모가 a라면 루트노드라는 의미
	if(a == parent[a])
	{
		return a;
	}
	// a의 부모가 a가 아니라면 부모 테이블 갱신 및 재귀호출
	else
	{
		return parent[a] = find_parent(parent[a]);
	}
}

// union 연산
void union_parent(int a, int b)
{
	// a,b의 부모 찾기
	a = find_parent(a);
	b = find_parent(b);

	// 더 작은 값이 부모가 되도록 설정
	if(a < b)
	{
		parent[b] = a;
	}
	else
	{
		parent[a] = b;
	}
}

// 이미 연결된 신들에 대해서 union 연산
void union_already()
{
	for(int i = 0; i < alv.size(); i++)
	{
		// 순회하는 두 신들의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(alv[i].first) != find_parent(alv[i].second))
		{
			// 두 신들 union 연산
			union_parent(alv[i].first, alv[i].second);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	// 신들의 좌표 입력
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}

	// 이미 연결되어 있는 신들 입력
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		alv.push_back({a, b});
	}

	// 신들의 통로 길이 계산하고 vv 벡터에 추가
	for(int i = 0; i < N; i++)
	{
		double a = v[i].first;
		double b = v[i].second;

		for(int j = i + 1; j < N; j++)
		{
			double aa = v[j].first;
			double bb = v[j].second;
			double dis = sqrt(pow(aa - a, 2) + pow(bb - b, 2));

			vv.push_back({dis,{i + 1, j + 1}});
		}
	}

	// 부모 테이블 초기화
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}

	// 통로 길이 오름차순 정렬
	sort(vv.begin(), vv.end());

	// 이미 연결된 신들은 미리 union 연산 수행
	union_already();

	for(int i = 0; i < vv.size(); i++)
	{
		// path는 두 신들의 통로 길이
		// a, b는 두 신들
		double path = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;

		// 순회하는 두 신들의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{

			// 두 신들 union 연산
			union_parent(a, b);

			// 길이 갱신
			ans += path;
		}
	}

	printf("%.2lf\n", ans);
}