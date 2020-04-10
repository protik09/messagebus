#include "MeasurementMessage.h"

double MeasurementMessage::getMeasurement()
{
	return m;
}

 std::string MeasurementMessage::toString() const

{                                                                 //toString function definition
	 return "MESSAGE " + std::to_string(Message::getPriority()) + " " + from + " " + Message::topic+" M " + m;     //concatenates info of priority,from,topic
}