#include<iostream>

using namespace std;

int main() {

    int N;
    int cnt = 0;

    cin >> N;
    
    for(int i = 0; i <= N; i++)
    {
        // 시간이 3시, 13시, 23시라면 무조건 포함되므로 더 이상 순회하지 말고 +3600
        if((i % 10) == 3) 
        {
            cnt += 3600;
            continue;
        }
        for(int j = 0; j < 60; j++)
        {
            // 분이 3분, 13분, 23분, 43분, 53분, 30분대라면 무조건 포함되므로 더 이상 순회하지 말고 +60
            if(((j / 10) == 3) || ((j % 10) == 3))
            {
                cnt += 60;
                continue;
            }
            for(int k = 0; k < 60; k++)
            {
                // 초가 3초, 13초, 23초, 43초, 53초, 30초대라면 포함되므로 +1
                if(((k / 10) == 3) || ((k % 10) == 3))
                {
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;
}