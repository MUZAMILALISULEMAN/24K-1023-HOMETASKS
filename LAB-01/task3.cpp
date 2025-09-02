#include<iostream>
using namespace std;
class Exam{
public:
int *marks;
public:
Exam(int marks=0){
    this->marks = new int(marks);
}
void show(){
    cout<<"MARKS: "<<*marks<<endl;
}
~Exam(){
    delete marks;
}
};
int main(){
Exam *one = new Exam(100);
Exam two = *one;

cout<<"FIRST: ";
one->show();
cout<<"SECOND: ";
two.show();
cout<<"FIRST UPDATED: "<<endl;
*one->marks = 300;
// see change in two;
cout<<"SECOND: ";
two.show();
cout<<"SECOND IS AFFECTED BY UPDATION OF FIRST";


// delete one;
// two.show();
 //dangling pointer issue;







    return 0;
}