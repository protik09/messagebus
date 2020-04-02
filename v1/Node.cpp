#include <iostream>

#include "Node.h"
#include "TextMessage.h"
#include "MessageBus.h"

std::string Node::getName() const {
	return name;
}

void Node::sendMessage(TextMessage* message)  {
	bus->acceptMessage(message);
}

void Node::acceptMessage(TextMessage* message) {
	std::cout << message->toString() << std::endl;
}

bool operator<(const Node& lhs, const Node& rhs) {
	return lhs.name < rhs.name;
}