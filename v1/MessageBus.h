#pragma once

#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "Node.h"
#include "TextMessage.h"
#include "TextMessageCompare.cpp"

class MessageBus {
private:
	std::set<Node*> nodes;
	std::unordered_map<std::string, std::vector<Node*>> subscriptions;
	std::priority_queue<TextMessage*, std::vector<TextMessage*>, TextMessageCompare> queue;
		
public:
	MessageBus() {}
	void registerTopic(const std::string&);
	void registerNode(Node*);
	void registerNodeForTopic(Node*, std::string);
	void acceptMessage(TextMessage*);
	void printMessages();
	void handleMessages();
};