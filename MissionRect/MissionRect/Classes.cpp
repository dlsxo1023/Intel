#include "Classes.h"
double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;
	return sqrt(w * w + h * h);
}
void Point::Show(const char* s)  // 디폴트 값은 프로토타입에만 지정 
{
	printf("%s(%d, %d)\n", s, x, y);
}
void Point::ShowEX(const char* s)  // 디폴트 값은 프로토타입에만 지정 
{
	//std::cout << s << "(" << x << "," << y << ")"<<std::endl;
	printf("%s(%d, %d)", s, x, y);
}
Rect& Rect::Show(const char* s)  // Rect(p1(x1, y1), p2(x2, y2))
{
	printf("%s(", s);
	LL.ShowEX("LL");
	UR.ShowEX("UR");
	printf(")\n");
	return *this;
}
double Rect::Area()
{
	return (double)(ABS((p1.x - p2.x) * (p1.y - p2.y)));
}
Point& Point::operator+(Point p)  // 두 점 Cur p와 p의 + 연산결과를 (새로운 point로) 반환
{
	p1 = (new Point(x + p.x, y + p.y));  // new(메모리 동적할당 Heap영역 새로운 공간 생성) 는 포인터로 받아야함
	return *p1;
}
Rect& Rect::operator+(Rect r)
{
	int x1 = MIN(MIN(this->x1, this->x2), MIN(r.x1, r.x2));
	int x2 = MAX(MAX(this->x1, this->x2), MAX(r.x1, r.x2));
	int y1 = MIN(MIN(this->y1, this->y2), MIN(r.y1, r.y2));
	int y2 = MAX(MAX(this->y1, this->y2), MAX(r.y1, r.y2));
	return *(new Rect(x1, y1, x2, y2));
}
Rect& Rect::operator-(Rect r)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	Rect& rr = *this;

	// 두 사각형이 겹치지 않는 경우 0 Rect 반환
	if (rr.LR.x < r.LL.x || rr.LL.x > r.LR.x) return *(new Rect(0, 0, 0, 0));
	if (rr.UL.y < r.LL.y || rr.LL.y > r.UL.y) return *(new Rect(0, 0, 0, 0));
		x1 = MIN(MIN(rr.x1, rr.x2), MIN(r.x1, r.x2));
		x2 = MAX(rr.LL.x, r.LL.x); 
		x3 = MIN(rr.LR.x, r.LR.x);
		x4 = MAX(MAX(rr.x1, rr.x2), MAX(r.x1, r.x2));
	 
		y1 = MIN(MIN(rr.y1, rr.y2), MIN(r.y1, r.y2));
		y2 = MIN(rr.UL.y, r.UL.y);
		y3 = MAX(rr.LL.y, r.LL.y);
		y4 = MAX(MAX(rr.y1, rr.y2), MAX(r.y1, r.y2));
	
	return *(new Rect(x2, y2, x3, y3));
}
double Rect::operator*(Rect r)
{
	double d1 = Area();
	double d2 = r.Area();
	double d3 = (*(this) - r).Area();

	return d1 + d2 - d3;
}