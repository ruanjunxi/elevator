#include"passenger.h"
void Passenger::setRequestTime(int requesttime)  // ��������ʱ�� 
{
	requestTime = requesttime;
}
void Passenger::setInitialFloor(int floor = 1)   // ���ó˿�����¥�� 
{
	initialFloor = floor;
}
void  Passenger::setDestination(int dest)   // ����Ŀ�ĵ� 
{
	requestTime = dest;
}
int   Passenger::getRequestTime()
{
	return requestTime;
}
int  Passenger::getInitialFloor()
{
	return initialFloor;
}
int  Passenger::getDestination()
{
	return destination;
}