#pragma once

#include <thread>
#include <vector>
#include <iostream>

class Worker {
 public:
    Worker() = default;
    ~Worker();

    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;
    Worker& operator=(const Worker&) = delete;

    template <typename Function, class... Args>
    void startNewThread(Function&& func, Args&&... args);

    void joinAllThreads();

 private:
    std::vector<std::thread> m_workerThreads;
};

template<typename Function, class... Args>
void Worker::startNewThread(Function &&func, Args &&... args) {
    m_workerThreads.push_back(std::thread(func, std::forward<Args>(args)...));
}
