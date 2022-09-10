/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43163 */
#include <string>
#include <vector>

using namespace std;

// 방문 처리를 위한 배열 선언
bool visited[50] = {false};

// 문자열 변환 수
int ret = 50;

// 변환할 수 있는 문자열인지 판단하는 함수
bool check_one_char(string A, string B)
{
    char idx = 0;
    
    // A와 B의 문자열을 비교
    for(int i = 0; i < A.size(); i++)
    {
        // 두 문자열의 문자가 같은 경우만 idx 증가
        if(A[i] == B[i])
        {
            idx++;
        }
    }
    
    // idx 값이 문자열 길이의 1보다 작다면 변환 가능
    if(idx == A.size() - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// DFS 수행 함수
void dfs(string begin, string target, vector<string> words, int step)
{
    // 현재까지 변환한 횟수 이미 구한 최종 변환한 횟수보다 크다면 탐색 의미가 없으므로 함수 종료
    if(ret <= step)
    {
        return;
    }
    
    // begin 문자열과 target 문자열이 같은 경우 아래 로직 수행
    if(begin == target)
    {
        // 기존에 구한 최종 변환한 횟수와 지금 구한 변환 횟수 중에 더 작은값으로 갱신
        ret = min(ret, step);
        return;
    }
    
    // words 벡터 길이만큼 순회
    for(int i = 0; i < words.size(); i++)
    {
        // 순회중인 문자열로 변환 가능하고 아직 방문하지 않았다면 아래 로직 수행
        if(check_one_char(begin, words[i]) && visited[i] == false)
        {
            // 순회중인 문자열 방문 처리
            visited[i] = true;
            
            // 변환한 문자열에서부터 target 문자열을 탐색하고 변환 횟수 1 증가시킨 후에 DFS 함수 호출
            dfs(words[i], target, words, step + 1);
            
            // DSF 함수 종료되면 방문처리를 다시 백트래킹하여 추후에도 다시 탐색할 수 있도록 함
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // DFS 함수 호출
    dfs(begin, target, words, 0);
    
    // 모든 DFS 함수 호출이 끝난 뒤에 ret 변수 확인
	// 기존 초기화 값과 동일하다면 0 출력
    if(ret == 50)
    {
        answer = 0;
    }
	// 값이 갱신되었다면 갱신된 값 출력
    else
    {
        answer = ret;
    }
    
    return answer;
}