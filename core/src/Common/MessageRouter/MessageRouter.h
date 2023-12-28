#ifndef COMMON_MESSAGEROUTER_MESSAGEROUTER_H
#define COMMON_MESSAGEROUTER_MESSAGEROUTER_H

#include <map>
#include <queue>
#include <string>

namespace common
{

class MessageRouter
{
public:
    MessageRouter();
    ~MessageRouter();
    static int Register(const std::string& name);
    static int Publish(const std::string& to, int msg);
    static int GetMsg(const std::string& to, int& msg);

private:
    static std::map<std::string, std::queue<int>> mailBox_;
};

} // namespace common

#endif