#include<iostream>
using namespace std;
class Box{
int *volume;
public:
Box(){
    volume = new int(0);
}
Box(int volume){
    this->volume = new int(volume);
}
void update(int vol){
    *volume = vol;
}
void print(){
    cout<<"VOLUME = "<<*volume<<endl;
}
Box(const Box &other){
if(this == &other) return;
volume = new int(*other.volume);
}

};
int main(){

Box b1;
Box b2(100);
Box b3 = b2;
cout<<"OBJECT 1, ";
b2.print();
cout<<"OBJECT 2, ";
b3.print();
cout<<"OBJECT 2 UPDATED, ";
b3.update(200);
b3.print();
cout<<"OBJECT 1 NOW,  ";
cout<<"NO CHANGE TO OBJECT ONE"<<endl;

    return 0;
}