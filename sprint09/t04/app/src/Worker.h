#pragma once

#include <thread>
#include <future>

class Worker {
 public:
    Worker() = default;
    ~Worker() = default;

    Worker(const Worker &) = delete;
    Worker(const Worker &&) = delete;
    Worker& operator=(const Worker&) = delete;

    template <typename Function, class... Args>
    auto startAsync(Function&& func, Args&&... args) {
        return std::async(std::launch::async, func, std::forward<Args>(args)...);
    }
};
