#include "Worker.h"
#include "MultithreadedFileHandler.h"

void MultithreadedFileHandler::processFile() {
    std::unique_lock<std::mutex> lck(m_mutex);
    m_condVar.wait(lck, [&](){return m_fileLoaded;});
    std::cout << m_file << std::endl;
    m_fileLoaded = false;
}

void MultithreadedFileHandler::loadFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::istreambuf_iterator<char> eos;
    m_file = std::string(std::istreambuf_iterator<char>(file), eos);
    m_fileLoaded = true;
    m_condVar.notify_all();
}