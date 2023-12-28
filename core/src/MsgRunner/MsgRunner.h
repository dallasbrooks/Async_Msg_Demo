#ifndef MSGRUNNER_MSGRUNNER_H
#define MSGRUNNER_MSGRUNNER_H

#include <future>
#include <mutex>
#include <vector>

#include "Receiver/Receiver.h"
#include "Sender/Sender.h"

namespace msg_runner
{

class MsgRunner
{
public:
    MsgRunner();
    ~MsgRunner();
    int Run();

private:
    int WaitForFinish();
    void StartSender();
    void StartReceiver();

    std::mutex lock_;
    sender::Sender bob_;
    receiver::Receiver alice_;

    bool working_{true};
    std::vector<std::future<int>> futures_;
};

}// namepspace msg_runner

#endif