#include<iostream>
using namespace std;
class ResearchPaper{
string *authors;
int size;
public:
ResearchPaper():authors(nullptr),size(0){
}
void add(string author){
    if(authors == nullptr){
        authors = new string[1];
        authors[size++] = author;
        
        return;
    }
    string * temp = new string[size + 1];
    for (int i = 0; i < size; i++)
    {
        temp[i]=authors[i];
    }
    delete[] authors;
    temp[size++] = author;
    authors = temp;

}
void display(){
    for (size_t i = 0; i < size; i++)
    {
        cout<<authors[i]<<" ";
    }
    cout<<endl;
    
}

ResearchPaper(const ResearchPaper& other){
    if(this == &other){
        return;
    }
    size = other.size;
    authors = new string[size];
    for (size_t i = 0; i < size; i++)
    {
        authors[i] = other.authors[i];
    }

}
void operator=(const ResearchPaper&other){

    if(this == &other){
        return;
    }
    if(authors!=nullptr){
        delete[] authors;
    }
    size = other.size;
    authors = new string[size];
    for (size_t i = 0; i < size; i++)
    {
        authors[i] = other.authors[i];
    }

}
~ResearchPaper(){
    if (authors!=nullptr)
    {
        delete[] authors;
    }
    
}
};
int main(){
    ResearchPaper *rp1 = new ResearchPaper;
    rp1->add("a");
    rp1->add("b");
    cout<<"OBJECT 1"<<endl;
    rp1->display();
    ResearchPaper rp2 = *rp1;
    cout<<"OBJECT 2(COPIED)"<<endl;
    rp2.display();
    cout<<"OBJECT 1 DELETED AND OBJECT 2"<<endl;
    delete rp1;
    rp2.display();
    cout<<"THIS IS INDEPENDENCY"<<endl;

    cout<<"========================"<<endl;
    ResearchPaper *rp = new ResearchPaper;
    rp->add("x");
    rp->add("y");
    ResearchPaper rp3;
    cout<<"OBJECT 1"<<endl;
    rp->display();
    rp3 = *rp;
    cout<<"OBJECT 2 COPIED BY OBJECT 1"<<endl;
    rp3.display();
    delete rp;
    cout<<"OBJECT 1 DELETED AND OBJECT 2:"<<endl;
    rp3.display();
    cout<<"THIS IS INDEPENDENCY"<<endl;



    

}