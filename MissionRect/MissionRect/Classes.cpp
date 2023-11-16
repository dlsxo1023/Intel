#include "Classes.h"
double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
void Point::Show(const char* s)  // ����Ʈ ���� ������Ÿ�Կ��� ���� 
{
	printf("%s(%d, %d)\n", s, x, y);
}
void Point::ShowEX(const char* s)  // ����Ʈ ���� ������Ÿ�Կ��� ���� 
{
	printf("%s(%d, %d)", s, x, y);
}
void Rect::Show(const char* s)  // Rect(p1(x1, y1), p2(x2, y2))
{
	printf("%s(", s);
	p1.ShowEX("p1");
	p2.SHowEX("p2");
	printf(")\n");
}
Point& Point::operator+(Point p)  // �� �� Cur p�� p�� + �������� (���ο� point��) ��ȯ
{
	Point* p1 = new Point(x + p.x, y + p.y);  // new(�޸� �����Ҵ� Heap���� ���ο� ���� ����) �� �����ͷ� �޾ƾ���
	return *p1;
}
