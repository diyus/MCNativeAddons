#pragma once

#include "../network/protocol/Packet.h"

class LevelEventPacket : public Packet {
public:
	virtual ~LevelEventPacket();
	virtual char getId() const;
	virtual void write(BinaryStream&) const;
	virtual void read(BinaryStream&);
	virtual void handle(const NetworkIdentifier&, NetEventCallback&) const;
};