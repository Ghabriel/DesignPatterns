#include <iostream>
#include "../impl.hpp"

class Message {
 public:
    Message(const std::string& msgContent) {
        content = msgContent;
    }

    const std::string& getContent() const {
        return content;
    }

 private:
    std::string content;
};


class UserEntranceEvent {
 public:
    UserEntranceEvent(const std::string& name) {
        username = name;
    }

    const std::string& getUsername() const {
        return username;
    }

 private:
    std::string username;
};


class MessageSource : public Observable<Message> {
 public:
    void run() {
        notifyObservers(Message("Hello, world!"));
    }
};


class UserEntranceSource : public Observable<UserEntranceEvent> {
 public:
    void run() {
        notifyObservers(UserEntranceEvent("admin"));
    }
};


class Chat : public Observer<Message>, public Observer<UserEntranceEvent> {
 private:
    void onNotify(const Message& data) override {
        std::cout << "Received message: " << data.getContent() << std::endl;
    }

    void onNotify(const UserEntranceEvent& data) override {
        std::cout << "A user entered the chatroom: " << data.getUsername() << std::endl;
    }
};


int main(int, char**) {
    Chat chat;
    MessageSource messageSource;
    UserEntranceSource userEntranceSource;

    messageSource.addObserver(chat);
    userEntranceSource.addObserver(chat);

    messageSource.run();
    userEntranceSource.run();

    userEntranceSource.removeObserver(chat);

    messageSource.run();
    userEntranceSource.run();
}
