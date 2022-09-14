#include<iostream>
#include<vector>
#include<algorithm>

#define MAX 101010

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int a = 0;
int b = 0;
int c = 0;
long long all_path = 0;
long long minimum_path = 0;
int cnt = 0;

// 부모 테이블
int parent[MAX];

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
    scanf("%d %d", &N, &M);

    for(int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &a, &b, &c);  // 경로 데이터 입력
        vec.push_back({c, {a, b}});     // 경로 데이터 갱신
        all_path += c;                  // 모든 경로 길이 계산
    }

    for(int i = 1; i <= N; i++)
    {
        // 부모 테이블 초기화
        parent[i] = i;
    }

    // 경로 오름차순 정렬
    sort(vec.begin(), vec.end());

    // 경로들 순회
    for(int i = 0; i < vec.size(); i++)
    {
        // a, b는 건물
        // dis는 두 건물의 길이
        int a = vec[i].second.first;
        int b = vec[i].second.second;
        int dis = vec[i].first;

        // 순회하는 두 건물의 부모 테이블이 다르다면(사이클이 형성되지 않는다면) 아래 로직 수행
        if(find_parent(a) != find_parent(b))
        {
            // 두 건물 union 연산
            union_parent(a, b);

            // 최소 경로 갱신
            minimum_path += dis;

            // 경로 수 증가
            cnt++;
        }
    }

    // 경로 수가 N-1개라면 모든 건물을 연결함을 의미
    if(cnt == (N - 1))
    {
        printf("%lld\n", all_path - minimum_path);
    }
    else
    {
        printf("-1\n");
    }
}