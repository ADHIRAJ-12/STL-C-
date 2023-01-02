
Stack:

#include <iostream>
#include<stack>

using namespace std;
int main() {
  stack<string> s;

  s.push("love");
  s.push("babbar");
  s.push("Kumar");

  cout<<"Top Element-> "<<s.top()<<endl;

  s.pop();
  cout<<"Top Element-> "<<s.top()<<endl;

  cout<<"size of stack"<<s.size()<<endl;

  cout<<"Empty or not "<<s.empty()<<endl;

}
