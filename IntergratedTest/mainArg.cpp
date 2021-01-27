#include <iostream>

using namespace std;

void TestPointer(int** p){
    int b =2;
    // cout<<"Dia chi cua a "<<a<<endl;
    cout<<"Gia tri cua p "<<p<<endl; //p giu dia chi cua con tro pa
    cout<<"Dia chi cua p "<<&p<<endl;
    cout<<"Gia tri cua dia chi p dang giu: "<<(*p)<<endl;
    // cout<<"Gia tri cua dia chi p dang giu: "<<(&pa)<<endl;


}

int main(int  arg, char** argv)
{

    int a  = 10;
    int* pa = &a;
    // cout<<"Dia chi cua a "<<&a<<endl;
    cout<<"Gia tri cua pa "<<pa<<endl; 
    cout<<"Dia chi cua pa "<<&pa<<endl<<endl;

    TestPointer(&a);
    // cout<<"Dia chi cua con tro sau khi test pa "<<a<<endl;

    return 0;
}