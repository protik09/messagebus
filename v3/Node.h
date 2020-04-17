//==============================================================
// Filename : Node.h
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Node class member function prototypes
//==============================================================
#pragma once

#include "Message.h"

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

