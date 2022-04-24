#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    
    int N;
    int x;
    int res = 0;
    int num = 0;
    vector<int> fear;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> x;
        fear.push_back(x);
    }

    sort(fear.begin(), fear.end());

    for(vector<int>::iterator itr = fear.begin(); itr != fear.end(); itr++)
    {
        num++;
        if(num >= *itr)
        {
            res++;
            num = 0;
        }
    }

    cout << res << endl;
}