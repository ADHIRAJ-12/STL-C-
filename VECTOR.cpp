arrays:
#include <iostream>
#include<array>

using namespace std;
int main() {
  
  int basic[3] ={1,2,3};

  array<int,4> a = {1,2,3,4};

  int size = a.size();

  for(int i=0;i<size;i++ ){ 
    cout<<a[i]<<endl;
  }

  cout<<"Element at 2nd Index-> "<<a.at(2)<<endl;

  cout<<"Empty or not-> "<<a.empty()<<endl;

  cout<<"First Element-> "<<a.front()<<endl;
  cout<<"last Element-> "<<a.back()<<endl;

}


Vector:

#include <iostream>
#include<vector>
using namespace std;
int main() {
  
  vector<int> v;

  vector<int> a(5,1);

  vector<int> last(a);
  
   cout<<"print last"<<endl;
  for(int i:last) {
    cout<<i<<" ";
  }cout<<endl;

  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(1);
  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(2);
  cout<<"Capacity-> "<<v.capacity()<<endl;

  v.push_back(3);
  cout<<"Capacity-> "<<v.capacity()<<endl;
  cout<<"Size-> "<<v.size()<<endl;

  cout<<"Elemetn at 2nd Index" <<v.at(2)<<endl;

  cout<<"front " <<v.front()<<endl;
  cout<<"back " <<v.back()<<endl;

 cout<<"before pop"<<endl;
  for(int i:v) {
    cout<<i<<" ";
  }cout<<endl;

  v.pop_back();

  cout<<"after pop"<<endl;
  for(int i:v) {
    cout<<i<<" ";
  }

  cout<<"before clear size "<<v.size()<<endl;
  v.clear();
  cout<<"after clear size "<<v.size()<<endl;



}
