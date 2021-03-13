#include <iostream>
#include <string>
using namespace std;
double x,y,width,height,radius;
char poly;
int n;
double xp,yp;
double xmin_r = NULL, xmax_r = NULL, ymin_r = NULL, ymax_r = NULL;
double xmin_c = NULL, xmax_c = NULL, ymin_c = NULL, ymax_c = NULL;
double xmin_p = NULL, xmax_p = NULL, ymin_p = NULL, ymax_p = NULL;
double local_xmin_r = NULL, local_xmax_r = NULL, local_ymin_r = NULL, local_ymax_r = NULL;
double local_xmin_c = NULL, local_xmax_c = NULL, local_ymin_c = NULL, local_ymax_c = NULL;
double local_xmin_p = NULL, local_xmax_p = NULL, local_ymin_p = NULL, local_ymax_p = NULL;
void RectangleBB(double &xmin, double &xmax, double &ymin, double &ymax)
    {   if (local_xmin_r != NULL && local_xmax_r != NULL && local_ymin_r != NULL && local_ymax_r != NULL) 
            {if (local_xmin_r > xmin)
                {local_xmin_r = xmin;}
            if (local_xmax_r < xmax)
                {local_xmax_r = xmax;}
            if (local_ymin_r > ymin)
                {local_ymin_r = ymin;}
            if (local_ymax_r < ymax)
                {local_ymax_r = ymax;}}
        else
            {local_xmin_r = xmin, local_xmax_r = xmax, local_ymin_r = ymin, local_ymax_r = ymax;}        
        xmin = local_xmin_r;
        xmax = local_xmax_r;
        ymin = local_ymin_r;
        ymax = local_ymax_r;
    }

void CircleBB(double &xmin, double &xmax, double &ymin, double &ymax)
    {   if (local_xmin_c != NULL && local_xmax_c != NULL && local_ymin_c != NULL && local_ymax_c != NULL)
            {if (local_xmin_c > xmin)
                {local_xmin_c = xmin;}
            if (local_xmax_c < xmax)
                {local_xmax_c = xmax;}
            if (local_ymin_c > ymin)
                {local_ymin_c = ymin;}
            if (local_ymax_c < ymax)
                {local_ymax_c = ymax;}}
        else  
        {local_xmin_c = xmin, local_xmax_c = xmax, local_ymin_c = ymin, local_ymax_c = ymax;}
        xmin = local_xmin_c;
        xmax = local_xmax_c;
        ymin = local_ymin_c;
        ymax = local_ymax_c;
    }

void PointSetBB(double &xmin, double &xmax, double &ymin, double &ymax)
    {   if (local_xmin_p != NULL && local_xmax_p != NULL && local_ymin_p != NULL && local_ymax_p != NULL)
            {if (local_xmin_p > xmin)
                {local_xmin_p = xmin;}
            if (local_xmax_p < xmax)
                {local_xmax_p = xmax;}
            if (local_ymin_p > ymin)
                {local_ymin_p = ymin;}
            if (local_ymax_p < ymax)
                {local_ymax_p = ymax;}}
        else 
            {local_xmin_p = xmin, local_xmax_p = xmax, local_ymin_p = ymin, local_ymax_p = ymax;}
        xmin = local_xmin_p;
        xmax = local_xmax_p;
        ymin = local_ymin_p;
        ymax = local_ymax_p;
    }




double decide_max(double a, double b, double c)
    {   

        double temp ;
        if (a == NULL && b ==NULL)
            {return c;}
        if (b == NULL && c == NULL)
            {return a;}
        if (a == NULL && c == NULL)
            {return b;}
        temp = a;
        if (b > temp)
            {temp = b;}
        if (c > temp)
            {temp = c;}
        return temp;
    }

double decide_min(double a, double b, double c)
    {   
        double temp;
        if (a == NULL && b ==NULL)
            {return c;}
        if (b == NULL && c == NULL)
            {return a;}
        if (a == NULL && c == NULL)
            {return b;}
        temp = a;
        if (temp > b)
            {temp = b;}
        if (temp > c)
            {temp = c;}
        return temp;
    }

int main()
{    poly = NULL ;
     while(poly != '#')
     {  cin >> poly;
         if (poly == 'R')
         {cin >> x >> y >> width >> height;
          xmin_r = x - (width/2);
          xmax_r = x + (width/2);
          ymin_r = y - (height/2);
          ymax_r = y + (height/2);
          RectangleBB(xmin_r, xmax_r, ymin_r, ymax_r);}
         if (poly == 'C')
         {cin >> x >> y >> radius;
          xmin_c = x - radius;
          xmax_c = x + radius;
          ymin_c = y - radius;
          ymax_c = y + radius;
          CircleBB(xmin_c, xmax_c, ymin_c, ymax_c);}
         if (poly == 'P')
         {cin >> n;
          for (int i=0;i<n;i++)
          { cin >> xp >> yp;
            xmin_p = xp;
            xmax_p = xp;
            ymin_p = yp;
            ymax_p = yp;
            PointSetBB(xmin_p, xmax_p, ymin_p, ymax_p);
          }
         }
    }


double xmax, xmin ,ymax, ymin;
xmax = decide_max(xmax_r, xmax_c, xmax_p);
xmin = decide_min(xmin_r, xmin_c, xmin_p);
ymax = decide_max(ymax_r, ymax_c, ymax_p);
ymin = decide_min(ymin_r, ymin_c, ymin_p);

double xmid = (xmin + xmax)/2;
double ymid = (ymin + ymax)/2;
double width = xmax -xmin;
double height = ymax - ymin;
cout << xmid << " " << ymid << " " << width << " " << height ;

}