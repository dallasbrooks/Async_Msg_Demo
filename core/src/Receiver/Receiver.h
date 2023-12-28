#ifndef RECEIVER_RECEIVER_H
#define RECEIVER_RECEIVER_H

#include <string>

#include "Common/ActorIntf.h"

namespace receiver
{

class Receiver : public common::ActorIntf
{
public:
    Receiver();
    ~Receiver();
    void Init() override;
    int HandleMessage() override;
    int Algorithm() override;

private:
    const std::string name_;
};

} // namepsace receiver

#endif