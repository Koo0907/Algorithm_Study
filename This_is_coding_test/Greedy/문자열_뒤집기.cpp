#include<iostream>
#include<string>

using namespace std;

int main() {

   string str;
   int cnt = 0;

   cin >> str;
   for(int i = 1; i < str.length(); i++)
   {
       // ��ȸ�ϴ� ���ڰ� ù��° ���ڿ� �ٸ��� �ٷ� ���� ���ڿ͵� �ٸ��ٸ� 1 ����
       if((str[i] != str[0]) && (str[i] != str[i-1]))
       {
           cnt++;
       }
   }
   
   cout << cnt << endl;
}