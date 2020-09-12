#include "Worker.h"

void Worker::joinThread() {
    if (m_thread) {
        m_thread->join();
        delete m_thread;
        m_thread = nullptr;
    }
}

Worker::~Worker() {
    joinThread();
}
