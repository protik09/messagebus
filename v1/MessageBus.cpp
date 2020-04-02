//==============================================================
// Filename : MessageBus.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Messagebus Class Method Definitions
//==============================================================

#include <map>

#include "MessageBus.h"

// Register a node to a particular topic
void MessageBus::registerTopic(const std::string& topic) {
	subscriptions[topic] = std::vector<Node*>();
}

// Insert a new node on the message bus
void MessageBus::registerNode(Node* node) {
	nodes.insert(node);
}

// Add
void MessageBus::registerNodeForTopic(Node* node, std::string topic) {
	std::vector<Node*> elements = subscriptions[topic];
	elements.push_back(node);
	subscriptions[topic] = elements;
}

void MessageBus::acceptMessage(TextMessage* message) {
	queue.push(message);
}

void MessageBus::printMessages() {
	while (!queue.empty()) {
		TextMessage tm = *(queue.top());
		std::cout << tm.toString() << std::endl;
		queue.pop();
	}
}

void MessageBus::handleMessages() {
	while (queue.size()!=0) {
		TextMessage* message = queue.top();
		
 		std::vector<Node*> elements = subscriptions[message->getTopic()];

		for (Node* node : elements) {
			node->acceptMessage(message);
		}
		queue.pop();
	}
}