#include <iostream>

#include "stream.h"
#include "detector.h"
#include "renderer.h"

cv::CommandLineParser usage(int argc, char **argv)
{
  cv::CommandLineParser parser(argc, argv,
    "{help h  |   |                               }"
    "{stream  |   | Path to the video file.       }"
    "{device  |0  | Device Number for the camera. }"
  );
  parser.about( "\nThis program is meant to do some very approximative facial detection\n" );
  // parser.printMessage();
  return parser;
}

int main(int argc, char **argv)
{
  cv::CommandLineParser parser = usage(argc, argv);
  cv::String fileStream = parser.get<cv::String>("stream");
  int cameraStream = parser.get<int>("device");
  if (parser.has("help"))
  {
    parser.printMessage();
    return 0;
  }

  Stream stream(cameraStream);
  if (!fileStream.empty()) {
    stream = Stream(fileStream);
  }

  Detector humanDetector("lbpcascade_frontalface.xml");
  Detector catDetector("lbpcascade_frontalcatface.xml");
  Detector otherDetector("lbpcascade_profileface.xml");
  Renderer renderer;

  if (!humanDetector.isLoaded() || !catDetector.isLoaded() || !otherDetector.isLoaded()) {
    std::cerr << "Couldn't find the configuration file." << std::endl;
    return -1;
  }
  if (!stream.isOpen()) {
    std::cerr << "Couldn't find the device." << std::endl;
    return -1;
  }

  srand(time(NULL));
  stream.run(catDetector, humanDetector, otherDetector, renderer);
  return 0;
}