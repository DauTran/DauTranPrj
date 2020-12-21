#include<iostream>
#include "Dept_locations.h"
using namespace std;

// Default Contructor
Dept_locations::Dept_locations(){}
// Contructor with paramaters
Dept_locations::Dept_locations(int id, int dNumber,std::string dLocation){
    Id = id;
    Dnumber =dNumber;
    Dlocation =dLocation;
}

void  Dept_locations::deleteTable(Dept_locations Arr[], int n, int position){
   for(int i=position; i<n; ++i){
      Arr[i].Id = Arr[i+1].Id - 1; 
      Arr[i].Dnumber = Arr[i+1].Dnumber;
      Arr[i].Dlocation = Arr[i+1].Dlocation ;
   }

}

void Dept_locations::InitArr(Dept_locations Arr[], int n){
    
    // cout<<"id   "<<"Dnumber "<<"Dlocation"<<endl;
    for(int i=0; i<n; ++i){
        Arr[i].Id = i;
        Arr[i].Dnumber = i;
        Arr[i].Dlocation = "";
    }
}

void Dept_locations::show(Dept_locations Arr[],int n){

  for(int i=0; i<n; ++i){
        cout<<Arr[i].Id<<"\t";
        cout<<Arr[i].Dnumber<<"\t";
        cout<<Arr[i].Dlocation<<endl;
    }
}

int main(){
    int n = 10;
    Dept_locations Arr1[n];
    Dept_locations B;
    B.InitArr(Arr1, n);
     B.show(Arr1, n);
    cout<<"endl "<<endl;
    B.deleteTable(Arr1, n, 2);
    B.show(Arr1, n);

 


    return 0;
}









// #include<vector>
// typedef vector<Dept_locations> Dept_locations_type;

//  vector<Dept_locations_type> A;
//         A.resize(n);

//     for(int i=0; i<A.size(); ++i){
//         A[i].resize(3);
//     }

//     // Khoi tao gia tri ban dau de test

//     for(int i=0; i<A.size(); ++i){
//         for(int j=0; j<A[i].size(); ++j){
//             A[i][j] =   
//         }
//     }


