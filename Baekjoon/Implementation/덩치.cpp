#include<iostream>
#include<vector>
#include<utility>

using namespace std;

int main() {

    int N;
    int x;
    int y;
    int rank = 1;
    vector<pair<int,int>> phy;
    vector<int> res;

    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        cin >> x >> y;
        phy.push_back({x,y});
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            // ���� �����Կ� Ű�� �ٸ� ����鿡 ���ؼ� �۴ٸ� ��� ����
            if(phy[i].first < phy[j].first && phy[i].second < phy[j].second)
            {
                rank++;
            }
        }
        res.push_back(rank);
        rank = 1;
    }

    for(vector<int>::iterator itr = res.begin(); itr != res.end(); itr++)
    {
        cout << *itr << endl;
    }
}