#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define MAX 100000

using namespace std;

// 사용할 변수 초기화
int N = 0;
int x = 0;
int y = 0;
int z = 0;
int ans = 0;

// 부모 테이블
int parent[MAX];

// 행성 x,y,z 각각의 좌표 벡터
vector<pair<int, int>> v[3];

// 행성들의 거리 벡터
vector<pair<int, pair<int, int>>> vv;

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
	scanf("%d", &N);

	// 행성들의 x,y,z 각각 좌표 입력
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d %d",&x, &y, &z);
		v[0].push_back({x, i});
		v[1].push_back({y, i});
		v[2].push_back({z, i});
		parent[i] = i;
	}

	// 행성들의 x,y,z 각각 좌표 오름차순 정렬
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());

	// 행성들의 x,y,z 각각 좌표를 인접한 행성의 좌표만 비교하여 vv 벡터에 삽입
	// 인접한 좌표가 최소 거리이므로 그 이외의 좌표는 확인할 필요 없음
	// 모든 좌표를 다 확인하면 메모리 초과 발생
	// x축의 거리와 y축의 거리와 z축의 거리 중에서 가장 최소값이 행성을 잇는 비용임을 주의
	for(int i = 0; i < (N - 1); i++)
	{
		vv.push_back({abs(v[0][i].first - v[0][i + 1].first), {v[0][i].second, v[0][i + 1].second}});
		vv.push_back({abs(v[1][i].first - v[1][i + 1].first), {v[1][i].second, v[1][i + 1].second}});
		vv.push_back({abs(v[2][i].first - v[2][i + 1].first), {v[2][i].second, v[2][i + 1].second}});
	}

	// 행성들의 거리 오름차순 정렬
	sort(vv.begin(), vv.end());

	for(int i = 0; i < vv.size(); i++)
	{
		// dis는 두 행성들 사이의 거리
		// x,y는 두 행성의 번호
		int dis = vv[i].first;
		int a = vv[i].second.first;
		int b = vv[i].second.second;

		// 순회하는 두 행성의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
		if(find_parent(a) != find_parent(b))
		{
			// 두 행성 union 연산
			union_parent(a, b);

			// 거리 갱신
			ans += dis;
		}
	}

	printf("%d\n", ans);
}