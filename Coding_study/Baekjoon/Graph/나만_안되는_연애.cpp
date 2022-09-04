#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 1000

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
char S = 0;
int u = 0;
int v = 0;
int d = 0;
int cnt = 0;
int ans = 0;

// 부모 테이블
int parent[MAX];

// 남초,여초 테이블
char ManWoman[MAX];

// 경로 데이터 벡터
vector<pair<int, pair<int, int>>> vec;

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
	scanf("%d %d",&N, &M);

	for(int i = 1; i <= N; i++)
	{
		cin.ignore();		// 입력 버퍼 제거
		scanf("%c", &S);	// 남초, 여초 정보 입력
		ManWoman[i] = S;	// 남초, 여초 테이블 갱신
		parent[i] = i;		// 부모 테이블 초기화
	}

	// 경로 데이터 입력
	for(int i = 0; i < M; i++)
	{
		scanf("%d %d %d", &u, &v, &d);
		vec.push_back({d, {u, v}});
	}

	// 경로 오름차순 정렬
	sort(vec.begin(), vec.end());

	for(int i = 0; i < vec.size(); i++)
	{
		// dist는 두 학교의 경로 길이
		// a와 b는 두 학교
		int dist = vec[i].first;
		int a = vec[i].second.first;
		int b = vec[i].second.second;

		// 연결되어 있는 두 학교가 다른 성비를 가지고 있다면 아래 로직 수행
		if(ManWoman[a] != ManWoman[b])
		{
			// 순회하는 두 학교의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
			if(find_parent(a) != find_parent(b))
			{
				// 두 노드 union 연산
				union_parent(a, b);
				
				// 경로 갱신
				ans += dist;

				// 경로 수 증가
				cnt++;
			}
		}
	}

	// 경로 수가 N-1개라면 모든 학교 연결함을 의미
	if(cnt == N - 1)
	{
		cout << ans << endl;
	}
	else
	{
		cout << -1 << endl;
	}
}