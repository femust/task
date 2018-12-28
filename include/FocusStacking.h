#ifndef FOCUSSTACKING_H
#define FOCUSSTACKING_H

#include<vector>

#include<iostream>

#include <opencv2/opencv.hpp>

#include "Filter.h"


class FocusStacking{
public:
    FocusStacking(std::shared_ptr<Filter>);
    ~FocusStacking();

    void addInputImage(cv::Mat image);


    void run();
    void run_filter();
    void debug(bool debug);



private:

    std::vector<cv::Mat> images_;
    std::vector<cv::Mat> images_filtered_;
    std::shared_ptr<Filter> filter_;

    bool debug_;







};

#endif // FOCUSSTACKING_H
