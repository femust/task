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
    cv::Mat execute(cv::Mat image);
};

class FilterFactory{
public:
    static std::shared_ptr<Filter> make_filter(EdgeDetectionMethod);
};

class Laplace4 : public Filter{
private:
    std::vector< std::vector<int>>  kernel_={{0,-1,0},
                                             {-1,4,-1},
                                             {0,-1,0}};
};

class Laplace8 : public Filter{
private:
    std::vector< std::vector<int>> kernel_={{-1,-1,-1},
                                             {-1,8,-1},
                                             {-1,-1,-1}};
};








#endif // FILTER_H
