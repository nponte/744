#ifndef VIDEOREADER_H_
#define VIDEOREADER_H_

#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>

#include "/usr/local/Cellar/opencv/2.4.13.2/include/opencv2/highgui/highgui.hpp"

#include "../util/timer.hpp"
#include "../util/workqueue.h"
#include "../settings.hpp"

const int MAX_FRAMES_TO_DROP = 10;

class VideoReader {
  public:
    VideoReader(const std::string& filename);
    cv::Mat getFrame();
    bool showFrame();
    bool isFrameAvailable();
    int getNumFramesAvailable();

  private:
    void bufferFrames(const std::string& filename);

    cv::VideoCapture videoCapture;
    int framesCaptured;
    bool windowCreated;
    bool fullyBuffered;
    double avgFps;

    std::thread bufferThread;
    WorkQueue<cv::Mat> frameQueue;
    pthread_cond_t queueCond;
    pthread_mutex_t queueLock;
};

#endif
