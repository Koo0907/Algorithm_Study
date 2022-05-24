#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int start_time = 0;
int end_time = 0;

vector<pair<int, int>> class_time;

// vector<int> ���ڿ� greater<int> ���ڸ� �߰� �����Ͽ� ������������ ���ĵǴ� �켱���� ť �̿�
priority_queue<int, vector<int>, greater<int>> class_room;

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> start_time >> end_time;
        class_time.push_back({start_time, end_time});
    }

    // �����ð����� ������������ ����
    // ���۽ð��� �Ȱ��ٸ� ����ð��� ���� ������ ����
    sort(class_time.begin(), class_time.end());

    // �켱���� ť�� ���� ���� �����ϰ� ���� ���� ������ ù��° ����� ����ð� ����
    class_room.push(class_time[0].second);

    // �ι�° �������� ��ȸ
    for(int i = 1; i < class_time.size(); i++)
    {
        // ��ȸ�ϴ� ������ ���۽ð��� ���� �켱���� ť�� ����ִ� ���� ���� ����ð����� ���ų� ũ�ٸ� ���Ǹ� ���� ���ǽǿ��� �̾ �� �� ����
        if(class_room.top() <= class_time[i].first)
        {
            // �̾��� �� �ִٸ� ���� ���� ����ð� ������ ����
            class_room.pop();
        }

        // ��ȸ�ϴ� ������ ����ð� ����
        class_room.push(class_time[i].second);
    }

    // �켱���� ť�� ũ�Ⱑ ���ǽ��� ���� ������
    cout << class_room.size() << endl;;
}