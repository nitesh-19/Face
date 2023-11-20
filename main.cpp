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
        return;
    }

}

void button(int state) {
    cout << state << endl;
}


int main() {

    int screen_width = (int) GetSystemMetrics(SM_CXSCREEN);
    int screen_height = (int) GetSystemMetrics(SM_CYSCREEN);
    string path = "C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face\\grill.jpg";
    Mat img = imread(path);
    Mat matrix, result_image;
    float h = img.size[0];
    float w = img.size[1];
    cout << img.size << endl;
    int a;
    int *p = &a;
    *p = 500;
    cout << "Click on the four corners of the image that you want to transform." << endl;
    resize(img, img, Size(), 0.8, 0.8, INTER_LINEAR);
    imshow("Image", img);
    createTrackbar("faw", "Image", p, 500, reinterpret_cast<TrackbarCallback>(button));
    setMouseCallback("Image", reinterpret_cast<MouseCallback>(event));
    cv::waitKey(0);
//    namedWindow("Frame");
//    createButton("but", reinterpret_cast<ButtonCallback>(button), nullptr, QT_PUSH_BUTTON, false);

    float avg_width = (get_distance((captured_coordinates)[0], (captured_coordinates)[1]) +
                       get_distance((captured_coordinates)[2], (captured_coordinates)[3])) / 2;
    float avg_height = (get_distance((captured_coordinates)[0], (captured_coordinates)[2]) +
                        get_distance((captured_coordinates)[1], (captured_coordinates)[3])) / 2;

    Point2f destination[4] = {{0,         0},
                              {avg_width, 0},
                              {0,         avg_height},
                              {avg_width, avg_height}};
    matrix = getPerspectiveTransform(captured_coordinates, destination);
    warpPerspective(img, result_image, matrix, Point(avg_width, avg_height));
    imshow("Result", result_image);
    waitKey(0);

}