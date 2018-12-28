#ifndef FOCUSSTACKING_H
#define FOCUSSTACKING_H

#include<vector>

#include<iostream>

#include <opencv2/opencv.hpp>

#include "Filter.h"


class FocusStacking
{
public:
    FocusStacking(std::shared_ptr<Filter>);
    ~FocusStacking();



    enum class MergeStrategy
            {
                    AlwaysMaximum,
    };


    void setManualEdgeThreshold(uint8_t threshold) { thresholdValue_ = threshold; useAutomaticThreshold_ = false; }
    void useAutomaticThreshold() { useAutomaticThreshold_ = true; }
    void setEdgeDetectionMethod(EdgeDetectionMethod method=EdgeDetectionMethod::Laplace4);
    void setMergeStrategy(MergeStrategy strategy) { mergeStrategy_ = strategy; }
    void setDepthThreshold(uint8_t threshold) { depthThresholdValue_ = threshold; }

    void addInputImage(cv::Mat image);

    void run();

    void debug(bool debug);



private:

    uint8_t                   thresholdValue_;
    uint8_t                   depthThresholdValue_;
    bool                      useAutomaticThreshold_;

    EdgeDetectionMethod edgeMethod_;
    MergeStrategy mergeStrategy_;
    std::vector<cv::Mat> images_;
    std::shared_ptr<Filter> filter_;

    bool debug_;







};

#endif // FOCUSSTACKING_H
