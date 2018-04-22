class Elevator
{
private:
	int currentFloor;   // ���ݵ�ǰ¥�� 
	int direction;    // 1 ��������  ��0 ��������
public:
	Elevator(int dir = 1, int floor = 0 ,int pp= 0);  // ���ݳ�ʼ������ ,�ҵ����ڵ�0��
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