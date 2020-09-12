#pragma once
#include <utility>
#include <thread>

class Worker {
 public:
    Worker() = default;
    ~Worker();

    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;
    Worker& operator=(const Worker&) = delete;

    template <typename Function, class... Args>
    void startWorker(Function&& func, Args&&... args);

    void joinThread();

 private:
    std::thread* m_thread{nullptr};
};

template<typename Function, class... Args>
void Worker::startWorker(Function &&func, Args &&... args) {
    joinThread();
    m_thread = new std::thread(func, std::forward<Args>(args)...);
}
