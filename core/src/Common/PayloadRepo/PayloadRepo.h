#ifndef COMMON_PAYLOADREPO_PAYLOADREPO_H
#define COMMON_PAYLOADREPO_PAYLOADREPO_H

#include <map>
#include <mutex>
#include <string>
#include <vector>

namespace common
{

class PayloadRepo
{
public:
    PayloadRepo();
    ~PayloadRepo();
    static int InsertItem(const std::string& p);
    static bool GetItem(const int k, std::string& p);

private:
    static int GetNextKey();
    static void RecylceKey(const int k);
    static std::mutex lock_;
    static std::map<int, std::string> dataStore_;
    static std::vector<int> recycledKeys_;
};

} // namespace common

#endif