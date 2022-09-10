/* 프로그래머스 */
/* https://school.programmers.co.kr/learn/courses/30/lessons/43164 */
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 방문 처리를 위한 배열
bool visited[10000];

// 여행 경로 벡터
vector<string> vec;

bool dfs(string now, vector<vector<string>> tickets, int depth)
{
	// dfs의 깊이(여행 경로)가 티켓의 수와 같다면 전부 확인한 것이므로 true 반환
    if(depth == tickets.size())
    {
        return true;
    }
    
	// 티켓 전부를 확인
    for(int i = 0; i < tickets.size(); i++)
    {
		// 티켓의 출발 공항이 파라미터로 들어온 공항과 같고 아직 방문하지 않은 티켓이라면 아래 로직 수행
        if(tickets[i][0] == now && visited[i] == false)
        {
			// 티켓 방문 처리
            visited[i] = true;

			// 티켓의 도착 공항 벡터에 추가
            vec.push_back(tickets[i][1]);
			
			// 티켓의 도착 공항을 출발 공항으로 설정하고 확인한 티켓 수를 1 증가 설정한 DFS 함수 호출
            bool temp_res = dfs(tickets[i][1], tickets, depth + 1);

			// 위에서의 DFS 함수가 true라면 여행 경로가 티켓을 모두 확인하기 전에 끊키지 않았다는 뜻이므로 true 반환
            if(temp_res == true)
            {
                return true;
            }
			// 위에서의 DFS 함수가 false라면 여행 경로가 티켓을 모두 확인하기 전에 끊켰다는 의미므로 현재 확인한 티켓은 방문 처리 취소
            else
            {
                visited[i] = false;
            }
        }
    }
    
	// 티켓 전부를 확인했는데도 파라미터로 들어온 출발 공항의 티켓을 찾지 못한 경우에는 마지막 벡터에 추가된 공항 삭제하고 false 반환
    vec.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
	// 티켓 오름차순 정렬
    sort(tickets.begin(), tickets.end());
    
	// 시작 공항 벡터에 추가
    vec.push_back("ICN");
    
	// DFS 함수 호출
    dfs("ICN", tickets, 0);
    
	// answer 벡터에 정답 벡터 대입
    answer = vec;
    
    return answer;
}