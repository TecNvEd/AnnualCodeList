#include<iostream>
#include<list>
#include<iomanip>
#include<vector>
using namespace std;
//G向前(没有则后) H向后(没有则前)
//I后(没有则首位切) 循环链表
//J后

int n,q;
struct Student{
    int id;
    string name;

    Student(int _id,string _name){
        id = _id;
        name = _name;
    }
};
string name, name1, name2,str;
list<Student> stu;
list<Student>::iterator dev;
vector<list<Student>::iterator> iterMap;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    iterMap.resize(2 * n + 2);
    for(int i = 1; i <= n ;i++){
        cin >> name1 >> name2;
        Student s1 = Student(2*(i - 1) - 1, name1);
        Student s2 = Student(2*(i - 1), name2);
        stu.push_back(s1);
        stu.push_back(s2);
    }
    dev = stu.begin();
    for(auto l = stu.begin(); l!= stu.end();l++){
        iterMap[l->id] = l;
    }
    cin >> str;
    for(int i = 0; i < q; i++){
        char c = str[i];
        auto lastIter = stu.end();
        lastIter--;
        if(c == 'K'){
            cout << iterMap[ dev->id % 2 == 1? dev->id + 1 : dev->id - 1]->name << endl;
        }
        else{
            if(c == 'G'){
                if(dev == stu.begin()){
                    dev++; 
                }
                else{
                    dev--;
                }
            }
            else if(c == 'H'){
                if(dev == lastIter){
                    dev--; 
                }
                else{
                    dev++;
                }
            }
            else if(c == 'I'){
                auto tmp = dev;
                Student tmpS = *dev;
                if(dev == lastIter){
                    dev = stu.begin();
                }
                else{
                    dev++;
                }
                stu.erase(tmp);
                stu.push_back(tmpS);
                auto tmpLast = stu.end();
                tmpLast--;
                iterMap[tmpS.id] = tmpLast; 
            }
            else if(c == 'J'){
                auto tmp = dev;
                Student tmpS = *dev;
                if(dev == lastIter){
                    dev = stu.begin();
                }
                else{
                    dev++;
                }
                stu.erase(tmp);
                auto partIter = iterMap[ tmpS.id % 2 == 1? tmpS.id + 1 : tmpS.id - 1];
                partIter++;
                stu.insert(partIter,tmpS);
            }
        }
    }


    for(auto l = stu.begin();l != stu.end(); l++){
        cout << l -> name <<endl;
    }
    
}