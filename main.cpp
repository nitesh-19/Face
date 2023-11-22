#include "iostream"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types.hpp>
#include <windows.h>

using namespace cv;
using namespace std;
Point2f captured_coordinates[4] = {{0, 0},
                                   {0, 0},
                                   {0, 0},
                                   {0, 0}};
int clicks = 0;
Mat img;
Mat result_image;
int flag = 0;

float get_distance(Point2f (&p1), Point2f (&p2)) {
    float x = p2.x - p1.x;
    float y = p2.y - p1.y;
    return sqrt(x * x + y * y);
}

static void event(int event, int x, int y) {
    if (event == EVENT_LBUTTONUP and clicks < 4) {
        cout << "Mouse click" << endl;
        cout << x << " " << y << endl;
        captured_coordinates[clicks] = {float(x), float(y)};
        cout << captured_coordinates[clicks] << endl;
        clicks++;
    } else if (clicks > 3) {
        destroyAllWindows();

        flag = 1;
    }
}

void trackbar_slider(int state) {
    if (state == 0) {
        // Handle division by zero, or set a minimum value for state
        cout << "state 0";
    }
    double scaleFactor = state / 250;
    Mat scaled_image;
    resize(img, result_image, Size(), scaleFactor, scaleFactor, INTER_LINEAR);
    imshow("Result", result_image);
    waitKey(2);

}


int main() {
    int screen_width = (int) GetSystemMetrics(SM_CXSCREEN);
    int screen_height = (int) GetSystemMetrics(SM_CYSCREEN);

    string path = R"(C:\Users\Nitesh\Documents\(B)CommonFiles\Coding_Workspace\Face\grill.jpg)";
    img = imread(path);
    Mat matrix;
    namedWindow("Image");

    float h = img.size[0];
    float w = img.size[1];
    int a = 100;


//    while (flag != 1) {
    imshow("Image", img);

    setMouseCallback("Image", reinterpret_cast<MouseCallback>(event));
    cv::waitKey(0);
//    }
    destroyAllWindows();


//    if (flag == 1) {
    float avg_width = (get_distance((captured_coordinates)[0], (captured_coordinates)[1]) +
                       get_distance((captured_coordinates)[2], (captured_coordinates)[3])) / 2;
    float avg_height = (get_distance((captured_coordinates)[0], (captured_coordinates)[2]) +
                        get_distance((captured_coordinates)[1], (captured_coordinates)[3])) / 2;

    Point2f destination[4] = {{0,         0},
                              {avg_width, 0},
                              {0,         avg_height},
                              {avg_width, avg_height}};
    namedWindow("Result");
    matrix = getPerspectiveTransform(captured_coordinates, destination);
    warpPerspective(img, result_image, matrix, Point(avg_width, avg_height));
    imshow("Result", result_image);
    createTrackbar("ScaleX", "Result", &a, 500, reinterpret_cast<TrackbarCallback>(trackbar_slider));
//    img = result_image;
//    imshow("Result", result_image);

//    createTrackbar("Scale Y", "Image", p, 100, reinterpret_cast<TrackbarCallback>(trackbar_slider));
//    }
    waitKey(10);


    return 0;

}