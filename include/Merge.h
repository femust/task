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

// A fabric to create ways for image mergining.
class MergeFactory{
public:
    static std::shared_ptr<Merge> make_merge(MergeMethod);
};

/*
Maximum method choses the heighest value for each pixel for gathered images.
 */
class Maximum : public Merge{
public:
    void execute(std::vector<cv::Mat>&,cv::Mat&,cv::Mat&);
};




#endif // MERGE_H
