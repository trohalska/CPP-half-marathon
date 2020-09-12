#include "Worker.h"

void Worker::joinAllThreads() {
    for (std::thread& x : m_workerThreads)
        if (x.joinable())
            x.join();
}

Worker::~Worker() {
    joinAllThreads();
}