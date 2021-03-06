#pragma once

#include "../network/protocol/Packet.h"

class SetHealthPacket : public Packet {
public:
	virtual ~SetHealthPacket();
	virtual char getId() const;
	virtual void write(BinaryStream&) const;
	virtual void read(BinaryStream&);
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) const;
};