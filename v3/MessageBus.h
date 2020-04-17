#pragma once

#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
#include <iostream>

#include "Node.h"
#include "Nodes.h"
#include "Message.h"
#include "MessageCompare.cpp"
#include <thread>
#include <mutex>
#include <chrono>

class MessageBus {
private:
	std::set<Node*> nodes;
	std::unordered_map<std::string, std::vector<Node*>> subscriptions;
	std::priority_queue<Message*, std::vector<Message*>, MessageCompare> queue;
	void run();
		
public:
	MessageBus() {}
	void registerTopic(const std::string&);
	void registerNode(Node*);
	void registerNodeForTopic(Node*, std::string);
	void acceptMessage(Message*);
	void printMessages();
	void handleMessages();
	void start();
};