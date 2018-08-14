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

void Stream::run(Detector &catDetector, Detector &humanDetector, Detector &otherDetector, Renderer const &renderer)
{
  God _cats[] = {
    God("Seth", cv::Scalar(187,221,255)),
    God("Sekhmet", cv::Scalar(187,221,255)),
    God("Anubis", cv::Scalar(255,204,204)),
    God("Bastet", cv::Scalar(221,187,255)),
  };
  God _humans[] = {
    God("Ma'at", cv::Scalar(221,221,221)),
    God("Nut", cv::Scalar(238,238,187)),
    God("Aten", cv::Scalar(238,238,187)),
    God("Hatmehyt", cv::Scalar(238,238,187)),
  };
  God _others[] = {
    God("Atum", cv::Scalar(221,187,255)),
    God("Neith", cv::Scalar(221,187,255)),
    God("Khonsou", cv::Scalar(221,187,255)),
    God("Bes", cv::Scalar(221,187,255)),
  };
  std::vector<God> cats(_cats, _cats + sizeof(_cats) / sizeof(_cats[0]));
  std::vector<God> humans(_humans, _humans + sizeof(_humans) / sizeof(_humans[0]));
  std::vector<God> others(_others, _others + sizeof(_others) / sizeof(_others[0]));

  cv::Mat frame;
  std::vector<cv::Rect> catFaces;
  std::vector<cv::Rect> humanFaces;
  std::vector<cv::Rect> otherFaces;
  while (this->capture.read(frame))
  {
    catFaces.clear();
    humanFaces.clear();
    otherFaces.clear();
    // We don't have any flux anymore, so we can close the stream.
    if (frame.empty())
      return;
    // detect and render cats
    catDetector.localise(frame, catFaces);
    humanDetector.localise(frame, humanFaces);
    otherDetector.localise(frame, otherFaces);
    renderer.render(frame, catFaces, cats);
    renderer.render(frame, humanFaces, humans);
    renderer.render(frame, otherFaces, others);
    cv::imshow("FacialDetection", frame);
    if (cv::waitKey(60) >= 0)
      return;
  }
}
