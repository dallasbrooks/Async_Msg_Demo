#include "Sender/Sender.h"

#include <iostream>

#include "Constants.h"

#include "Common/MessageRouter/MessageRouter.h"
#include "Common/PayloadRepo/PayloadRepo.h"

namespace sender
{

Sender::Sender()
    : name_{"Bob"}
{
    //
}

Sender::~Sender()
{
    //
}

void Sender::Init()
{
    common::MessageRouter::Register(name_);
}

int Sender::HandleMessage()
{
    return OKAY;
}

int Sender::Algorithm()
{
    static const std::string msg{"Bob says hello"};
    const auto key = common::PayloadRepo::InsertItem(msg);
    const std::string target{"Alice"};
    common::MessageRouter::Publish(target, key);
    return OKAY;
}

} // namespace sender