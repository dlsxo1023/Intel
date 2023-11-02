#pragma once
#include <iostream>
#define MIN(x, y)  (((x) > (y)) ? (y) : (x))
#define MAX(x, y)  (((x) < (y)) ? (y) : (x))

class point
{
private:     //���������� ( �ܺ� ���� �Ұ�)

public:  //����������  (�ܺ� ���� ����)
    int x, y, z;  //�ɹ� ���� ����. //��ü�� ��ǥ
    point(int x = 0, int y = 0) : x(x), y(y)  // �̴ϼȶ�����
        //������ ���� //�ƹ��� Ÿ���� ���� �Լ�//�ܺ������� �ʿ��ϱ⿡ public ���������� ���� �̸� ���
        //�Լ��� Ư���� ������ ����(default, overload ��)
    {
        z = 0;//x = x1; y = y1; 
    }
    void SetP(int x1 = 0, int y1 = 0) { x = x1; y = y1; }
    double Dist(point p)   // �ɹ� �Լ� // �� ������ �Ÿ� ���.  // ���ϰ��� Double Ÿ������ return
    {
        int w = x - p.x;
        int h = y - p.y;
        return sqrt(w * w + h * h);   //sqrt ��ɾ� ��ü�� double Ÿ���� // ���� Ÿ���� ���Ծ��ص� ��
    }
    double Dist(point p1, point p2)   // �ɹ� �Լ� // �� ��(�ڽ��� ������) �Ÿ� ���.  // ���ϰ��� Double Ÿ������ return
    {
        int w = p1.x - p2.x;
        int h = p1.y - p2.y;
        return sqrt(w * w + h * h);   //sqrt ��ɾ� ��ü�� double Ÿ���� // ���� Ÿ���� ���Ծ��ص� ��
    }
};

class Rect
{

    point p11, p22;  // Ŭ���� �ɹ� ���� ����
    //point LL, LR, UL, UR;
public:
    Rect(point p1, point p2) : p11(p1), p22(p2)    // �̴ϼȶ�����
    {
        /* int xl = MIN(p1.x, p2.x);
         int xr = MAX(p1.x, p2.x);
         int yl = MIN(p1.y, p2.y);
         int yu = MAX(p1.y, p2.y);
         LL = point(xl, yl);
         LR = point(xr, yl);
         UL = point(xl, yu);
         UR = point(xr, yu);*/

    }
    point GetLL();
    point GetLR();
    point GetUL();
    point GetUR();
};
point Rect::GetLL()
{
    return point(MIN(p11.x, p22.x), MIN(p11.y, p22.y));
}
point Rect::GetLR()
{
    return point(MAX(p11.x, p22.x), MIN(p11.y, p22.y));
}
point Rect::GetUL()
{
    return  point(MIN(p11.x, p22.x), MAX(p11.y, p22.y));
}
point Rect::GetUR()
{
    return  point(MAX(p11.x, p22.x), MAX(p11.y, p22.y));

}