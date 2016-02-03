#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace cv;
using namespace std;

const char * window_name = "Chaos game (c) Jay Bosamiya";
const int max_iterations = (int)1e5;
const int display_every = (int)1e2;

vector<Point> point_set;
int r100 = 50;

void display_fractal();
void display_points();

void delete_point() {
  if ( point_set.size() >= 1 ) {
    point_set.pop_back();
  }
  display_points();
}

void waiter(int delay = 0) {
  start_of_waiter:
  char c = waitKey(delay);
  switch (c) {
    case 'f':
      display_fractal();
      break;
    case 'q':
      exit(0);
      break;
    case 'x':
      delete_point();
      break;
    default:
      if (delay == 0) {
        goto start_of_waiter;
      }
      break;
  }
}

void create_fractal(Mat &img, Point p) {
  if ( point_set.size() < 1 ) {
    return;
  }

  RNG rng;
  double r = r100 / 100.0;

  for ( int i = 0 ; i < max_iterations ; i++ ) {
    Point towards = point_set[rng.uniform(0, point_set.size())];
    p = r*p + (1-r)*towards;

    img.at<Vec3b>(p)[0] = 255;
    img.at<Vec3b>(p)[1] = 255;
    img.at<Vec3b>(p)[2] = 255;

    if ( i % display_every == 0 ) {
      imshow(window_name, img);
      waiter(1);
    }
  }
}

void display_fractal() {
  Mat display_image(600, 600, CV_8UC3, Scalar(0,0,0));

  if ( point_set.size() < 1 ) {
    return;
  }

  Point centre(0,0);
  for ( vector<Point>::iterator it = point_set.begin() ; it != point_set.end() ; it++ ) {
    centre += *it;
  }
  centre = centre * (1.0/point_set.size());

  create_fractal(display_image, centre);

  waiter();
}

void display_points() {
  Mat display_image(600, 600, CV_8UC3, Scalar(0,0,0));

  for ( vector<Point>::iterator it = point_set.begin() ; it != point_set.end() ; it++ ) {
    circle(display_image, *it, 5, Scalar(255,255,255), -1, 8);
  }
  if ( point_set.size() >= 1 ) {
    circle(display_image, *(point_set.rbegin()), 5, Scalar(0,0,255), -1, 8);
  }

  imshow(window_name, display_image);
  waiter();
}

void on_mouse(int event, int x, int y, int, void*) {
  if( event != EVENT_LBUTTONDOWN )
    return;

  point_set.push_back(Point(x, y));

  display_points();
}

int main( int argc, char** argv ) {
  namedWindow(window_name, CV_WINDOW_AUTOSIZE);

  cout << "Usage:\n"
          "\tLeft Click: Add new point\n"
          "\tKeypress x: Delete latest point\n"
          "\tKeypress f: Run the chaos game\n"
          "\tKeypress q: Quit\n";

  setMouseCallback(window_name, on_mouse);
  createTrackbar("r*100: ", window_name, &r100, 100, NULL);
  display_points();

  return 0;
}
