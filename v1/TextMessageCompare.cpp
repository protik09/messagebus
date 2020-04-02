#include <iostream>

#include "TextMessage.h"

class TextMessageCompare {
public:
	bool operator()(TextMessage* a, TextMessage* b) {
		return (a->getPriority() > b->getPriority());
	}
};