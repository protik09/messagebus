#pragma once
#include "MessageBus.h"

class Nodes {
private:
	MessageBus* bus;
	void run();
public:
	Nodes(MessageBus* bus) : bus(bus) {}
	void start();
};

