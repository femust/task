#ifndef FocusStacker_H
#define FocusStacker_H

#include<vector>

#include<iostream>
#include<string>

#include <opencv2/opencv.hpp>

#include "Filter.h"
#include "Merge.h"

class FocusStacker{
public:
    FocusStacker(std::shared_ptr<Filter>,std::shared_ptr<Merge>);
    ~FocusStacker();

    void addInputImage(cv::Mat image);
    void run();

protected:
    void run_filter(std::vector<cv::Mat>);
    void run_merger(std::vector<cv::Mat>);
    void save_image(cv::Mat,std::string);
    void debug(bool debug);

private:
    std::vector<cv::Mat> images_;
    std::vector<cv::Mat> images_filtered_;
    std::shared_ptr<Filter> filter_;
    std::shared_ptr<Merge> merger_;

    cv::Mat merged_image_;
    cv::Mat lookup_image_;
    cv::Mat depth_image_;

    bool debug_;
};

#endif // FocusStacker_H
