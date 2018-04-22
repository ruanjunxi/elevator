#include<iostream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include "passenger.h"
#include"elevator.h"
#define MAX_USER 500
#define MAX_LINE 3
using namespace std;
Elevator lift;
Passenger p[MAX_USER];
int n = 0;
void readFile(const char *srcFile)
{
	int i = 0,a,b,c;
	FILE *fp = NULL;
	char strLine[MAX_LINE];
	memset(strLine, 0, MAX_LINE);
	if ((fp = fopen(srcFile, "r")) == NULL)      //判断文件是否存在及可读  
	{
		printf("Open Falied!");
		return;
	}
	fgets(strLine, MAX_LINE, fp);
	sscanf(strLine, "%d", &n);
	while (!feof(fp))                                   //循环读取每一行，直到文件尾  
	{
		fgets(strLine, MAX_LINE, fp);    //将fp所指向的文件一行内容读到strLine缓冲区  
		sscanf(strLine, "%d %d %d", &a, &b, &c);
		p[i].setDestination(c);
		p[i].setInitialFloor(b);
		p[i].setRequestTime(a);
		i++;
	}
}
void writeFile(const char *fileName, const char *content, int current_floor, int current_time)     //参数：文件全名，写入内容  
{
	FILE *fp = NULL;                                   //定义文件指针  
	if ((fp = fopen(fileName, "a")) == NULL)         //打开指定文件，如果文件不存在则新建该文件  
	{
		printf("Open Failed.\n");
		return;
	}
	if (current_time) {
		fprintf	(fp, "电梯在%d时刻停在%d楼", current_time, current_floor);
	}
	fprintf(fp, "%s\n", content);                 //格式化写入文件（追加至文件末尾）  
	fclose(fp);    //关闭文件  
}
int main()
{
	readFile("./input.txt");
	int currentTime = 0;
	bool exit_flag = true;
	p[0].flag = 1;
	currentTime = p[0].getRequestTime();  // 第一位乘客发出请求
	while (1)
	{
		//if (lift.getDirection) {  //电梯上升
		for (int i = 0; i < n; i++) {
			if (p[i].getRequestTime() <= currentTime && p[i].getInitialFloor() == lift.getCurrentFloor() && p[i].flag == 0) {    //上电梯
				p[i].flag = 1;
				lift.population++;
				currentTime++;  //上电梯即电梯停下 时间加一 
				writeFile("output.txt", " ", lift.getCurrentFloor(), currentTime);
			}
			if (p[i].flag == 1 && lift.getCurrentFloor() == p[i].getDestination()) {      // 下电梯
				p[i].flag = -1;
				lift.population--;
				currentTime++;
				writeFile("output.txt", " ", lift.getCurrentFloor(), currentTime);
				// writeFile(outputFile, " ", 0, currentFloor, currentTime)
			}
			// }
			if (lift.population != 0)   lift.move(lift.getDirection());  // 当电梯没人时电梯不移动
			if (lift.getCurrentFloor() == 2 && lift.getDirection() == 1) {   // 电梯到达顶部
				lift.changeDirection(0);
			}
			if (lift.getCurrentFloor() == 0 && lift.getDirection() == 0) {
				lift.changeDirection(1);
			}
		}
		currentTime++;
		// 退出判断 
		for (int i = 0; i < n; i++) {
			if (p[i].flag != -1) {
				exit_flag = false;
				break;
			}
		}
		if (exit_flag == 1) {
			break;
		}
	}
	 system("pause");
	 return 0;
}

