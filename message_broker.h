#ifndef MESSAGE_BROKER_H
#define MESSAGE_BROKER_H

#include <string>
#include <sqlite3.h>
#include <mutex>
#include "databaseOpenStatus.h"

class MessageBroker {
public:
    MessageBroker(const std::string& dbFilename);
    ~MessageBroker();

    bool isInitialized() const;

private:
    sqlite3* db_;
    std::mutex dbMutex_;
    bool initialized_;
};

#endif  // MESSAGE_BROKER_H
