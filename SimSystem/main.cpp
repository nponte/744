#include <cstdlib>
#include <iostream>

//#include "buildtest/buildtest.hpp"
//#include "oculus2/oculus2.hpp"
//#include "optimizer/optimizer.hpp"
//#include "renderer/renderer.hpp"
//#include "rendertest/rendertest.hpp"
//#include "util/cylinderwarp.hpp"
//#include "util/imageutil.hpp"
//#include "util/timer.hpp"
#include "videoreader.hpp"

static int playVideo(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: "
      << argv[0]
      << " playvideo filename"
      << std::endl;
    return 1;
  }
  std::string filename = argv[2];
  VideoReader videoReader(filename);
  while (videoReader.showFrame()) {
    cv::waitKey(1);
  }
  return 0;
}

int main(int argc, char* argv[]) {
//  if (argc < 2) {
//    usage();
//  }

  playVideo(argc, argv);
  /*
  if (runMode == "buildtest") {
    return BuildTest::runBuildTest();
  } else if (runMode == "playvideo") {
    return playVideo(argc, argv);
  } else if (runMode == "cylinderwarp") {
    return cylinderWarp(argc, argv);
  } else if (runMode == "render") {
    return renderStereo(argc, argv);
  } else if (runMode == "rendertest") {
    return renderTest(argc, argv);
  } else if (runMode == "oculus2") {
    return oculus2(argc, argv);
  } else if (runMode == "optimize") {
    return optimize(argc, argv);
  } else {
    usage();
  }
  */

  return 0;
}
