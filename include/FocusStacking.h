#ifndef FOCUSSTACKING_H
#define FOCUSSTACKING_H

#include<vector>

#include<iostream>

#include <opencv2/opencv.hpp>

#include "Filter.h"


class FocusStacking
{
public:
    FocusStacking();
    ~FocusStacking();

    enum class EdgeDetectionMethod
    {
        Laplace4,
        Laplace8,
    };

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
    Filter *filter_=nullptr;

    bool debug_;







};

#endif // FOCUSSTACKING_H
