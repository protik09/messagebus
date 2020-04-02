#include <iostream>

#include "Message.h"
#include "TextMessage.h"
#include "MeasurementMessage.h"
#include "ImageMessage.h"
#include "Node.h"
#include "MessageBus.h"
#include <string>
#include <thread>
#include <vector>
#include "Nodes.h"
#include <chrono>
using namespace std::chrono_literals;

int main() {
	MessageBus* bus = new MessageBus();
	bus->start();

	Nodes* nodes= new Nodes(bus);
	nodes->start();

	std::string str;
	std::getline(std::cin, str);

	// clean up
	// ...

	return 0;
}