#include "FocusStacking.h"

FocusStacking::FocusStacking(std::shared_ptr<Filter> filter,std::shared_ptr<Merge> merger):filter_(filter),merger_(merger){
}
FocusStacking::~FocusStacking(){}
void FocusStacking::addInputImage(cv::Mat image){
    images_.emplace_back(image);
    if(debug_){
        std::cout << "Added image: " << images_.size() << std::endl;
    }
}
void FocusStacking::run_filter(){
    cv::Mat kernel=filter_->get_kernel();
    for (auto it=images_.begin();it<images_.end();it++){
        images_filtered_.push_back(filter_->execute(*it,kernel));
    }
    std::cout << "images_filtered: " <<images_filtered_.size() << std::endl;
}
void FocusStacking::run_merger(){
    merged_image_= merger_->execute(images_);
}

void FocusStacking::run(){
    run_filter();
    run_merger();
}
void FocusStacking::debug(bool debug=false){
    std::cout << "There are " << images_.size() << " images." << std::endl;
}
