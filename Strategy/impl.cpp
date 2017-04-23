/* created by Ghabriel Nunes <ghabriel.nunes@gmail.com> [2017] */

#include <iostream>
#include <memory>
#include <sstream>
#include <unordered_map>

// Utility function to pretty-print unordered maps
template<typename K, typename V>
std::string mapToString(const std::unordered_map<K,V>& map) {
    std::stringstream stream;
    stream << "{";
    bool first = true;
    for (auto& pair : map) {
        if (!first) {
            stream << ", ";
        }
        stream << "{" << pair.first << ", " << pair.second << "}";
        first = false;
    }
    stream << "}";
    return stream.str();
}


// Utilizes the Non-Virtual Interface (NVI) idiom
class Logger {
 public:
    void log(const std::string& message) {
        onLog(message);
    }

 private:
    virtual void onLog(const std::string& message) = 0;
};


class PrintLogger : public Logger {
 private:
    void onLog(const std::string& message) override {
        std::cout << message << std::endl;
    }
};


// Note that this is an example of the Null Object pattern
class NullLogger : public Logger {
 private:
    void onLog(const std::string&) override {}
};


class Database {
 public:
    using ParameterList = std::unordered_map<std::string, std::string>;

    Database(std::shared_ptr<Logger> logger) : logger(logger) {}

    void execute(const std::string& query, const ParameterList& params) {
        logger->log("Query: " + query + "\nParams: " + mapToString(params));
        // execute query here...
    }

 private:
    std::shared_ptr<Logger> logger;
};


int main(int, char**) {
    // Changing "PrintLogger" to "NullLogger" effectively disables logging
    auto logger = std::shared_ptr<Logger>(new PrintLogger());

    auto connection = Database(logger);
    connection.execute("SELECT `name` FROM `users` WHERE `id`=:id", {
        {"id", "42"}
    });

    connection.execute("UPDATE `users` SET `name`=:name WHERE `id`=:id", {
        {"id", "42"},
        {"name", "admin"}
    });

    std::cout << "Finished" << std::endl;
}
