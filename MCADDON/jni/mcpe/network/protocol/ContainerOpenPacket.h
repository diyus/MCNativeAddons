#pragma once

#include "../network/protocol/Packet.h"

class ContainerOpenPacket : public Packet {
public:
	virtual ~ContainerOpenPacket();
	virtual char getId() const;
	virtual void write(BinaryStream&) const;
	virtual void read(BinaryStream&);
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) const;
};