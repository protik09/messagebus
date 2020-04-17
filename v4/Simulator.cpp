#include <iostream>
#include <string>
#include "Message.h"
#include "TextMessage.h"
#include "MeasurementMessage.h"
#include "ImageMessage.h"
#include "Node.h"
#include "MessageBus.h"
#include "NodeConfigReader.h"
#include "NodeConfigWriter.h"
#include "Nodes.h"
#include <thread>

int main() {
	std::string db = "C:\\Users\nhdha\Desktop\MEssagebus\cpp\messagebus\v4";

	NodeConfigWriter* n = new NodeConfigWriter(db);
	n->clear();

	n->writeNode("Node1", "localhost", 10000, "localhost", 20000);
	n->writeNode("Node2", "localhost", 10001, "localhost", 20001);
	n->writeNode("Node3", "localhost", 10002, "localhost", 20002);

	n->writeTopic("Topic1");
	n->writeTopic("Topic2");
	n->writeTopic("Topic3");
	n->writeTopic("TopicG");

	n->writeNodeTopic("Node1", "Topic1");
	n->writeNodeTopic("Node2", "Topic2");
	n->writeNodeTopic("Node3", "Topic3");
	n->writeNodeTopic("Node1", "TopicG");
	n->writeNodeTopic("Node2", "TopicG");

	MessageBus* bus = new MessageBus(db);
	bus->init();
	bus->start();

	Nodes* nodes = new Nodes(bus);
	nodes->start();

	std::string str;
	std::getline(std::cin, str);

	// clean up
	// ...
}