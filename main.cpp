#pragma ide diagnostic ignored "EndlessLoop"

#include "iostream"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
//#include <opencv2/core/utility.hpp>
using namespace cv;
using namespace std;

void event(int event, int x, int y) {
    if (event == EVENT_LBUTTONUP) {
        cout << "Mouse click" << endl;
        cout << x << " " << y << endl;

    }
}

int main() {

    string path = "C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face\\man.jpg";
    //VideoCapture cap(0);
    Mat img = imread(path);
    //Mat img;
    Mat img_gray;
    Mat img_blur;
    Mat img_canny;

    Mat resized_img;

    Mat cropped_img;


    cout << img.size << endl;
    //     cap.read(img);
    cvtColor(img, img_gray, COLOR_BGR2GRAY);
    GaussianBlur(img, img_blur, Size(7, 7), 2, 0);
    Canny(img_blur, img_canny, 50, 150);
    Rect roi(100, 100, 150, 150);
//    cropped_img = img_gray(roi);
    circle(img, Point(100, 100), 155, Scalar(0, 69, 255));
    imshow("Image", img);

    setMouseCallback("Image", reinterpret_cast<MouseCallback>(event));
    cv::waitKey(0);
    imshow("Image", img_canny);
    cv::waitKey(0);


}