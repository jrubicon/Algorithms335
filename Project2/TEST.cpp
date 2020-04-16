#include <iostream>
#include <vector>
using namespace std;

bool is_nonincreasing(const vector<int>& A) {
  //TO DO: Write code for this function, including rewriting the return
  // statement, and then delete these comments.
  bool eqcheck = false;
  bool decheck = false;

  for(int i = 0; i < A.size()-1; i++){
    if(A.at(i) < A.at(i+1)){
      break;
    }
    else if(A.at(i) == A.at(i+1))
      eqcheck = true;
    else if(A.at(i) > A.at(i+1))
      decheck = true;
  }
  if(eqcheck && decheck){
    return true;
  }
  else{
    return false;
  }
  }

void test(int A){
  switch(A){
    case 1:
    cout << "true\n";
    break;
    case 0:
    cout << "false\n";
    break;
  }
}


  int main(){
    cout << "decreasing:\n";
    std::vector<int> v{5,4,3,2,1};

    for(int i=0; i< v.size(); i++)
      cout << v.at(i);
    cout << "\n";
    bool decreasing = is_nonincreasing(v);
    test(decreasing);

    cout << "nonincreasing:\n";
    std::vector<int> y{5,5,3,2,1};

    for(int i=0; i< y.size(); i++)
      cout << y.at(i);
    cout << "\n";
    bool nonincreasing = is_nonincreasing(y);
    cout<< nonincreasing << "\n";
    test(nonincreasing);

    cout << "increasing:\n";
    std::vector<int> x{1,2,3,4,5};

    for(int i=0; i< x.size(); i++)
      cout << x.at(i);
    cout << "\n";
    bool increasing = is_nonincreasing(x);
    test(increasing);

    cout << "nondecreasing:\n";
    std::vector<int> z{1,2,2,3,4};

    for(int i=0; i< z.size(); i++)
      cout << z.at(i);
    cout << "\n";
    bool nondecreasing = is_nonincreasing(z);
    test(nondecreasing);

  return 0;
  }
