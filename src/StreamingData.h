#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

#ifndef STREAMING_DATA_H
#define STREAMING_DATA_H


/*
This is the first project of Zi Liang, which is about online machine learning.

And I Want to Design it with fast and easy useage.

2020.09.13*/


/*
于 2020.09.27 调试完成
*/


// datastream
namespace MyDataStream{

  //不带索引的流数据对象中的每一轮
  class data_unordered_perturn
  {
    // using vecTYPE=array<T,len>; //暂时不采用模板去进行封装，有时间一定进行补充
  public:
    data_unordered_perturn();
    ~data_unordered_perturn();
    data_unordered_perturn(const vector<float>& ith_feature);
    data_unordered_perturn(const vector<float>& ith_feature,const int ith_label);
    vector<float> get_ith_feature()const ;  //????????????????
    int get_ith_label() const;
    void set_ith_feature(const vector<float>& fea);
    void set_ith_label(int l);
  private:
    vector<float> ith_feature;
    // float ith_feature_test[dim];//仅仅作为测试,不保证最终可以这样用 
    int ith_label;
  };

  //带索引的流数据对象中的每一轮
  class data_perturn{
  public:
    data_perturn();
    ~data_perturn();
    data_perturn(const vector<float>& ith_feature);
    data_perturn(const vector<float>& ith_feature, const int ith_label,const int i);
    data_unordered_perturn no_unordered();

    vector<float> get_ith_feature()const;
    int get_ith_label()const;
    int get_i()const;

    void set_ith_feature(const vector<float> vec);
    void set_ith_label(const int la);
    void set_i(const int i);
  private:
    vector<float> ith_feature;
    int ith_label;
    int i;
  };

  
  //关于流式数据的一个类
  class StreamingData{
  private:

    //一个流格式的stream;
    // istream sadLiangzi;
    // bool is_have_order;
    ifstream infile;
    data_perturn data_thisturn;
    vector<data_perturn > features_before;
  public:

    StreamingData();
    ~StreamingData();
    // StreamingData(const istream & input_data);
    // StreamingData(const string batch_file);
    StreamingData(const string& stream_file);

    data_perturn update_1_time();
    data_perturn update_m_times(int m);
    
    data_perturn get_data_this_turn();
    int get_this_i();
    vector<float> get_this_feature();
    int get_this_label();
    vector<data_perturn > get_features_before();
    
  };

  using BatchData=vector<data_perturn>;
  // struct BatchData{
  //   int dim;
  //   vector<data_perturn> data;
  // };

  // class File{
  //   //something
  // };


  
  //定义一个静态方法类,封装所需要的所有基本方法-->更新：C++没有静态类
  
  class DSutils{
  public:
    static StreamingData batch2stream(const BatchData & b_dat);
    static BatchData stream2batch(const StreamingData & s_dat);

    static void save_as_stream_file(const string path, const BatchData & b_dat);

    static data_perturn add_numoftutrn_2_ordered(const data_unordered_perturn& dup,const int i);
    
    static void read_from_stream_file(const string& path, BatchData& bd);
    static void read_from_batch_file(const string& path,BatchData& bd);
    static void split(const std::string& s, std::vector<std::string>& v, const std::string& c);
  };
  
}

// /********************************************************************
//                        在线学习算法命名空间的封装
//  ********************************************************************/

// //包含了所有基本算法的命名空间
// namespace OpenOnlineLearning
// {
//   //定义数据流的基本格式
//     class BasicDataStream
//     {
//         BasicDataStream();
//         ~BasicDataStream();
//     };

//   //定义几种典型的,可供使用的损失函数
//     enum loss_func
//     {
//         design_myself,cross_entropy,somethingothers
//     };


//   //定义online learning算法的基类
//     class BasicOnlineLearning
//     {
//         public:
//         BasicOnlineLearning();
//         ~BasicOnlineLearning();
//         BasicOnlineLearning(const BasicDataStream& stream_data, const std::string loss_func, const std::string opti_methd);
        
//     };

// };



// //定义关于模型优化的基本的优化类
// namespace OnlineOptimization
// {

//     //定义一个所有优化算法的基类
//     class Basic_online_optimization_method
//     {
//     private:
//         /* data */
//     public:
//         Basic_online_optimization_method(/* args */);
//         ~Basic_online_optimization_method();
//     };
    

//   //定义在线梯度下降算法
//     class Online_gradient_descent:OnlineOptimization::Basic_online_optimization_method
//     {
//         private:

//         public:
//         Online_gradient_descent(float & learning_rate,);
//         ~Online_gradient_descent();

//     };

//     //定义几种基本的模型优化方法
//     enum opti_methd
//     {
//         OGD,FTRL
//     };



// }

#endif  //STREAMING_DATA_H
