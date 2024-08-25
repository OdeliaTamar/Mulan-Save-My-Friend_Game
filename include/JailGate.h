#pragma once
#include"Gate.h"
#include "Friend.h"

class Factory;
class JailGate :public Gate
{
public:
	JailGate(sf::Vector2f position);
	virtual ~JailGate() = default;
protected:
	static bool m_register;
};