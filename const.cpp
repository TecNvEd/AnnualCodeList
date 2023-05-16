#include<iostream>

using namespace std;


//const 修饰全局变量
const int GlobalPos = 0;
const static int Version = 1.0;

class A{
    private:
        const int a;
    public:
        int getValue();//普通成员函数
        int getValue() const;//常成员函数 不得修改类中对象的值
};
int main(void)
{
    //使用const来修饰变量时 必须亚要同步进行初始化 不然无意义
    //这两种const都是将用来指明num是一个常变量

    int normal = 1;

    const int num = 5;
    int const num1 = 5;
    //const 修饰静态常量字符串
    const char* str = "techdreamer";

    //const 修饰常量指针
    //此处的const表示 不能通过iPointer来修改num的值 但是你还是可以直接修改num自己的值
    const int* iPointer = &normal;

    //同时 虽然不能通过const修饰的指针来修改对应变量的值
    //但是仍然可以修改指针所指向的对象
    iPointer = &num;


    //const 修饰指针常量
    //这种情况下 指针不能再指向其他的地址
    //但是可以通过指针来修改num
    int* const iPointer1 = &normal;





    //上述两种情况的交集
    //指向常量的常指针
    const int* const iPointer2 = &normal;



    //形参中给source 加入const修饰 确保了不能在函数体内部修改source
    void fun(char* dest, const char* source);

    //p1 p2 指向的地址都不能修改
    void fun1(int* const p1, int* const p2);
    
    //例子 库文件中函数声明
    size_t strlen(const char* str);
    int strcmp(const char* str1, const char* str2);
    char* strcat(char* destination, const char* source);
    char* strcpy(char* destination, const char* source);
    int system(const char* command);
    int puts(const char* str);
    int printf(const char* format);


    //给函数的返回值进行const修饰
    //确保了后续接收函数的返回值为const类型 确保其不能被修改
    const char* funn(void);
    const char* ccc = funn();




    int* const funcn(void);
    int* const aaa = funcn();










}
const char* funn(void){const char* a = "1212";return a;};
int* const funcn(void){int aaa; int* const a = &aaa;return a;};