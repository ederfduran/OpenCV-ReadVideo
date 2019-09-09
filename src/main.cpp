#include <iostream>
#include <string>

// OpenCV includes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"


namespace cv_constants{
    const std::string keys={
    "{help h usage ? | | print this message}"
    "{@video | | Video file, if not defined try to use camera}"
    };
    const std::string window_name="video";
}


int main(int argc,const char** argv){
    cv::CommandLineParser parser(argc,argv,cv_constants::keys);
    parser.about("Read Video App v1.0.0");

    if(parser.has("help")){
        parser.printMessage();
        return 0;
    }
    
    // get path of video file 
    std::string video_file= parser.get<std::string>(0);

    // check if params are correctly parsed in his variables
    if(!parser.check()){
        parser.printErrors();
        return 0;
    }

    cv::VideoCapture cap; 
    if(!video_file.empty()){
        cap.open(video_file);// open video file
    } else{
        std::cout << "No video file found!";
        return -1;
    }
    if(!cap.isOpened()){
        return -1;
    }
    // create a window to show the frames
    cv::namedWindow(cv_constants::window_name); 
    for(;;){
        cv::Mat frame;
        cap>> frame;
        if(frame.empty()){
            return 0;
        }
        // show the frame in created window
        cv::imshow(cv_constants::window_name,frame);  
        // wait 30 milliseconds to check wheter any user want to stop application
        if(cv::waitKey(30)>=0){ 
            break;
        }
    }
    cap.release();
    return 0;
}