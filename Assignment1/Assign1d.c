/*
* Programmer : Prasanta Dutta
*/

#include<stdio.h> /* Basic IO */
#include<math.h> /* For sqrt, pow */

typedef struct Point{
    int x;
    int y;
}Point;

double dist(Point p1, Point p2){
    return sqrt(pow(p1.x - p2.x,2) + pow(p1.y - p2.y,2));
}

double max(double a, double b,double c){
    double max = a;
    if(b > max)
        max = b;
    if(c > max)
        max = c;
    return max;
}

int main(int argc, char const *argv[])
{
    double side1,side2,side3;
    Point trianglePts[3];
    printf("Enter x, y coordinate of 1st point : ");
    scanf("%i %i",&trianglePts[0].x,&trianglePts[0].y);
    printf("Enter x, y coordinate of 2nd point : ");
    scanf("%i %i",&trianglePts[1].x,&trianglePts[1].y);
    printf("Enter x, y coordinate of 3rd point : ");
    scanf("%i %i",&trianglePts[2].x,&trianglePts[2].y);

    side1 = dist(trianglePts[0],trianglePts[1]);
    side2 = dist(trianglePts[1],trianglePts[2]);
    side3 = dist(trianglePts[2],trianglePts[0]);

    printf("%lf %lf %lf\n",side1,side2,side3);

    double maxSide = max(side1,side2,side3);
    double otherSides[2];

    if(side1 < 0 || side2 < 0 || side3 < 0){
        printf("Invalid Triangle\n");
        return 0;
    }

    if(maxSide == side1){
        otherSides[0] = side2;
        otherSides[1] = side3;
    }
    else if(maxSide == side2){
        otherSides[0] = side1;
        otherSides[1] = side3;
    }
    else{
        otherSides[0] = side1;
        otherSides[1] = side2;
    }

    if(maxSide > otherSides[0] + otherSides[1]){
        printf("InValid Triangle\n");
        return 0;
    }

    printf("%lf %lf %lf\n",maxSide,otherSides[0],otherSides[1]);

    if(otherSides[0] + otherSides[1] == maxSide)
        printf("Right Angled Triangle\n");
    else if(otherSides[0] + otherSides[1] > maxSide)
        printf("Acute Triangle\n");
    else
        printf("Obtuse Triangle\n");    
    return 0;
}
