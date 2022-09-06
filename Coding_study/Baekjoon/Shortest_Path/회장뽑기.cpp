#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1e9
#define MAX 51

using namespace std;

// ����� ���� �ʱ�ȭ
int N = 0;
int a = 0;
int b = 0;
int cri_score = INF;

// �ִܰŸ� �迭
int dis[MAX][MAX];

// ȸ�� �ĺ��� ��� ����
vector<int> v;

// �ִܰŸ� �迭 �ʱ�ȭ
void map_clear(void)
{
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(i != j)
			{
				dis[i][j] = INF;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);

	// �ִܰŸ� 2���� �迭 �ʱ�ȭ
	map_clear();

	while(1)
	{
		scanf("%d %d",&a, &b);
		{
			// �� �Է��� ��� -1�̸� �ݺ��� Ż��
			if((a == -1) && (b == -1))
			{
				break;
			}
		}

		// ���� ģ������ ������ ���� ��� ����
		dis[a][b] = 1;
		dis[b][a] = 1;
	}

	// �÷��̵� ���� �˰��� ����
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	// ��� ������� ��ȸ�ϸ鼭 üũ
	for(int i = 1; i <= N; i++)
	{
		int temp_score = 0;

		// �� �࿡ ���� ū ���� ����
		for(int j = 1; j <= N; j++)
		{
			temp_score = max(temp_score, dis[i][j]);
		}
		
		// �� �࿡�� ���� ū ���� ��������� ȸ�� �ĺ� ���� ������ ��
		// ȸ�� �ĺ� ���� �������� �۴ٸ� �Ʒ� ���� ����
		if(temp_score < cri_score)
		{
			// ȸ�� �ĺ� ��� ���� �ʱ�ȭ
			v.clear();

			// ȸ�� �ĺ� ���� ���� ����
			cri_score = temp_score;

			// ��ȸ���� ��� �߰�
			v.push_back(i);
		}
		// ȸ�� �ĺ� ���� ������ ���ٸ� �Ʒ� ���� ����
		else if(temp_score == cri_score)
		{
			// ȸ�� �ĺ� ��� ���Ϳ� ��ȸ���� ��� �߰�
			v.push_back(i);
		}
		else
		{
			//nothing...
		}
	}

	// ȸ�� �ĺ� ��� ���� �������� ����
	sort(v.begin(), v.end());

	// ȸ�� ���� ������ �ĺ� �� ���
	cout << cri_score << " " << v.size() << endl;

	// ȸ�� �ĺ� ����� ���
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}