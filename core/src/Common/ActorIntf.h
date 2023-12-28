#ifndef COMMON_ACTORINTF_H
#define COMMON_ACTORINTF_H

namespace common
{

class ActorIntf
{
public:
    ActorIntf() {}
    ~ActorIntf() {}
    virtual void Init() = 0;
    virtual int HandleMessage() = 0;
    virtual int Algorithm() = 0;
};

} // namespace common

#endif