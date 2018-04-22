class Elevator
{
private:
	int currentFloor;   // 电梯当前楼层 
	int direction;    // 1 代表向上  ，0 代表向下
public:
	Elevator(int dir = 1, int floor = 0 ,int pp= 0);  // 电梯初始向上走 ,且电梯在第0层
	int population;
	void changeDirection(int dir)
	{
		direction = dir;
	}
	void move(int dir)
	{
		if (dir)  currentFloor++;
		else currentFloor--;
	}
	int getCurrentFloor()
	{
		return currentFloor;
	}
	int getDirection()
	{
		return direction;
	}
};
Elevator::Elevator(int dir, int floor, int pp)
{
	direction = dir;
	currentFloor = floor;
	population = pp;
}