#include<vector>
#include<iostream>
#include<array>
#include "tv.h"

using namespace std;
// using namespace myvec;

// typedef vector<float> vecTYPE;


// testVec::testVec()
// {
//   test1=vecTYPE();
// }

// testVec::testVec(const vecTYPE& some1)
// {
//   this->test1=some1;
// }
// testVec::~testVec()
// {
//   ;
// }

// vecTYPE testVec::get_test_1()
// {
//   return vecTYPE(this->test1);
// }

// int main()
// {
//   vecTYPE liangzi={1,2,3,4,5};
//   // testVec a=testVec();
  
//   auto a=testVec(liangzi);
//   auto cc=a.get_test_1();
//   cout<<cc[0]<<endl;
//   return 0;
// }


template<typename t,int len>
myvec<t,len>::myvec()
{
  testvec=vecTYPE();
}

template<typename t,int len>
myvec<t,len>::~myvec()
{
  ;
}

template<typename t,int len>
myvec<t,len>::myvec(const vecTYPE& a)
{
  testvec=vecTYPE(a);
}


int main()
{
  array<float,3> a={1,2,3};
  cout<<a[1]<<endl;
  auto cc=myvec<float,3>(a);
  cout<<cc.testvec[0]<<endl;
  return 0;
}
