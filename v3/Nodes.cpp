//==============================================================
// Filename : Nodes.cpp
// Authors : Dharanish NH, Protik Banerji
// Version : 1.0
// License : MIT
// Description : Nodes class member function defintions
//==============================================================

#include "Nodes.h"


// Run method implementation for MessageBus
void Nodes::run()
{
	const int max_nodes = 3;
	std::vector<Node *> node_vec;
	std::vector<Message *> garbage;

	// Init new nodes
	for (int i = 0; i < max_nodes; i++)
	{
		std::string node_name = "Node" + std::to_string(i);
		Node *node = new Node(node_name, bus);
		node_vec.push_back(node);
		bus->registerTopic("Topic" + i);
		bus->registerNodeForTopic(node , "Topic" + i);
	}
	// Register the topics and nodes to topics (also done in loop above)
	bus->registerTopic("TopicG");
	bus->registerNodeForTopic(node_vec[0], "TopicG");
	bus->registerNodeForTopic(node_vec[1], "TopicG");
	
	// Put data on the nodes
	for (int i = 10; i >= 1; i--)
	{
		TextMessage *message1 = new TextMessage(i, node_vec[0]->getName(), "Topic1", "(" + std::to_string(i) + ")" + node_vec[0]->getName() + "-->Topic1");
		MeasurementMessage *message2 = new MeasurementMessage(i, node_vec[1]->getName(), "Topic2", i);
		unsigned char *data1 = new unsigned char[16];
		ImageMessage *message3 = new ImageMessage(i, node_vec[2]->getName(), "Topic3", data1, 16);
		TextMessage *messageGen1 = new TextMessage(i, node_vec[0]->getName(), "TopicG", "(" + std::to_string(i) + ")" + node_vec[0]->getName() + "-->TopicG");
		MeasurementMessage *messageGen2 = new MeasurementMessage(i, node_vec[1]->getName(), "TopicG", i);
		unsigned char *data3 = new unsigned char[256];
		ImageMessage *messageGen3 = new ImageMessage(i, node_vec[2]->getName(), "TopicG", data3, 256);

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
	while (!node_vec.empty())
	{
		delete node_vec.back();
		node_vec.pop_back();
	}
	delete bus;
}

// Start method implementation for MessageBus
void Nodes::start()
{
	// Run in thread
	std::thread node_thread([this]() { this->run(); });
}