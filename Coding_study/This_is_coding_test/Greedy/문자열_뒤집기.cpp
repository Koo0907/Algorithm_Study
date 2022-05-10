#include<iostream>
#include<string>

using namespace std;

int main() {

   string str;
   int cnt = 0;

   cin >> str;
   for(int i = 1; i < str.length(); i++)
   {
       // 순회하는 문자가 첫번째 문자와 다르고 바로 앞의 문자와도 다르다면 1 증가
       if((str[i] != str[0]) && (str[i] != str[i-1]))
       {
           cnt++;
       }
   }
   
   cout << cnt << endl;
}