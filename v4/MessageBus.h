#pragma once

#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <string>

#include "Node.h"
#include "Message.h"
#include "MessageCompare.cpp"

class MessageBus {
private:
	std::set<Node*> nodes;
	std::unordered_map<std::string, std::vector<Node*>> subscriptions;
	std::priority_queue<Message*, std::vector<Message*>, MessageCompare> queue;
	std::string dblocation;
	void run();

public:
	MessageBus(const std::string dblocation): dblocation(dblocation) {}
	void init();
	void registerTopic(const std::string&);
	void registerNode(Node*);
	void registerNodeForTopic(Node*, std::string);
	void acceptMessage(Message*);
	void printMessages();
	void handleMessages();
	void start();
};