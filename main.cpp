#include "iostream"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types.hpp>
#include <windows.h>

using namespace cv;
using namespace std;
Point2f param[4] = {{0, 0},
                    {0, 0},
                    {0, 0},
                    {0, 0}};
int clicks = 0;

float get_distance(float (&p1)[2], float (&p2)[2]) {
    float x = p2[0] - p1[0];
    float y = p2[1] - p1[1];
    return sqrt(x * x + y * y);
}

static void event(int event, int x, int y) {
    if (event == EVENT_LBUTTONUP and clicks < 4) {
        cout << "Mouse click" << endl;
        cout << x << " " << y << endl;
        param[clicks] = {float(x), float(y)};
        cout << param[clicks] << endl;
        clicks++;
    } else if (clicks > 3) {
        return;
    }

}


int main() {
    int screen_width = (int) GetSystemMetrics(SM_CXSCREEN);
    int screen_height = (int) GetSystemMetrics(SM_CYSCREEN);
    string path = "C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face\\test.jpg";
    param[2] = {5, 2};
    Mat img = imread(path);
    Mat matrix, result_image;
    float h = img.size[0];
    float w = img.size[1];
    cout << img.size << endl;
    cout << param[2] << endl;
    cout << "Click on the four corners of the image that you want to transform." << endl;

    resize(img, img, Size(), 0.1, 0.1, INTER_LINEAR);
    imshow("Image", img);
    setMouseCallback("Image", reinterpret_cast<MouseCallback>(event));
    cv::waitKey(0);
//    for (int k = 0; k < 4; k++){
//        cout<<param[]
//    }


    Point2f destination[4] = {{0, 0},
                              {1, 0},
                              {0, 1},
                              {1, 1}};
    matrix = getPerspectiveTransform(param, destination);
    warpPerspective(img, result_image, matrix, Point(w, h));
    imshow("Result", result_image);
    waitKey(0);

}