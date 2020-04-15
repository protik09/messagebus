#pragma once

#include <string>
#include "TextMessage.h"
//#include "MessageBus.h"
class MessageBus;

class Node {
private:
	std::string name;
	MessageBus* bus;
public:
	Node(const std::string& name, MessageBus* bus) :
		name(name), bus(bus) {}
	std::string getName() const;
	void sendMessage(Message*);
	void acceptMessage(Message*);
	friend bool operator<(const Node&, const Node&);
};

