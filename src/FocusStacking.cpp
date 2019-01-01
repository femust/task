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
    if (images_[0].channels()==1){

        for (auto it=images_.begin();it<images_.end();it++){
        images_filtered_.push_back(filter_->execute(*it,kernel));
        }
    } else if (images_[0].channels()==3){

       std::vector<cv::Mat> channels(3);
       std::vector<cv::Mat> channels_filtered(3);
       cv::Mat image_filtered;
       for (auto it=images_.begin();it<images_.end();it++){
           cv::split(*it,channels);
           channels_filtered[0]=filter_->execute(channels[0],kernel);
           channels_filtered[1]=filter_->execute(channels[1],kernel);
           channels_filtered[2]=filter_->execute(channels[2],kernel);
           cv::merge(channels_filtered,image_filtered);
           images_filtered_.push_back(image_filtered);
        }
    }
}

void FocusStacking::run_merger(){
    if (images_[0].channels()==1){
        merged_image_=cv::Mat::zeros(images_[0].rows,images_[0].cols, CV_8UC1);
        merger_->execute(images_,merged_image_,lookup_image_);
    } else if (images_[0].channels()==3){
        merged_image_=cv::Mat::zeros(images_[0].rows,images_[0].cols, CV_8UC3);
        std::vector<cv::Mat> rVectorchannel;
        std::vector<cv::Mat> bVectorchannel;
        std::vector<cv::Mat> gVectorchannel;
        std::vector<cv::Mat> channels_filtered(3);
        for (auto it=images_.begin();it<images_.end();it++){
            cv::Mat channels[3];
            cv::split(*it,channels);
            rVectorchannel.push_back(channels[0]);
            gVectorchannel.push_back(channels[1]);
            bVectorchannel.push_back(channels[2]);
        }
        merger_->execute(rVectorchannel,lookup_image_,channels_filtered[0]);
        merger_->execute(gVectorchannel,lookup_image_,channels_filtered[1]);
        merger_->execute(bVectorchannel,lookup_image_,channels_filtered[2]);
        cv::merge(channels_filtered,merged_image_);
    }
}

void FocusStacking::run(){
    run_filter();
    run_merger();

    cv::namedWindow( "Final window",cv::WINDOW_AUTOSIZE );// Create a window for display.
   // std::cout << merged_image_ << std::endl;
   // std::cout <<merged_image_<< std::endl;
    cv::imshow( "Final window", merged_image_ );                   // Show our image inside it.
    cv::waitKey(0);
}
void FocusStacking::debug(bool debug=false){
    std::cout << "There are " << images_.size() << " images." << std::endl;
}
