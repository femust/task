#include "FocusStacker.h"

FocusStacker::FocusStacker(std::shared_ptr<Filter> filter,std::shared_ptr<Merge> merger):filter_(filter),merger_(merger){
}
FocusStacker::~FocusStacker(){}
void FocusStacker::addInputImage(cv::Mat image){
    images_.emplace_back(image);
    if(debug_){
        std::cout << "Added image: " << images_.size() << std::endl;
    }
}
void FocusStacker::run_filter(std::vector<cv::Mat> images){
    cv::Mat kernel=filter_->get_kernel();
    if (images[0].channels()==1){
        for (auto it=images.begin();it<images.end();it++){
        images_filtered_.push_back(filter_->execute(*it,kernel));
        }
    } else if (images[0].channels()==3){
       std::vector<cv::Mat> channels(3);
       std::vector<cv::Mat> channels_filtered(3);
       cv::Mat image_filtered;
       for (auto it=images.begin();it<images.end();it++){
           cv::split(*it,channels);
           channels_filtered[0]=filter_->execute(channels[0],kernel);
           channels_filtered[1]=filter_->execute(channels[1],kernel);
           channels_filtered[2]=filter_->execute(channels[2],kernel);
           cv::merge(channels_filtered,image_filtered);
           images_filtered_.push_back(image_filtered);
        }
    }
}

void FocusStacker::run_merger(std::vector<cv::Mat> images){
    if (images[0].channels()==1){
        merged_image_=cv::Mat::zeros(images[0].rows,images[0].cols, CV_8UC1);
        merger_->execute(images,lookup_image_,merged_image_);
    } else if (images[0].channels()==3){
        merged_image_=cv::Mat::zeros(images[0].rows,images[0].cols, CV_8UC3);
        std::vector<cv::Mat> rVectorchannel;
        std::vector<cv::Mat> bVectorchannel;
        std::vector<cv::Mat> gVectorchannel;
        std::vector<cv::Mat> channels_filtered(3);
        for (auto it=images.begin();it<images.end();it++){
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

void FocusStacker::save_image(cv::Mat image,std::string file_name)
{
    imwrite( file_name, image );
}

void FocusStacker::run(){
    run_filter(images_);
    run_merger(images_);
    save_image(merged_image_,"result.png");
    cv::Mat depth=cv::Mat::zeros(lookup_image_.rows,lookup_image_.cols, CV_8UC1);
    int coefficient=255/images_.size();
    for (int i=0;i<lookup_image_.rows;i++)
    {
        for (int j=0;j<lookup_image_.cols;j++)
        {
            depth.at<uchar>(i,j)=uchar(255-lookup_image_.at<int>(i,j)*coefficient);
        }
    }
    save_image(depth,"depth.png");

}
void FocusStacker::debug(bool debug=false){}
