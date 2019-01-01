#ifndef MERGE_H
#define MERGE_H

#include<iostream>
#include <stdio.h>

#include <opencv2/opencv.hpp>

enum class MergeMethod{
    Maximum,
};

class Merge{
public:
    virtual void execute(std::vector<cv::Mat>&,cv::Mat&,cv::Mat&) = 0;
};

class MergeFactory{
public:
    static std::shared_ptr<Merge> make_merge(MergeMethod);
};

class Maximum : public Merge{
public:
    void execute(std::vector<cv::Mat>&,cv::Mat&,cv::Mat&);
};




#endif // MERGE_H
