#include "FocusStacking.h"

FocusStacking::FocusStacking(std::shared_ptr<Filter> filter):filter_(filter){
}
FocusStacking::~FocusStacking(){}
void FocusStacking::addInputImage(cv::Mat image){
    images_.emplace_back(image);
    if(debug_){
        std::cout << "Added image: " << images_.size() << std::endl;
    }
}
void FocusStacking::run_filter(){
    for (auto it=images_.begin();it<images_.end();it++){
        images_filtered_.push_back(filter_->execute(*it));
    }
}
void FocusStacking::run(){}
void FocusStacking::debug(bool debug=false){
    std::cout << "There are " << images_.size() << " images." << std::endl;
}
