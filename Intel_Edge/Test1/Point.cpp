#include "Point.h"
double Point::Dist(Point p)
{	
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
Point& Point::SetP(Point p)
{
	x = p.x; y = p.y; 
	return *this;
}
Point& Point::SetP(int x, int y)
{
	this->x = x; this->y = y; 
	return *this;
}
void Point::viewP(const char *s)  // ����Ʈ ���� ������Ÿ�Կ��� ���� 
{
	printf("%s(%d, %d)\n", s, x, y);
}
Point& Point::MoveP(int xo, int yo)
{
	this -> x += xo; this-> y += yo;
	return *this;
}
Point& Point::operator+(Point p)  // �� �� Cur p�� p�� + �������� (���ο� point��) ��ȯ
{
	Point *p1 = new Point(x + p.x, y + p.y);  // new(�޸� �����Ҵ� Heap���� ���ο� ���� ����) �� �����ͷ� �޾ƾ���
	return *p1;
}
Point& Point::operator++()  //��ü ���� ������ �����ε�
{
	++x; ++y;
	return *this;
}
Point& Point::operator++(int) //��ü ���� ������ �����ε�
{
	Point* p1 = new Point(x++, y++);
	return *p1;
}
double Point::operator*(Point p)
{
	double w = x - p.x;
	double h = y - p.y;
	double area = w * h; 
	return ABS(area);
}

Point3D& Point3D::SetP(Point3D p)
{
	X() = p.X(); Y() = p.Y(); z = p.z;
	return *this;
}
