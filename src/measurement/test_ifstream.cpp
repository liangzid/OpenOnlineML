#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<iostream>
#include<exception>

using namespace std;


void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));

    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}



int main()
{
  string path="../../data/letter.scale.sf";
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
	  cout<<index<<' '<<label<<endl;
	  for(auto fea :feature)
	    {
	      cout<<fea<<endl;
	    }


	  
	  ceshi++;
	}

      
      // infile>>cc;
      // infile>>cc;
      // cout<<"------\nreading from the file:"<<path<<"..."<<endl;
      // cout<<cc<<endl;
      // cout<<dd<<endl;
    }
  catch(exception e)
    {
      infile.close();
    }
  infile.close();
}
