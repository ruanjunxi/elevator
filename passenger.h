class Passenger
{
private:
	int requestTime;
	int initialFloor;
	int destination;
public:
	int flag;  // 0 ����δ�ϵ��� 1�������˵���  -1��������г�
	void setFlag(int f = 0);
	void setRequestTime(int requesttime);
	void setInitialFloor(int floor);
	void setDestination(int dest);
	int getRequestTime();
	int getInitialFloor();
	int getDestination();
}; 
