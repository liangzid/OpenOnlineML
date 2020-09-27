'''
=================================================================================
这个文件旨在提供一种通用的转化接口。
即试图将LIBSVM（https://www.csie.ntu.edu.tw/~cjlin/libsvmtools/datasets/）格式的数据
转化为本文的流数据集格式，以便进行后续的实验。
                          ---ziliang 2020.09.26
================================================================================
下面是被要求的参考文献：
Chih-Chung Chang and Chih-Jen Lin, LIBSVM : a library for support vector 
machines. ACM Transactions on Intelligent Systems and Technology, 2:27:1--27:27, 
2011. Software available at http://www.csie.ntu.edu.tw/~cjlin/libsvm. 
================================================================================
'''

"""
-----------------------libSVM文件格式--------------------------------------------
libsvm的文件格式是：“label index:value index:value ... index:value”
其中，label是该数据的标签，使用index:value对的方式对特征进行表征，主要是为了应对特征的
稀疏性。
下面是从数据集letter.scale里给出的一段例子：
16 1:-0.466667 2:-0.0666667 3:-0.333333 4:-0.333333 5:-0.333333 6:-0.333333 7:0.2 8:-0.2 9:-0.466667 10:0.0666667 11:-0.0666667 12:0.2 13:-0.733333 14:0.2 15:-0.0666667 16:0.333333 
19 1:-0.0666667 2:0.333333 3:0.0666667 4:-0.0666667 5:-0.466667 6:0.0666667 7:0.0666667 8:-0.333333 9:0.333333 10:0.466667 11:-0.733333 12:0.0666667 13:-0.733333 14:-0.333333 15:-0.333333 16:0.333333 
8 1:-0.466667 2:0.2 3:-0.333333 4:-0.0666667 5:-0.466667 6:-0.0666667 7:-0.0666667 8:0.733333 9:-0.866667 10:-0.0666667 11:-0.2 12:0.0666667 13:-0.6 14:0.0666667 15:-1 16:0.0666667 
8 1:-0.2 2:-0.0666667 3:0.0666667 4:-0.333333 5:-0.466667 6:-0.0666667 7:-0.2 8:-0.6 9:-0.0666667 10:0.333333 11:-0.0666667 12:0.2 13:-0.6 14:0.0666667 15:-0.6 16:-0.0666667 
6 1:-0.466667 2:-0.0666667 3:-0.333333 4:-0.333333 5:-0.6 6:-0.466667 7:0.6 8:-0.733333 9:-0.333333 10:0.733333 11:-0.0666667 12:-0.333333 13:-0.866667 14:0.333333 15:-0.866667 16:-0.0666667 
--------------------------------------------------------------------------------
"""

"""
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                      转化后的期望文件格式
我们希望转化后的流文件具有两种格式，一种是libsvm格式，另一种则是为非稀疏准备的格式，本质
上是一个三元组：“index,label,value1 value2 ... valuen”.
将上面例子中的数据转化为sf格式之后的样子是：

1 16 -0.466667,-0.0666667,-0.333333,-0.333333,-0.333333,-0.333333,0.2,-0.2,-0.466667,0.0666667,-0.0666667,0.2,-0.733333,0.2,-0.0666667,0.333333,0.0,
2 19 -0.0666667,0.333333,0.0666667,-0.0666667,-0.466667,0.0666667,0.0666667,-0.333333,0.333333,0.466667,-0.733333,0.0666667,-0.733333,-0.333333,-0.333333,0.333333,0.0,
3 8 -0.466667,0.2,-0.333333,-0.0666667,-0.466667,-0.0666667,-0.0666667,0.733333,-0.866667,-0.0666667,-0.2,0.0666667,-0.6,0.0666667,-1.0,0.0666667,0.0,
4 8 -0.2,-0.0666667,0.0666667,-0.333333,-0.466667,-0.0666667,-0.2,-0.6,-0.0666667,0.333333,-0.0666667,0.2,-0.6,0.0666667,-0.6,-0.0666667,0.0,


下面是进行此种转化的脚本
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
"""

def libsvm2sf(srcpath,dstpath,length=-1):
    sf=open(dstpath,'a')
    with open( srcpath,'r',encoding="utf-8")as f:
        aline=f.readline()
        index=0
        while aline:
            alist=aline.split(" ")
            # print(alist)
            strLabel=alist[0]

            if length==-1:
                temp=alist[-1]
                length=int(temp.split(':')[0])


            adict={}
            for strele in alist:
                if strele==alist[0] or strele=='\n':
                    continue
                # print(strele)
                i=strele.split(':')[0]
                v=strele.split(":")[1]
                adict[int(i)]=float(v)
            # 获取得到所需要的函数
            strFeature=""
            ct=0
            while ct<=length:
                if ct+1 in adict:
                    strFeature+=(str(adict[ct+1])+',')
                else:
                    strFeature+=(str(0.0)+',')

                ct+=1
                
            strIndex=str(index)
            index+=1

            str_result=strIndex+' '+strLabel+' '+strFeature+'\n'

            sf.write(str_result)
            aline=f.readline()
    sf.close()
    print("OK.")



    
            
if __name__=="__main__":
    sp="../../data/letter.scale"
    dp="../../data/letter.scale.sf"
    libsvm2sf(sp,dp,length=16)
    
    
            










