//==============================================================
// Filename : Simulator.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Simulate adding nodes, registering nodes and
// 				 topics, register node to topics and send messages
// 				 on the messagebus.
//==============================================================
#include <iostream>

#include "Message.h"
#include "TextMessage.h"
#include "MeasurementMessage.h"
#include "ImageMessage.h"
#include "Node.h"

#include "MessageBus.h"
#include <string>
#include <vector>

int main() {
	std::vector<Message*> garbage;
	MessageBus* bus=new MessageBus();

	Node* node1 = new Node("Node1", bus);
	Node* node2 = new Node("Node2", bus);
	Node* node3 = new Node("Node3", bus);

	bus->registerNode(node1);
	bus->registerNode(node2);
	bus->registerNode(node3);

	bus->registerTopic("Topic1");
	bus->registerTopic("TopicG");
	bus->registerTopic("Topic2");
	bus->registerTopic("Topic3");

	bus->registerNodeForTopic(node1, "Topic1");
	bus->registerNodeForTopic(node2, "Topic2");
	bus->registerNodeForTopic(node3, "Topic3");
	bus->registerNodeForTopic(node1, "TopicG");
	bus->registerNodeForTopic(node2, "TopicG");


	for (int i = 10; i >= 1; i--) {
		TextMessage* message1 = new TextMessage(i, node1->getName(), "Topic1", "(" + std::to_string(i) + ")" + node1->getName() + "-->Topic1");
		MeasurementMessage* message2 = new MeasurementMessage(i, node2->getName(), "Topic2", i);
		unsigned char* data1 = new unsigned char[16];
		ImageMessage* message3 = new ImageMessage(i, node3->getName(), "Topic3", data1, 16);
		TextMessage* messageGen1 = new TextMessage(i, node1->getName(), "TopicG", "(" + std::to_string(i) + ")" + node1->getName() + "-->TopicG");
		MeasurementMessage* messageGen2 = new MeasurementMessage(i, node2->getName(), "TopicG", i);
		unsigned char* data3 = new unsigned char[256];
		ImageMessage* messageGen3 = new ImageMessage(i, node3->getName(), "TopicG", data3, 256);

		bus->acceptMessage(message1);
		bus->acceptMessage(message2);
		bus->acceptMessage(message3);
		bus->acceptMessage(messageGen1);
		bus->acceptMessage(messageGen2);
		bus->acceptMessage(messageGen3);

		garbage.push_back(message1);
		garbage.push_back(message2);
		garbage.push_back(message3);
		garbage.push_back(messageGen1);
		garbage.push_back(messageGen2);
		garbage.push_back(messageGen3);

	}
	bus->handleMessages();

	// clean up memory
	while (!garbage.empty())
	{
		delete garbage.back();
		garbage.pop_back();
	}
	garbage.shrink_to_fit();
	delete node1;
	delete node2;
	delete node3;
	delete bus;
}