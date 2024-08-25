#include "Subject.h"

Subject::Subject()
{
}
//------------------------------------
void Subject::registerObserver(Observer* observer)
{
	m_observers.emplace_back(observer);
}
