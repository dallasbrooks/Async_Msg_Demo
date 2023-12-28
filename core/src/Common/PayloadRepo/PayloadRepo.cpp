#include "Common/PayloadRepo/PayloadRepo.h"

namespace common
{

std::mutex PayloadRepo::lock_;
std::map<int, std::string> PayloadRepo::dataStore_;
std::vector<int> PayloadRepo::recycledKeys_;

PayloadRepo::PayloadRepo()
{
    //
}

PayloadRepo::~PayloadRepo()
{
    //
}

int PayloadRepo::InsertItem(const std::string& p)
{
    std::lock_guard<std::mutex> lock{lock_};
    const int k = GetNextKey();
    dataStore_[k] = p;
    return k;
}

bool PayloadRepo::GetItem(const int k, std::string& p)
{
    std::lock_guard<std::mutex> lock{lock_};
    const auto it = dataStore_.find(k);
    if (dataStore_.end() == it)
    {
        return false;
    }
    p = it->second;
    dataStore_.erase(it);
    RecylceKey(k);
    return true;
}

int PayloadRepo::GetNextKey()
{
    if (!recycledKeys_.empty())
    {
        int k = recycledKeys_.front();
        recycledKeys_.erase(recycledKeys_.begin());
        return k;
    }
    return dataStore_.size();
}

void PayloadRepo::RecylceKey(const int k)
{
    for (const auto& key : recycledKeys_)
    {
        if (key == k)
        {
            return;
        }
    }
    recycledKeys_.push_back(k);
}

} // namespace common