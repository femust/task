#ifndef FOCUSSTACKING_H
#define FOCUSSTACKING_H

#include<vector>

#include<iostream>

#include <opencv2/opencv.hpp>

#include "Filter.h"
#include "Merge.h"

class FocusStacking{
public:
    FocusStacking(std::shared_ptr<Filter>,std::shared_ptr<Merge>);
    ~FocusStacking();

    void addInputImage(cv::Mat image);


    void run();
    void run_filter();
    void run_merger();

    void debug(bool debug);



private:

    std::vector<cv::Mat> images_;
    std::vector<cv::Mat> images_filtered_;
    std::shared_ptr<Filter> filter_;
    std::shared_ptr<Merge> merger_;

    cv::Mat merged_image_;

    bool debug_;







};

#endif // FOCUSSTACKING_H
