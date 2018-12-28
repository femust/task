#include "Merge.h"

std::shared_ptr<Merge> MergeFactory::make_merge(MergeMethod method){
    if (method==MergeMethod::Maximum){
        std::cout << "Maximum method chose"<<std::endl;
        return std::make_shared<Maximum>();
    }else{
        std::cout << "Wrong method" << std::endl;
        //throw error
    }
}

cv::Mat Maximum::execute(std::vector<cv::Mat> images_){
    int rows=images_[0].rows;
    int columns=images_[0].cols;
    int distance=0;
    int max=0;
    for (auto it=images_.begin();it<images_.end();it++)
    {
        std::cout << "Matrix: " << std::endl;
        std::cout << *it << std::endl;
    }
    cv::Mat merged_lookup = cv::Mat::zeros(rows, columns, CV_32S);
    cv::Mat merged = cv::Mat::zeros(rows, columns, CV_32S);
    std::cout << merged << std::endl;

    for (auto i=0; i<rows; i++){
        for (auto j=0; j<columns; j++){
            max=0;
            for (auto it=images_.begin();it<images_.end();it++){
                distance=std::distance(images_.begin(),it);
                std::cout <<max << " < " << int(it->at<int>(i,j))<< "result: " << (max < it->at<int>(i,j)) << " distance: " << distance << std::endl;
                if (max < it->at<int>(i,j)){
                    max = it->at<int>(i,j);
                    merged_lookup.at<int>(i,j)=distance;
                }
            }
            merged.at<int>(i,j)=images_[merged_lookup.at<int>(i,j)].at<int>(i,j);
        }
    }
    std::cout << "Result: " << std::endl;
    std::cout << merged_lookup << std::endl;
    std::cout << merged << std::endl;
    return merged;
}

