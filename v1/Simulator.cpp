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

#include "TextMessage.h"
#include "MessageBus.h"
#include <vector>

int main()
{
	MessageBus *bus = new MessageBus();

	Node *node1 = new Node("Node1", bus);
	Node *node2 = new Node("Node2", bus);
	Node *node3 = new Node("Node3", bus);

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

	std::vector<TextMessage *> garbage;

	for (int i = 12; i > 0; i--)
	{
		TextMessage *message1 = new TextMessage(i, node1->getName(), "Topic1", "(" + std::to_string(i) + ")" + node1->getName() + "-->Topic1");
		TextMessage *message2 = new TextMessage(i, node2->getName(), "Topic2", "(" + std::to_string(i) + ")" + node2->getName() + "-->Topic2");
		TextMessage *message3 = new TextMessage(i, node3->getName(), "Topic3", "(" + std::to_string(i) + ")" + node3->getName() + "-->Topic3");
		TextMessage *messageGen = new TextMessage(i, node1->getName(), "TopicG", "(" + std::to_string(i) + ")" + node1->getName() + "-->TopicG");

		bus->acceptMessage(message1);
		bus->acceptMessage(message2);
		bus->acceptMessage(message3);
		bus->acceptMessage(messageGen);

		garbage.push_back(message1);
		garbage.push_back(message2);
		garbage.push_back(message3);
		garbage.push_back(messageGen);
	}
	bus->handleMessages();

	// clean up memory
	// ...
}
