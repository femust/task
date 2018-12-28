#ifndef FILTER_H
#define FILTER_H

#include<iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>

enum class EdgeDetectionMethod{
    Laplace4,
    Laplace8,
    ZeroFilter,
};

class Filter{
public:
    cv::Mat execute(cv::Mat,cv::Mat);
    virtual cv::Mat get_kernel()=0;
};

class FilterFactory{
public:
    static std::shared_ptr<Filter> make_filter(EdgeDetectionMethod);
};

class Laplace4 : public Filter{
public:
    cv::Mat get_kernel() override{return kernel_;};
private:
    cv::Mat kernel_ = (cv::Mat_<double>(3,3) << 0, -1, 0, -1, 4, -1, 0, -1, 0);
};

class Laplace8 : public Filter{
public:
    cv::Mat get_kernel() override{return kernel_;};
private:
    cv::Mat kernel_ = (cv::Mat_<double>(3,3) << -1,-1,-1,-1,8,-1,-1,-1,-1);
};

class ZeroFilter : public Filter{
public:
    cv::Mat get_kernel() override{return kernel_;};
private:
   cv::Mat kernel_ = (cv::Mat_<double>(3,3) << 0, 0, 0, 0, 0, 0, 0, 0, 0);
};


#endif // FILTER_H
