#include<iostream>
using namespace std;
#include "virtual_inher.h"


int display2(int n, Shape **p)
{
	int ch2 =0;
	int x1,x2,y1,y2;
	cout<<"Enter the choice of shape to draw \n";
	cout<<"\t1. Line\n";
	cout<<"\t2. Rect\n";
	cout<<"\t3. Polygon\n";
	cin>>ch2;
	switch(ch2)
	{
		case 1 :
		{
			// draw line and store pts at pointer at current n.
			//Line l;
			p[n] =new Line();
			
			cout<<n<<endl;
			cout<<"Enter the coordinates for the line points (x1,y1),(x2,y2) \n";
			cin>>x1>>y1>>x2>>y2;
			(p[n])->Setpts(x1,y1,x2,y2);
			(p[n])->Draw();
			++n;
			//display1(n,p);
			return n;
		}
		break;
		
		case 2 :
		{
			// draw rect and store pts at pointer at current n.
		//	Rect r;
			p[n] = new Rect();
		//	++n;
			cout<<"Enter the coordinates for the rectangle diagonal points (x1,y1),(x2,y2) \n";
			cin>>x1>>y1>>x2>>y2;
			(p[n])->Setpts(x1,y1,x2,y2);
			(p[n])->Draw();
			++n;
			return n;
		}
		break;
		
		case 3 :
		{
			int size;
			cout<<"Enter the size of polygon. \n";
			cin>>size;
			// draw a polygon 
		//	Poly pl(size, 'P');
			p[n] = new Poly(size);
		//	++n;
			(p[n])->Setpts();
			(p[n])->Draw();
			++n;
			return n;
		}
		break;
		
		default :
		{
			cout<<"Enter a valid choice \n";
			display2(n,p);
		}
		break;
		
	}

}

void _moveShape(int n,Shape **p)
{
	 try {
		 int xs,ys;
		//char tp = (p[n-1]->GetType());
		//cout<<"Last drawn fig is a "<<tp<<endl;


		cout<<"Enter x and y axis shift values: (The last drawn fig will be shifted horiz and vertically.)\n";
		cin>>xs>>ys;
		(p[n-1])->Move(xs,ys);				

		/*switch(tp)
		{
			case 'L':
				{
					(p[n-1])->Move(xs,ys);				
				//}
				break;

			case 'R':
				{
					((Rect *)p[n-1])->Move(xs,ys);
				}
				break;

			case 'P':
				{
					((Poly *)p[n-1])->Move(xs,ys);
				}
				break;
			default:

				cout<<"Enter valid choice:";
				break;
		}*/
    }
    catch (string exceptionString) {
        cout << exceptionString;
    }

}

int _eraseShape(int n, Shape **p)
{
	 try {
	//	 int xs,ys;
	//	char tp = (p[n-1]->GetType());
	//	cout<<"Last drawn fig is a "<<tp<<endl;


		cout<<"The last drawn fig will be erased.\n";
		(p[n-1])->Erase();				

		/*switch(tp)
		{
			case 'L':
				{
					((Line *)p[n-1])->Erase();				
				}
				break;

			case 'R':
				{
					((Rect *)p[n-1])->Erase();
				}
				break;

			case 'P':
				{
					((Poly *)p[n-1])->Erase();
				}
				break;
			default:

				cout<<"Enter valid choice:";
				break;
		}*/

    }
    catch (string exceptionString) {
        cout << exceptionString;
    }
	cout<<"Returning --n"<<endl;
	return --n;
}

void display1(int n, Shape **p)
{
	int ch;
	int _n1,_n2;
	cout<<"Enter choice to perform the following functions : \n";
	cout<<"\t1. Draw \n";
	cout<<"\t2. Move \n";
	cout<<"\t3. Erase/ Undo \n";
	cout<<"\t4. Exit \n";
	cin>>ch;
	switch(ch)
	{
		case 1:
		{
			//show second menu
			_n1=display2(n,p);
//			cout<<"Displaying p size"<<sizeof(p)/sizeof(p[0])<<endl;
			display1(_n1,p);
		}
			break;
		case 2:
		{
			//move last drawn shape
			if(n>0)
			{
				_moveShape(n,p);
//				cout<<"Displaying p size"<<sizeof(p)/sizeof(p[0])<<endl;
				display1(n,p);
			}
			else
			{
				cout<<"No shape drawn to move. \n";
			//	cout<<n;
				display1(n,p);
			}
		}
			break;
		
		case 3:
		{
			//erase last drawn shape
			if(n>0)
			{
				_n2 = _eraseShape(n,p);
				cout<<"Returned"<<_n2<<endl;
				display1(_n2,p);
			}
			else
				cout<<"No shape drawn to erase. \n";
				display1(n,p);
		}
		break;

		case 4:
			//exit the program
			//delete[] p;
			exit(0);
			break;

		default:
		{
			cout<<"Enter a valid choice. \n";
			display1(n,p);
		}
		break;
	}

}

int main()
{
	Shape *ps[100];
	static int n = 0;
	display1(n,ps);
	delete[] ps;
	return 0;
}
