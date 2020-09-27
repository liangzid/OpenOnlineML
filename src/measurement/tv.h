#include<vector>
#include<array>
using namespace std;

// typedef vector<float> vecTYPE;
// namespace myvec{
//   class testVec
// {
//  private:
//   vecTYPE test1;

//  public:
//   testVec();
//   ~testVec();
//   testVec(const vecTYPE& some1);
//   vecTYPE get_test_1();
// };  
// }

template<typename t,int len> class myvec {
  using vecTYPE=array<t,len>;
 public:
  vecTYPE testvec;
  myvec();
  ~myvec();
  myvec(const vecTYPE& a);
};



