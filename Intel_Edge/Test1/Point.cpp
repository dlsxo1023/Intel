#include "Point.h"

using namespace std;

template <typename T>
double Point<T>::Dist(Point<T>& p)
{	
	T w =  x - p. x;
	T h =  y - p. y;
	return sqrt(w * w + h * h);
}
template <typename T>
Point<T>& Point<T>::SetP(Point<T>& p)
{
	T x = p.x; T y = p. y; 
	return *this;
}
template <typename T>
Point<T>& Point<T>::SetP(T x, T y)
{
	this->x = x; this-> y =  y; 
	return *this;
}
template <typename T>
void Point<T>::viewP(const char *s)  // ����Ʈ ���� ������Ÿ�Կ��� ���� 
{
	//printf("%s(%d, %d)\n", s, x, y);
	cout << s << "(" << x << "," << y << ")\n";
}
template <typename T>
Point<T>& Point<T>::MoveP(T xo, T yo)
{
	this -> x += xo; this-> y += yo;
	return *this;
}
template <typename T>
Point<T>& Point<T>::operator+(Point<T> p)  // �� �� Cur p�� p�� + �������� (���ο� point��) ��ȯ
{
	Point<T>*p1 = new Point<T>(x + p.x,  y + p.y);  // new(�޸� �����Ҵ� Heap���� ���ο� ���� ����) �� �����ͷ� �޾ƾ���
	return *p1;
}
template <typename T>
Point<T>& Point<T>::operator++()  //��ü ���� ������ �����ε�
{
	++x; ++y;
	return *this;
}
template <typename T>
Point<T>& Point<T>::operator++(int) //��ü ���� ������ �����ε�
{
	Point* p1 = new Point<T>(x++, y++);
	return *p1;
}
template <typename T>
double Point<T>::operator*(Point<T> p)
{
	T w = x - p.x;
	T h = y - p.y;
	T area = w * h; 
	return ABS(area);
}

//Point3D& Point3D::SetP(Point3D p)
//{
//	X() = p.X(); Y() = p.Y(); z = p.z;
//	return *this;
//}
