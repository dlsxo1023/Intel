#pragma once
//#include <corecrt_math.h>
//extern double sqrt(double);
#include <iostream>

#define ABS(x)  (((x) < 0) ? ((-x)) : (x)) 

template <typename T>
class Point
{
private:
	T x; T y;

public:
	Point(T x1 = 0, T y1 = 0) : x(x1), y(y1) {}

	T &X() { return x; }; // �����̺� ������ �ɹ� ���� ���� �ۺ� �����ڷ� �ٲٴ� �Լ�
	T &Y() { return y; }; //�����̺� ������ �ɹ� ���� ���� �ۺ� �����ڷ� �ٲٴ� �Լ�
	Point<T>& SetP(Point<T>& P);   // Self-Reference
	Point<T>& SetP(T x, T y);
	double Dist(Point<T>& p);  // Distance
	void viewP(const char *s = NULL); // View Current Point
	Point<T>& MoveP(T xo, T yo);
	Point<T>& operator+(Point<T> p);
	Point<T>& operator++();  //���� ������
	Point<T>& operator++(int);  //���� ������
	double operator*(Point<T> p); // �� ���� �̷�� �簢���� ����  
};

//class Point3D : public Point    // Ŭ���� ��� ����
//{
//private:	
//	int z;
//public:
//	Point3D(int x = 0 , int y = 0, int z = 0) : Point(x , y), z(z)
//	{}
//	Point3D& SetP(Point3D p);
//	double Dist3D(Point3D p)    // Distance 3D
//	{
//		int w = X() - p.X();
//		int h = Y() - p.Y(); // ����Ŭ���� protected ���� ����
//		int d = z - p.z; //����Ŭ���� �����̱⿡ �����̺� int z ���ٰ���
//		return sqrt((w * w) + (h * h) + (d * d));
//	}
//};

