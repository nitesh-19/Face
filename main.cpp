#pragma ide diagnostic ignored "EndlessLoop"

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/core/utility.hpp>
using namespace cv;
using namespace std;

int main() {

//    string path = "C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face-Recognition-Cpp\\man.jpg";
    VideoCapture cap(0);
//    Mat img = imread(path);
    Mat img;
    Mat img_gray;
    Mat img_blur;
    while (true) {
        cap.read(img);
        cvtColor(img, img_gray, COLOR_BGR2GRAY);
        GaussianBlur(img, img_blur, Size(7, 7), 5, 0);
        imshow("Image", img_blur);
        cv::waitKey(1);
        //fewacf

    }


}