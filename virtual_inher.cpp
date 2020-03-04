#include<iostream>
using namespace std;
#include "virtual_inher.h"


Shape::Shape(int n)
{
	if(n > 0)
	{
		size = n;
		pts = new Point[n];
	}
	else
		cout<<"Enter Valid Size.";
	
//	if(t == 'L' || t == 'R' || t == 'P')
//	{
//		type = t;
//	}
//	else
//		throw "Shape is not defined.";
	
}

Shape::~Shape()
{
	delete[] pts;
}

//char Shape::GetType()
//{
//	return type;
//}

void Shape::Move(int x1 , int y1)
{
	
	for(int i=0;i<size;i++)
	{
	}
	for(int i = 0; i < size; i++)
	{   	
		cout<<"Moving"<<"("<<pts[i].x<<","<<pts[i].y<<")\t"<<"to ("<<pts[i].x+x1<<","<<pts[i].y+y1<<")\n";
		pts[i].x += x1;
		pts[i].y += y1;
	}
}

Shape& Shape::operator=(Shape& s)
{
	if(size != s.size)
	{
		delete[] pts;
		size = s.size;
		//type = s.type;
		pts = new Point[s.size];
	}
	for(int i = 0; i < size; i++ )
	{
		pts[i].x = s.pts[i].x;
		pts[i].y = s.pts[i].y;
	}
	return *this;
}

void Shape::Draw()
{
}

void Shape::Erase()
{
}

void Shape::Setpts()
{
}

void Shape::Setpts(int x1, int y1, int x2, int y2)
{
}

Line::Line():Shape(2)
{
}
void Line::Move(int x1,int y1)
{
	Shape::Move(x1, y1);
	cout<<"Finished moving line .... \n";
}

void Line::Draw()
{
	cout<<"Drawing line .... \n";
	for(int i=0;i<size;i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<"\n";
}
void Line::Erase()
{
	
	cout<<"Erasing Line .... \n";
	for(int i = 0; i < size; i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<endl;
}
void Line::Setpts(int x1,int y1, int x2, int y2)
{
	Shape::pts[0].x = x1;
	Shape::pts[0].y = y1;
	Shape::pts[1].x = x2;
	Shape::pts[1].y = y2;
}



Rect::Rect():Shape(2)
{

}
void Rect::Move(int x1,int y1)
{
	Shape::Move(x1,  y1);	
	cout<<"Finished moving Rectangle .... \n";
}
void Rect::Draw()
{
	cout<<"Drawing Rectangle .... \n";
	for(int i=0;i<size;i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<"\n";
}
void Rect::Erase()
{

	cout<<"Erasing Rectangle .... \n";
	for(int i = 0; i < size; i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<endl;
}
void Rect::Setpts(int x1,int y1, int x2, int y2)
{
	pts[0].x = x1;
	pts[0].y = y1;
	pts[1].x = x2;
	pts[1].y = y2;

}

Poly::Poly(int n):Shape(n)
{
}

void Poly::Move(int x1, int y1)
{
	Shape::Move(x1,y1);
	cout<<"Finished moving Polygon .... \n";
}

void Poly::Draw()
{
	cout<<"Draw polygon:......."<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<"\n";
}

void Poly::Erase()
{
	cout<<"Erasing Polygon......\n";
	for(int i = 0; i < size; i++)
	{
		cout<<"("<<pts[i].x<<","<<pts[i].y<<")\t";
	}
	cout<<endl;
}

void Poly::Setpts()
{
	int x1,y1;
	for(int i =0; i < size; i++)
	{
		cout<<"Enter coordinates for vertex"<<i+1<<endl;
		cin>>x1>>y1;
		pts[i].x = x1;
		pts[i].y = y1;
	}
}





