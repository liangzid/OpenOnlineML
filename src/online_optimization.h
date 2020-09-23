#include<string>
/*
This is the first project of Zi Liang, which is about online machine learning.

And I Want to Design it with fast and easy useage.

2020.09.13

*/

namespace OpenOnlineLearning
{
    class BasicDataStream
    {
        BasicDataStream();
        ~BasicDataStream();
    };

    enum loss_func
    {
        design_myself,cross_entropy,somethingothers
    };
    enum opti_methd
    {
        OGD,FTRL
    };

    class BasicOnlineLearning
    {
        public:
        BasicOnlineLearning();
        ~BasicOnlineLearning();
        BasicOnlineLearning(const BasicDataStream& stream_data, const std::string loss_func, const std::string opti_methd);
        
    };




};




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
    

    class Online_gradient_descent:OnlineOptimization::Basic_online_optimization_method
    {
        private:

        public:
        Online_gradient_descent(float & learning_rate,);
        ~Online_gradient_descent();





    };










}





