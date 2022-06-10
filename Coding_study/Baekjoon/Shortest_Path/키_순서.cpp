#include<iostream>

#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MAX 501 // 최대 학생 수가 500명이므로 501을 MAX 값으로 설정

using namespace std;

// 사용할 변수 초기화
int N = 0;
int M = 0;
int u = 0;
int v = 0;
int cnt = 0;

// 2차원 최단거리 테이블
int graph[MAX][MAX];

int main()
{
    cin >> N >> M;

    // 최단거리 테이블 INF로 초기화
    for(int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }

    // 학생들의 키 비교 데이터 입력
    for(int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);

        // u번째 학생보다 v번째 학생이 키가 더 크다는 
        graph[u][v] = 1;
    }

    // 플로이드 워셜 알고리즘 수행
    for(int k = 1; k <= N; k++)
    {
        for(int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= N; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        int temp = 0;

        // 각 번호의 열과 행을 순회
        for(int j = 1; j <= N; j++)
        {
            // 순회중인 열과 행에 INF(키를 비교한 적이 없다는 의미)가 없다면 temp 값 증가
            if((graph[i][j] != INF) || (graph[j][i] != INF))
            {
                temp++;
            }
        }

        // temp 값이 graph[i][j]를 제외하고 INF가 없다면 키의 순서를 알 수 있으므로 cnt 증가
        if(temp == N - 1)
        {
            cnt++;
        }
    }

    cout << cnt << endl;

}