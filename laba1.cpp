#include <iostream>

using namespace std;

bool imp(bool a,bool b){
  if((a == 0) && (b == 1)){
    return 0;
  }
  else{
    return 1;
  }
}

int main(){
  cout << "Enter x, y and z" << endl;
  bool x, y, z, p1, p2, ans;
  cin >> x >> y >> z;
  p1 = (x && (y && z));
  p2 = (x || y || z);
  ans = imp(p1 , p2);
  cout << "Answer is:" << ans << endl;
  return 0;
  }
