#include<iostream>

using namespace std;




#define INT1 int*
typedef int* INT2;


#define COUNT(M) M * M
#define COUNT1(M) (M) * (M)
int main(void)
{
    int a = 5;
    int b = 10;
    //p1&p2's definitions are fine and compatible
    INT1 p1 = &a;
    INT2 p2 = &a;

    /**You can try these two**/
    //INT1 p3,p4 = &b;
    //INT2 p5,p6 = &b;

    //p4 reports error  illegal conversion from int* to int
    //you will find out that the #define is simply a replacement, meaning that the str is replace by the str declared in the macro sentence
    //but the typedef is defining a new type.

    int x = 6;
    cout << "COUNT(6):" << COUNT(6) << endl;
    cout << "COUNT(5 + 1):" << COUNT(5 + 1) << endl;
    cout << "COUNT1(6):" << COUNT1(6) << endl;
    cout << "COUNT1(5 + 1):" << COUNT1(5 + 1) << endl;


    cout << "COUNT(x++):" << COUNT(x++) << endl;

    x = 6;

    cout << "COUNT1(x++):" << COUNT1(x++) << endl;

    x = 6;

    //64?
    cout << "COUNT(++x):" << COUNT(++x) << endl;

    x = 6;
    //64?
    cout << "COUNT1(++x):" << COUNT1(++x) << endl;

    x = 6;
    cout << (++x) * (++x) <<endl;





}