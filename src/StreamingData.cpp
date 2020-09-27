/**********************************************
this file is the 实现 of onlineoptimization.h
于2020.09.27 调试完成 liangzid
***********************************************/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
#include<exception>
#include<map>
#include "./StreamingData.h"

using namespace std;
using namespace MyDataStream;
//---------------------class data_unordered_perturn-------------------------
data_unordered_perturn::data_unordered_perturn()
{
  ith_feature=vector<float>();
  ith_label=-1;
}

data_unordered_perturn::~data_unordered_perturn()
{
  ;
}

data_unordered_perturn::data_unordered_perturn(const vector<float>& ith_feature)
{
  this->ith_feature=ith_feature;
  this->ith_label=ith_label;
}

data_unordered_perturn::data_unordered_perturn(const vector<float>& ith_feature,const int ith_label)
{
  this->ith_feature=ith_feature;
  this->ith_label=ith_label;
}


vector<float> data_unordered_perturn::get_ith_feature() const
{
  return this->ith_feature;
}

int data_unordered_perturn::get_ith_label() const
{
  return this->ith_label;
}

void data_unordered_perturn::set_ith_feature(const vector<float>& fea)
{
  this->ith_feature=fea;
}

void data_unordered_perturn::set_ith_label(int l)
{
  this->ith_label=l;
}



//---------------------------------------------------------------------------

//--------------class: data_perturn------------------------------------------
data_perturn::data_perturn()
{
  ith_feature=vector<float>();
  ith_label=-1;
  i=-1;
}

data_perturn::~data_perturn()
{
  ;
}

data_perturn::data_perturn(const vector<float>& ith_feature)
{
  this->ith_feature=ith_feature;
  ith_label=-1;
  i=-1;
}

data_perturn::data_perturn(const vector<float>& ith_feature, const int ith_label,const int i)
{
  this->ith_feature=vector<float>(ith_feature);
  this->ith_label=ith_label;
  this->i=i;
}
data_unordered_perturn data_perturn::no_unordered()
{
  auto a_test=data_unordered_perturn(this->ith_feature,this->ith_label);
  return a_test;
}

vector<float> data_perturn::get_ith_feature() const 
{
  auto vec_n= vector<float>{this->ith_feature};
  return vec_n;
}

int data_perturn::get_ith_label() const
{
  return this->ith_label;
}

int data_perturn::get_i() const 
{
  return this->i;
}

void data_perturn::set_ith_feature(const vector<float> vec)
{
  this->ith_feature=vec;
}
void data_perturn::set_ith_label(const int la)
{
  this->ith_label=la;
}

void data_perturn::set_i(const int i)
{
  this->i=i;
}


//--------------------------------end-----------------------------------------

//-----------------------class: Streamingdata---------------------------------
StreamingData::StreamingData()
{
  // is_have_order=false;
  data_thisturn=data_perturn();
  features_before=vector<data_perturn>();
}
// StreamingData::StreamingData(const istream& input_data)
// {
//   data_thisturn<<input_data;
//   features_before=vector<data_perturn>();

// }

// //不会写，没写出来
// StreamingData::StreamingData(const string batch_file)
// {
//   //？？？？
// }
StreamingData::StreamingData(const string& stream_file)
{
      this->infile.open(stream_file);
      string aline;
      vector<string> alist;
      getline(infile,aline);
      MyDataStream::DSutils::split(aline,alist," ");
      auto index=stoi(alist[0]);
      auto label=stoi(alist[1]);
      vector<float> feature;
      vector<string> tempattsStr;
      MyDataStream::DSutils::split(alist[2],tempattsStr,",");
      for(auto ele:tempattsStr)
	{
	  if(ele=="\n")
	    continue;
	  feature.push_back(stof(ele));
	}
      data_thisturn=data_perturn(feature,label,index);
  // try
  //   {     
  //     infile.open(stream_file);
  //     string aline;
  //     vector<string> alist;
  //     getline(infile,aline);
  //     MyDataStream::DSutils::split(aline,alist," ");
  //     auto index=stoi(alist[0]);
  //     auto label=stoi(alist[1]);
  //     vector<float> feature;
  //     vector<string> tempattsStr;
  //     MyDataStream::DSutils::split(alist[2],tempattsStr,",");
  //     for(auto ele:tempattsStr)
  // 	{
  // 	  if(ele=="\n")
  // 	    continue;
  // 	  feature.push_back(stof(ele));
  // 	}
  //     data_thisturn=data_perturn(feature,label,index);
  //   }
  // catch(exception e)
  //   {
  //     cout<<"initial SD error."<<endl;
  //     infile.close();
  //   }
  
}

StreamingData::~StreamingData()
{
  // infile.close();
}


data_perturn StreamingData::update_1_time()
{
  string aline;
  vector<string> alist;
  if(getline(infile,aline))
    {
      MyDataStream::DSutils::split(aline,alist," ");
      auto index=stoi(alist[0]);
      auto label=stoi(alist[1]);
      vector<float> feature;
      vector<string> tempattsStr;
      MyDataStream::DSutils::split(alist[2],tempattsStr,",");
      for(auto ele:tempattsStr)
	{
	  if(ele=="\n")
	    continue;
	  feature.push_back(stof(ele));
	}

      features_before.push_back(data_thisturn);
      data_thisturn=data_perturn(feature,label,index);
    }
  else
    {
      cout<<"at the end of file. this is no data."<<endl;
      features_before.push_back(data_thisturn);
      data_thisturn=data_perturn();
    }
  return data_thisturn;
}

data_perturn StreamingData::update_m_times(int m)
{
  for(int i=0;i<m;i++)
    {
      update_1_time();
    }
  return data_thisturn;
}

data_perturn StreamingData::get_data_this_turn()
{
  
  return this->data_thisturn;
}


int StreamingData::get_this_i()
{
  return this->data_thisturn.get_i();
}

vector<float> StreamingData::get_this_feature()
{
  return vector<float>(this->data_thisturn.get_ith_feature());
}

int StreamingData::get_this_label()
{
  return this->data_thisturn.get_ith_label();
}

vector<data_perturn> StreamingData::get_features_before()
{
  return vector<data_perturn>(this->features_before); 
}

//-------------------------end----------------------------------------

//-----------------------static class: DSutils-----------------------

//s: 被切割的字符串s，v:存储被切割之后的字符串, c:分隔符
void DSutils::split(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find (c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

// StreamingData DSutils::batch2stream(const BatchData& b_dat)
// {  
// }

// BatchData DSutils::stream2batch(const StreamingData& s_dat)
// {
//   ;
// }

void DSutils::save_as_stream_file(const string path, const BatchData& b_dat)
{
  ofstream outfile;
  try
    {
      outfile.open(path);
      for(auto data_pt:b_dat)
	{
	  string index=to_string(data_pt.get_i());
	  string label=to_string(data_pt.get_ith_label());
	  string vecstr;
	  auto fea=data_pt.get_ith_feature();
	  for (auto numb:fea)
	    {
	      // cout<<numb<<endl;
	      vecstr+=to_string(numb);
	      vecstr+=",";
	    }
	  vecstr+="\n";
	  string aline=index+" "+label+" "+vecstr;
	  outfile<<aline;
	}
    }
  catch(exception e)
    {
      cout<<"error! exit!!"<<endl;
      outfile.close();
    }
  outfile.close();
}


data_perturn DSutils::add_numoftutrn_2_ordered(const data_unordered_perturn& dup,const int i)
{
  return data_perturn(dup.get_ith_feature(), dup.get_ith_label(),i);
}

//指从我们的标准格式文件中获取得到数据的基本信息
void DSutils::read_from_stream_file(const string& path, BatchData& bd)
{
  // string path="../../data/letter.scale.sf";
  ifstream infile;
  try
    {
      infile.open(path);
      // infile=ifstream(path,ios::in|ios::binary);
      string aline;
      int ceshi=1;
      while(getline(infile,aline)&& ceshi==1)
	{
	  //将字符串切割成一个vector
	  vector<string> alist;
	  split(aline,alist," ");
	  auto index=stoi(alist[0]);
	  auto label=stoi(alist[1]);
	  vector<float> feature;
	  vector<string>tempattsStr;
	  split(alist[2],tempattsStr,",");
	  for(auto ele:tempattsStr)
	    {
	      if (ele=="\n")
		continue;
	      feature.push_back(stof(ele));
	    }

	  bd.push_back(data_perturn(feature,label,index));
	  // cout<<index<<' '<<label<<endl;
	  // for(auto fea :feature)
	  //   {
	  //     cout<<fea<<endl;
	  //   }	  
	  // ceshi++;
	}
    }
  catch(exception e)
    {
      infile.close();
    }
  infile.close();
}

void DSutils::read_from_batch_file(const string& path, BatchData& bd)
{
  // string path="../../data/letter.scale.sf";
  ifstream infile;
  try
    {
      infile.open(path);
      // infile=ifstream(path,ios::in|ios::binary);
      string aline;
      int ceshi=1;
      int index=0;
      while(getline(infile,aline)&& ceshi==1)
	{
	  //将字符串切割成一个vector
	  vector<string> alist;
	  split(aline,alist," ");
	  auto label=stoi(alist[0]);

	  map<int,float> amap;
	  for(auto a:alist)
	    {
	      if(a==alist[0])
		continue;
	      vector<string> kvlist;
	      split(a,kvlist,":");
	      amap[stoi(kvlist[0])]=stof(kvlist[1]);
	    }
	  
	  vector<string> lengthstrs;
	  split(alist.at(alist.size()-1),lengthstrs,":");
	  auto length=stoi(lengthstrs[0]);
	  auto feature=vector<float>();
	  for(int i=0;i!=length;i++)
	    {
	      if (amap.find(i+1)!=amap.end())
		feature.push_back(amap[i+1]);
	      else
		{
		  feature.push_back(0.0);
		}
	    }
	  bd.push_back(data_perturn(feature,label,index));
	  index++;
	  // cout<<index<<' '<<label<<endl;
	  // for(auto fea :feature)
	  //   {
	  //     cout<<fea<<endl;
	  //   }	  
	  // ceshi++;
	}
    }
  catch(exception e)
    {
      infile.close();
    }
  infile.close();
  
}


