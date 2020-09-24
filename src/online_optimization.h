#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef uint unsigned int;
/*
This is the first project of Zi Liang, which is about online machine learning.

And I Want to Design it with fast and easy useage.

2020.09.13

*/

// datastream
namespace MyDataStream{

  //不带索引的流数据对象中的每一轮
  class data_unordered_perturn
  {
  public:
    data_unordered_perturn();
    ~data_unordered_perturn();
    data_unordered_perturn(const vector<float>& ith_feature,const uint ith_label);
    data_perturn add_numoftutrn_2_ordered(int i);
    vector<float> get_ith_feature();//????????????????
    unint get_ith_label();
  private:
    vector<float> ith_feature;
    // float ith_feature_test[dim];//仅仅作为测试,不保证最终可以这样用 
    uint ith_label;
  };

  //带索引的流数据对象中的每一轮
  class data_perturn{
  public:
    data_perturn();
    ~data_unordered_perturn();
    data_perturn(const vector<float>& ith_feature);
    data_perturn(const vector<float>& ith_feature, const uint ith_label,const int i);
    data_unordered_pertur no_unordered();

    vector<float> get_ith_feature();
    uint get_ith_labe();
    int get_i();
  private:
    vector<float> ith_feature;
    uint ith_label;
    int i;
  };

  //关于流式数据的一个类
  class StreamingData{
  private:

    //一个流格式的stream;
    // istream sadLiangzi;
    bool is_have_order;
    data_perturn data_thisturn;
    vector<data_perturn > features_before;
  public:

    StreamingData();
    ~StreamingData();
    StreamingData(const istream & input_data);
    StreamingData(const string batch_file);
    StreamingData(const string stream_file);

    data_perturn update_1_time();
    data_perturn update_m_times(int m);
    
    data_perturn get_data_this_turn();
    int get_this_i();
    vector<float> get_this_feature();
    uint get_this_label();
    vector<vector<float> > get_features_before();
    
  };

  struct BatchData{
    int dim;
    vector<data_perturn> data;
  };

  // class File{
  //   //something
  // };


  
  //定义一个静态方法类,封装所需要的所有基本方法
  static class DSutils{
  public:
    StreamingData & batch2stream(const BatchData & b_dat);
    BatchData & stream2batch(const StreamingData & s_dat);

    void save_as_stream_file(const string path, const BatchData & b_dat);

    BatchData & read_from_stream_file(const string path);
    BatchData & read_from_batch_file(const string path);
    
  };
  
};

/********************************************************************
                       在线学习算法命名空间的封装
 ********************************************************************/

//包含了所有基本算法的命名空间
namespace OpenOnlineLearning
{
  //定义数据流的基本格式
    class BasicDataStream
    {
        BasicDataStream();
        ~BasicDataStream();
    };

  //定义几种典型的,可供使用的损失函数
    enum loss_func
    {
        design_myself,cross_entropy,somethingothers
    };


  //定义online learning算法的基类
    class BasicOnlineLearning
    {
        public:
        BasicOnlineLearning();
        ~BasicOnlineLearning();
        BasicOnlineLearning(const BasicDataStream& stream_data, const std::string loss_func, const std::string opti_methd);
        
    };

};



//定义关于模型优化的基本的优化类
namespace OnlineOptimization
{

    //定义一个所有优化算法的基类
    class Basic_online_optimization_method
    {
    private:
        /* data */
    public:
        Basic_online_optimization_method(/* args */);
        ~Basic_online_optimization_method();
    };
    

  //定义在线梯度下降算法
    class Online_gradient_descent:OnlineOptimization::Basic_online_optimization_method
    {
        private:

        public:
        Online_gradient_descent(float & learning_rate,);
        ~Online_gradient_descent();

    };

    //定义几种基本的模型优化方法
    enum opti_methd
    {
        OGD,FTRL
    };



}





