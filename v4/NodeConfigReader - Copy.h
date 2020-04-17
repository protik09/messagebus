#pragma once
#include <string>
#include "MessageBus.h"

class NodeConfigReader {
private:
	std::string dblocation;
	MessageBus* bus = nullptr;
	
public:
	NodeConfigReader(const std::string dblocation) : dblocation(dblocation) {}
	void setMessageBus(MessageBus* bus);
	void setupNodes();
};

