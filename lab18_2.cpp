#include <iostream>
#include <algorithm>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *R1,Rect *R2){
    double dx1 = R1->x+R1->w;
    double dy1 = R1->y-R1->h;
    double dx2 = R2->x+R2->w;
    double dy2 = R2->y-R2->h;
    
    double x_left   = max(R1->x, R2->x);
    double y_top    = min(R1->y, R2->y);
    double x_right  = min(dx1, dx2);
    double y_bottom = max(dy1, dy2);
    
    double overlap_width  = x_right - x_left;
    double overlap_height = y_top - y_bottom;
    
    if (overlap_width < 0 or overlap_height < 0) return 0;
    
     return overlap_width * overlap_height;
    
}

int main(){
	Rect R1 = {1,1,5,5};
Rect R2 = {2,2,5,5};	
cout << overlap(&R1,&R2);	
}
