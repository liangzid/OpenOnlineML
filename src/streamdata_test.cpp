#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<array>
#include "./StreamingData.h"
using namespace std;
using namespace MyDataStream;


int main()
{
  StreamingData asd("../data/letter.scale.sf");
  cout<<asd.get_this_feature()[0]<<endl;
  asd.update_1_time();
  cout<<asd.get_this_feature()[0]<<endl;
  cout<<asd.get_features_before()[0].get_ith_feature()[0]<<endl;
  
  // data_perturn dp1=data_perturn({1,2,3},12,1);
  // vector<data_perturn> vd;
  // vd.push_back(dp1);
  // dp1=data_perturn({4,4,4},10,0);
  // vd.push_back(dp1);

  // cout<<vd[0].get_ith_label()<<vd[1].get_ith_label()<<endl;
  
  // string s1="haha";
  // string s2="lala\n";
  // cout<<s1+s2<<endl;

  // ofstream outfile;
  // outfile.open("../data/letter.scale.sf.test");
  // outfile<<(s1+s2);
  // outfile<<(s1+s2);
  // outfile<<(s1+s2);
  
  // outfile.close();

  
  // BatchData cc;
  // // DSutils::read_from_stream_file("../data/letter.scale.sf",cc);
  // DSutils::read_from_batch_file("../data/letter.scale",cc);
  // // cout<<cc[0].get_ith_feature()[0]<<endl;
  // DSutils::save_as_stream_file("../data/letter.scale.sf.test",cc);
  // cout<<"OK";
  
  // vector<float> aa={1,2,3,4};
  // auto a=data_perturn(aa,4,1);
  // // a.set_ith_feature({5,5,5});
  // // cout<<a.get_ith_feature()[2]<<endl;
  // // cout<<a.get_ith_label()<<endl;
  // // cout<<a.get_i()<<endl;

  // // auto b=a.no_unordered();
  // // cout<<b.get_ith_feature()[1]<<endl;

  // BatchData liangzi;
  // liangzi.dim=1;
  // liangzi.data={a,a};

  // // cout<<liangzi->dim<<endl;
  // cout<<liangzi.dim<<endl;
  
  return 0;
}

