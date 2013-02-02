/*
 * Telnet.h
 *
 *  Created on: Feb 2, 2013
 *      Author: kurios
 */

#ifndef TELNET_H_
#define TELNET_H_

#include <string>
#include <deque>
#include <mutex>

namespace knet {


class Message {

public:
	std::string * msg;
	uint16_t connection;

	Message();
	Message(std::string *, uint16_t);
	~Message();
};
class Telnet {
public:
	Telnet(uint16_t port);
	virtual ~Telnet();
	uint8_t open();
	knet::Message * getMessage();
	uint8_t sendMessage(knet::Message *);
	bool hasMessage();

private:
	uint16_t port;
	std::deque<Message> msgList;
	int socket;
	std::mutex msgListMutex;
};

} /* namespace knet */
#endif /* TELNET_H_ */
