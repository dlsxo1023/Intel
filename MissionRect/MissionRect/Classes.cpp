#include "Classes.h"
double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}

}
void Point::Show(const char* s)  // ����Ʈ ���� ������Ÿ�Կ��� ���� 
{
	printf("%s(%d, %d)\n", s, x, y);
}
Point& Point::operator+(Point p)  // �� �� Cur p�� p�� + �������� (���ο� point��) ��ȯ
{
	Point* p1 = new Point(x + p.x, y + p.y);  // new(�޸� �����Ҵ� Heap���� ���ο� ���� ����) �� �����ͷ� �޾ƾ���
	return *p1;
}
