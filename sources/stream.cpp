#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"

#include "stream.h"

Stream::Stream(int device)
{
  this->capture.open(device);
}

Stream::Stream(std::string const &fileName)
{
  this->capture.open(fileName);
}

Stream::~Stream()
{
  if (this->capture.isOpened())
  {
    this->capture.release();
  }
}

bool Stream::isOpen() const
{
  return this->capture.isOpened();
}

void Stream::run(Detector &detector, Renderer const &renderer)
{
  cv::Mat frame;
  std::vector<cv::Rect> faces;
  while (this->capture.read(frame))
  {
    faces.clear();
    // We don't have any flux anymore, so we can close the stream.
    if (frame.empty())
      return;
    detector.localise(frame, faces);
    renderer.render(frame, faces);
    cv::imshow("FacialDetection", frame);
    if (cv::waitKey(60) >= 0)
      return;
  }
}
