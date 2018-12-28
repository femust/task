#ifndef FILTER_H
#define FILTER_H

#include<iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>

enum class EdgeDetectionMethod{
    Laplace4,
    Laplace8,
};

class Filter{
public:
    Filter();
    virtual ~Filter();
    cv::Mat execute(cv::Mat image);
    virtual void display()=0;
    std::shared_ptr<Filter> filter_;
};

class FilterFactory{
public:
    FilterFactory();
    static std::shared_ptr<Filter> make_filter(EdgeDetectionMethod);
};

class Laplace4 : public Filter{
public:
    Laplace4();
    ~Laplace4();
    void display();
private:
    std::vector< std::vector<int>>  kernel_={{0,-1,0},
                                             {-1,4,-1},
                                             {0,-1,0}};
};

class Laplace8 : public Filter{
public:
    Laplace8();
    ~Laplace8();
    void display();
private:
    std::vector< std::vector<int>> kernel_={{-1,-1,-1},
                                             {-1,8,-1},
                                             {-1,-1,-1}};
};








#endif // FILTER_H
