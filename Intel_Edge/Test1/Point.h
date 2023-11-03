#pragma once
//#include <corecrt_math.h>
//extern double sqrt(double);
#include <iostream>
class Point
{
private:
	int x;

protected:
	int y;

public:
	Point(int x1 = 0, int y1 = 0) : x(x1), y(y1) {}
	int &X() { return x; }; // �����̺� ������ �ɹ� ���� ���� �ۺ� �����ڷ� �ٲٴ� �Լ�
	int &Y() { return y; }; //�����̺� ������ �ɹ� ���� ���� �ۺ� �����ڷ� �ٲٴ� �Լ�
	Point& SetP(Point P);   // Self-Reference
	Point& SetP(int x, int y);
	double Dist(Point p);  // Distance
	void viewP(const char *s = NULL); // View Current Point
	Point& MoveP(int xo, int yo);
};

class Point3D : public Point    // Ŭ���� ��� ����
{
private:	
	int z;
public:
	Point3D(int x = 0 , int y = 0, int z = 0) : Point(x , y), z(z)
	{}
	double Dist3D(Point3D p)    // Distance 3D
	{
		int w = X() - p.X();
		int h = y - p.y; // ����Ŭ���� protected ���� ����
		int d = z - p.z; //����Ŭ���� �����̱⿡ �����̺� int z ���ٰ���
		return sqrt((w * w) + (h * h) + (d * d));
	}
};

