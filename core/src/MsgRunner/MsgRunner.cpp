#include "MsgRunner/MsgRunner.h"

#include <iostream>
#include <thread>

#include "Constants.h"

namespace msg_runner
{

MsgRunner::MsgRunner()
{
    bob_.Init();
    alice_.Init();
}

MsgRunner::~MsgRunner()
{
    //
}

int MsgRunner::Run()
{
    StartSender();
    StartReceiver();
    return WaitForFinish();
}

int MsgRunner::WaitForFinish()
{
    std::this_thread::sleep_for(std::chrono::seconds(10));
    working_ = false;
    for (auto& f : futures_)
    {
        f.get();
    }
    return OKAY;
}

void MsgRunner::StartSender()
{
    auto f = std::async(std::launch::async, [this]()
    {
        std::cout << std::this_thread::get_id() << std::endl;
        while(working_)
        {
            bob_.HandleMessage();
            bob_.Algorithm();
            std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        return OKAY;
    });
    futures_.push_back(std::move(f));
}

void MsgRunner::StartReceiver()
{
    auto f = std::async(std::launch::async, [this]()
    {
        std::cout << std::this_thread::get_id() << std::endl;
        while(working_)
        {
            alice_.HandleMessage();
            alice_.Algorithm();
            std::this_thread::yield();
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }
        return OKAY;
    });
    futures_.push_back(std::move(f));
}

} // namespace msg_runner