#ifndef SENDER_SENDER_H
#define SENDER_SENDER_H

#include <string>

#include "Common/ActorIntf.h"

namespace sender
{

class Sender : public common::ActorIntf
{
public:
    Sender();
    ~Sender();
    void Init() override;
    int HandleMessage() override;
    int Algorithm() override;
    
private:
    const std::string name_;
};

} // namespace sender

#endif