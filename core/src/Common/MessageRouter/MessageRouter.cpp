#include "Common/MessageRouter/MessageRouter.h"

#include <iostream>

#include "Constants.h"

namespace common
{


std::map<std::string, std::queue<int>> MessageRouter::mailBox_;

MessageRouter::MessageRouter()
{
    //
}

MessageRouter::~MessageRouter()
{
    //
}

int MessageRouter::Register(const std::string &name)
{
    if (mailBox_.find(name) != mailBox_.end())
    {
        std::cout << name << " already registered" << std::endl;
        return FAIL;
    }
    mailBox_.insert({name, std::queue<int>()});
    return OKAY;
}

int MessageRouter::Publish(const std::string& to, int msg)
{
    auto it = mailBox_.find(to);
    if (mailBox_.end() == it)
    {
        std::cout << to << " does not exist" << std::endl;
        return FAIL;
    }
    it->second.push(msg);
    return OKAY;
}

int MessageRouter::GetMsg(const std::string& to, int& msg)
{
    auto it = mailBox_.find(to);
    if (mailBox_.end() == it)
    {
        std::cout << to << " does not exist" << std::endl;
        return FAIL;
    }
    if (!it->second.empty())
    {
        msg = it->second.front();
        it->second.pop();
        return OKAY;
    }
    return FAIL;
}

} // namespace common