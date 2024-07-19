#pragma once
#include <mutex>
#include <condition_variable>

class SharedBuffer : private std::mutex, private std::condition_variable
{
    bool newDataAvailable;
    std::string buffer;

public:
    SharedBuffer() : newDataAvailable(false) {}

    /**
     * Writing values to the buffer with notification of another thread
     * @param [in] toBuffer - input buffer
     */
    void writeAndNotify(std::string toBuffer)
    {
        std::unique_lock<std::mutex> lock(*this);
        buffer = std::move(toBuffer);
        newDataAvailable = true;
        lock.unlock();
        notify_all();
    }

    /**
     * Reading from the data buffer and then clearing the buffer
     * @return buffer values
     */
    std::string readOnNotified()
    {
        std::unique_lock<std::mutex> lock(*this);
        wait(lock, [this]{ return newDataAvailable; });
        std::string bufferData = std::move(buffer);
        buffer.clear();
        newDataAvailable = false;
        lock.unlock();
        return bufferData;
    }
};
