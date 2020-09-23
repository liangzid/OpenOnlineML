#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> result;
        int i=0;
        wordList.push_back(endWord);
        vector<vector<string>> candidate;
        vector<vector<string>> needErase;
        while(needErase.size()!=candidate.size() || i!=0)
        {
            for(auto ele : candidate)
            {
                cout<<ele;
            }
            if(i==0)
            {
                for (int i=0;i<wordList.size();i++)
                {
                    if(isOneChange(wordList[i],beginWord))
                    {
                        auto temp=vector<string>{beginWord,wordList[i]};
                        candidate.push_back(temp);
                    }
                }
            }
            else
            {
                int flagNeedStop=0;
                for (int j=0;j<candidate.size();j++)
                {
                    for(int k=0;k<wordList.size();k++)
                    {
                        if (isOneChange(candidate[j][candidate[j].size()-1],wordList[k]))
                        {
                            candidate[j].push_back(wordList[k]);
                            if(k==(wordList.size()-1))
                            {
                                //相当于找到了最后的一个元素
                                flagNeedStop=1;
                            }
                        }
                        else if(k==(wordList.size()-1))
                        {
                            needErase.push_back(candidate[j]);
                        }
                    }
                }
                if(flagNeedStop==1)
                {
                    vector<vector<string>> result;
                    for(int qq=0;qq<candidate.size();qq++)
                    {
                        if (candidate[qq][candidate[qq].size()-1]==endWord)
                        {
                            result.push_back(candidate[qq]);
                        }
                    }
                    return result;
                }
                for(auto ele : needErase)
                {
                    for(int ee=0;ee!=candidate.size();ee++)
                    {
                        if (candidate[ee]==ele)
                        {
                            candidate.erase(candidate.begin()+ee);
                            break;
                        }
                    }
                }
                needErase.clear();
            }

            
        }
        return candidate;

    }

    bool isOneChange(string w1,string w2)
    {
        int havechange=0;
        for(int i=0;i<w1.size();i++)
        {
            if (w1.at(i)!=w2.at(i))
            {
                havechange++;
            }
        }
        if (havechange==1)
        {
            return true;
        }
        return false;
    }












};