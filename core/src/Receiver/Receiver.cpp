#include "Receiver/Receiver.h"

#include <iostream>

#include "Constants.h"

#include "Common/MessageRouter/MessageRouter.h"
#include "Common/PayloadRepo/PayloadRepo.h"

namespace receiver
{

Receiver::Receiver()
    : name_{"Alice"}
{
    //
}

Receiver::~Receiver()
{
    //
}

void Receiver::Init()
{
    common::MessageRouter::Register(name_);
}

int Receiver::HandleMessage()
{
    int key = 0;
    int ret = common::MessageRouter::GetMsg(name_, key);
    if (OKAY != ret)
    {
        return ret;
    }
    std::string msg;
    bool success = common::PayloadRepo::GetItem(key, msg);
    if (!success)
    {
        std::cout << "Repo clone failed" << std::endl;
        return FAIL;
    }
    std::cout << name_ << " saw: '" << msg << "'" << std::endl;
    return OKAY;
}

int Receiver::Algorithm()
{
    return OKAY;
}

} // namespace receiver