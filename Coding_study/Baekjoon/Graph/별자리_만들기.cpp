#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 100

using namespace std;

// 사용할 변수 초기화
int n = 0;
double x = 0;
double y = 0;
double ans = 0;

// 부모 테이블
int parent[MAX];

// 별들의 좌표 벡터
vector<pair<double, double>> v;

// 별들 사이의 거리 벡터
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

int main()
{
	scanf("%d", &n);

	// 별들의 좌표 입력
	for(int i = 0; i < n; i++)
	{
		scanf("%lf %lf",&x, &y);
		v.push_back({x, y});
	}

	// 별들 사이의 거리 계산하고 vv 벡터에 추가
	for(int i = 0; i < n; i++)
	{
		double a = v[i].first;
		double b = v[i].second;

		for(int j = i + 1; j < n; j++)
		{
			double aa = v[j].first;
			double bb = v[j].second;
			double path = sqrt(pow(aa - a, 2) + pow(bb - b, 2));

			vv.push_back({path, {i, j}});
		}
	}

	// 부모 테이블 초기화
	for(int i = 0; i < n; i++)
	{
		parent[i] = i;
	}

	// 별들의 거리 오름차순 정렬
	sort(vv.begin(), vv.end());

	for(int i = 0; i < vv.size(); i++)
	{
		// dis는 두 별들 사이의 거리
		// x,y는 두 별의 번호
		double dis = vv[i].first;
		x = vv[i].second.first;
		y = vv[i].second.second;

		// 순회하는 두 별의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(x) != find_parent(y))
		{
			// 두 별 union 연산
			union_parent(x, y);

			// 거리 갱신
			ans += dis;
		}
	}

	printf("%.2lf\n", ans);
}