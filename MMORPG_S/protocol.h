#pragma once

constexpr int BUF_SIZE = 1024;
constexpr int NAME_SIZE = 20;

enum class PacketType : unsigned char
{
    C2S_MOVE,
    S2C_MOVE,
};

#pragma pack (push, 1)

struct C2S_LOGIN_PACKET {
	unsigned char size;
	char	type;
	char	name[NAME_SIZE];
};

struct C2S_MOVE_PACKET {
	unsigned char size;
	char	type;
	char	direction;  // 0 : UP, 1 : DOWN, 2 : LEFT, 3 : RIGHT
	unsigned	move_time;
};

struct S2C_MOVE_PACKET {
	unsigned char size;
	char	type;
	int		id;
	short	x, y;
	unsigned int move_time;
};


#pragma pack (pop)