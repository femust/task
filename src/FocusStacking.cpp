#include "FocusStacking.h"

FocusStacking::FocusStacking()
{
    if (debug_)
    {
        std::cout << "Constructor executed" << std::endl;
    }
}

FocusStacking::~FocusStacking()
{
    if (filter_!=nullptr)
    {
        delete filter_;
    }

}

void FocusStacking::addInputImage(cv::Mat image)
{
    images_.emplace_back(image);
    if(debug_)
    {
        std::cout << "Added image: " << images_.size() << std::endl;
    }
}

void FocusStacking::setEdgeDetectionMethod(EdgeDetectionMethod method)
{
    if (filter_!=nullptr)
    {
        delete filter_;
    }

    if (method == EdgeDetectionMethod::Laplace4)
    {
         std::cout << "Laplace4" << std::endl;
         //filter_ = new Laplace4();
    }
     else if (method == EdgeDetectionMethod::Laplace8)
    {
       filter_= new Laplace8();
    }
    else {
        std::cout << "Wrong method" << std::endl;
    }

    if(debug_)
    {
        if (method==EdgeDetectionMethod::Laplace4)
        {
            std::cout << "Laplace4" << std::endl;
        }
        else if (method==EdgeDetectionMethod::Laplace8)
        {
            std::cout << "Laplace8" << std::endl;
        }
    }



}

void FocusStacking::run()
{
cv::Mat proba = cv::Mat::ones(10, 10, CV_32F);
std::cout << "Setting an image" << std::endl;
filter_->set_image(proba);
std::cout << "displaying an image" << std::endl;
filter_->display();
filter_->execute();





}



void FocusStacking::debug(bool debug=false)
{
    if(debug)
    {
        std::cout << "Debug mode on" <<std::endl;
    }
  debug_=debug;

}
