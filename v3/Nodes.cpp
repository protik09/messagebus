//==============================================================
// Filename : Nodes.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Nodes class member function defintions
//==============================================================

#include "Nodes.h"

#include <iostream>
#include <mutex>
#include <chrono>

#include "Node.h"
#include "Message.h"
#include "ImageMessage.h"
#include "MeasurementMessage.h"
#include "MessageBus.h"


// Run method implementation for MessageBus
void Nodes::run()
{
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
	// Put data on the nodes
	std::vector<TextMessage*> garbage;
	for (int i = 10; i >= 1; i--)
	{
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


		
	}
	// clean up memory


}

// Start method implementation for MessageBus
void Nodes::start()
{
	// Run in thread
	std::thread node_thread([this]() { this->run(); });
	node_thread.detach();
}

