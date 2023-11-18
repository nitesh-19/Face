#include "iostream"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types.hpp>

using namespace cv;
using namespace std;
Point2f param[4] = {{0, 0},
                    {0, 0},
                    {0, 0},
                    {0, 0}};
int clicks = 0;

static void event(int event, int x, int y) {
    if (event == EVENT_LBUTTONUP and clicks < 4) {
        cout << "Mouse click" << endl;
        cout << x << " " << y << endl;
        param[clicks] = {float(x), float(y)};
        cout << param[clicks] << endl;
        clicks++;
    }
}


int main() {
    string path = "C:\\Users\\Nitesh\\Documents\\(B)CommonFiles\\Coding_Workspace\\Face\\grill.jpg";
    param[2] = {5, 2};
    Mat img = imread(path);
    cout << img.size << endl;
    cout << param[2] << endl;
    imshow("Image", img);
    setMouseCallback("Image", reinterpret_cast<MouseCallback>(event));
    cv::waitKey(0);
    cout << param[0] << endl;


}