#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void run_filter(Mat input_image, Mat &output_image) {
  // TODO: Rewrite this as necessary for the filter
  // Currently all it does is just output same image
  output_image = input_image;
}

void show_help(const char *progname) {
    cerr <<"Usage: " << progname << " input_image output_image" << endl;
}

int main( int argc, char** argv ) {
  if( argc < 3 ) {
    show_help(argv[0]);
    return -1;
  }

  Mat input_image, output_image;

  input_image = imread(argv[1], CV_LOAD_IMAGE_COLOR);
  if ( ! input_image.data ) {
      show_help(argv[0]);
      cerr <<  "ERROR: Could not open or find the image " << argv[1] << endl;
      return -1;
  }

  run_filter(input_image, output_image);

  imwrite(argv[2],output_image);

  return 0;
}
