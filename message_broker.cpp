#include "message_broker.h"
#include <iostream>

MessageBroker::MessageBroker(const std::string& dbFilename) : db_(nullptr), dbMutex_() {
    int rc = sqlite3_open(dbFilename.c_str(), &db_);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening SQLite database: " << sqlite3_errmsg(db_) << std::endl;
        sqlite3_close(db_);
        db_ = nullptr;
    } else {
        std::cout << "SQLite database opened successfully." << std::endl;
        initialized_ = true;
    }
}

MessageBroker::~MessageBroker() {
    if (db_) {
        sqlite3_close(db_);
        db_ = nullptr;
    }
}

bool MessageBroker::isInitialized() const {
    return initialized_;
}
