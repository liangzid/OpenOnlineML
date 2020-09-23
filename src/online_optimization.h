#include<string>
/*
This is the first project of Zi Liang, which is about online machine learning.

And I Want to Design it with fast and easy useage.

2020.09.13

*/

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





