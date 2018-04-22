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
	if ((fp = fopen(srcFile, "r")) == NULL)      //�ж��ļ��Ƿ���ڼ��ɶ�  
	{
		printf("Open Falied!");
		return;
	}
	fgets(strLine, MAX_LINE, fp);
	sscanf(strLine, "%d", &n);
	while (!feof(fp))                                   //ѭ����ȡÿһ�У�ֱ���ļ�β  
	{
		fgets(strLine, MAX_LINE, fp);    //��fp��ָ����ļ�һ�����ݶ���strLine������  
		sscanf(strLine, "%d %d %d", &a, &b, &c);
		p[i].setDestination(c);
		p[i].setInitialFloor(b);
		p[i].setRequestTime(a);
		i++;
	}
}
void writeFile(const char *fileName, const char *content, int current_floor, int current_time)     //�������ļ�ȫ����д������  
{
	FILE *fp = NULL;                                   //�����ļ�ָ��  
	if ((fp = fopen(fileName, "a")) == NULL)         //��ָ���ļ�������ļ����������½����ļ�  
	{
		printf("Open Failed.\n");
		return;
	}
	if (current_time) {
		fprintf	(fp, "������%dʱ��ͣ��%d¥", current_time, current_floor);
	}
	fprintf(fp, "%s\n", content);                 //��ʽ��д���ļ���׷�����ļ�ĩβ��  
	fclose(fp);    //�ر��ļ�  
}
int main()
{
	readFile("./input.txt");
	int currentTime = 0;
	bool exit_flag = true;
	p[0].flag = 1;
	currentTime = p[0].getRequestTime();  // ��һλ�˿ͷ�������
	while (1)
	{
		//if (lift.getDirection) {  //��������
		for (int i = 0; i < n; i++) {
			if (p[i].getRequestTime() <= currentTime && p[i].getInitialFloor() == lift.getCurrentFloor() && p[i].flag == 0) {    //�ϵ���
				p[i].flag = 1;
				lift.population++;
				currentTime++;  //�ϵ��ݼ�����ͣ�� ʱ���һ 
				writeFile("output.txt", " ", lift.getCurrentFloor(), currentTime);
			}
			if (p[i].flag == 1 && lift.getCurrentFloor() == p[i].getDestination()) {      // �µ���
				p[i].flag = -1;
				lift.population--;
				currentTime++;
				writeFile("output.txt", " ", lift.getCurrentFloor(), currentTime);
				// writeFile(outputFile, " ", 0, currentFloor, currentTime)
			}
			// }
			if (lift.population != 0)   lift.move(lift.getDirection());  // ������û��ʱ���ݲ��ƶ�
			if (lift.getCurrentFloor() == 2 && lift.getDirection() == 1) {   // ���ݵ��ﶥ��
				lift.changeDirection(0);
			}
			if (lift.getCurrentFloor() == 0 && lift.getDirection() == 0) {
				lift.changeDirection(1);
			}
		}
		currentTime++;
		// �˳��ж� 
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

