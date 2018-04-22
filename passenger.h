class Passenger
{
private:
	int requestTime;
	int initialFloor;
	int destination;
public:
	int flag;  // 0 代表未上电梯 1代表上了电梯  -1代表结束行程
	void setFlag(int f = 0);
	void setRequestTime(int requesttime);
	void setInitialFloor(int floor);
	void setDestination(int dest);
	int getRequestTime();
	int getInitialFloor();
	int getDestination();
}; 
