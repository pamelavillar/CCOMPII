#include <iostream>
#include <array>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
// Apartir de 3999, se añade una linea encima del numero romano millar, indicando que el numero se multiplica por 1000
// 3999 -> MMMCMXCIX
//4000 -> CM (con una linea encima)
// 50->L ; 100->C; 500->D; 1000->M
//390 -> CCXC
//400 -> CD
//440 -> CDXL


void try0(int n,int s,vector<string>& romano){
    array <string, 7> basics = {"I","V","X", "L", "C", "D", "M"};
    array <int, 7> basicsN= {1,5,10,50,100,500,1000};
    s-=1;

    if (n==0){
        return;
    }


    for (int i=0; i<7;i++){ //-> IV, IX, XL
        if (basicsN[i]==n*pow(10,s)){
            romano.push_back(basics[i]);
            return;
        }
        else if (basicsN[i]==(n*pow(10,s))+pow(10,s)){//10 = 9*1 + 1 -> IX // 50 [3]= 4*10 + 10 -> XL
            romano.push_back(basics[s*2]+basics[i]);
            return;
        }
    }

    if (n<4){
        for(int j=0; j<n;j++){
            romano.push_back(basics[s*2]);
        }
        return;
    }
    else if(n>5){
        string aux;
        aux+=basics[s*2+1];
        for(int k=0; k<n-5;k++){
            aux+=basics[s*2];
        }
        romano.push_back(aux);
        return;
    }
   
}

int main(){
    int nu;
    cout<<"ingrese un numero: ";
    cin>>nu;
    int s=1;//comienza con 1=unidades, 2=decenas, 3=centenas, 4=millar
    vector<string>romano;
       
    while(nu>0){
        if (s>=4 && nu==4){//este caso es porque apartir del 3999, el millar se multiplica, 
                  //entonces es como hacer borron y cuenta nueva xd, esta arriba explicado :b
            s=1;
            romano.push_back("-");
            try0(nu%10,s,romano);
            nu=nu/10;
            s++;
        }
        try0(nu%10,s,romano);
        nu=nu/10;
        s++;//aumenta de unidades, a decenas,a centenas ...
    }

    for(int i = romano.size()-1;i>=0; i--){
        cout<<romano[i];
    }
    

};
