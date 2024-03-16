#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

class Calendar{
      
    public: 
        int mes, year, dia;

        Calendar(int, int, int);

        bool calc_bisiesto(int year){
            if(year%400==00 || (year%100!=0 && year%4 == 0))
                return true;
            
            else
                return false;
        } 
        int finDeMes(int mes){
            int dias[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if(mes==2 && calc_bisiesto(year))
                return 29;
            else
                return dias[mes];

}
};







int main(){
    string nom_dias[7] = {"L","M","M","J", "V", "S", "D"};
    string nom_mes[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"}; 
    

    Calendar cal(0,0,0);
    int mes, year;
    cout<<"Ingrese un año"<<endl;
    cin>>cal.year;
    cout<<"Ingrese un mes"<<endl;
    cin>>cal.mes;



    
    for(int i = 0; i <7 ; i++){
        cout << nom_dias[i] << setw(4);
    }
    cout << endl;
    for(int j = 1; j <31; j++){
        cout << j << setw(4);
        nom_dias[0+j];
        cout << endl;
    }
    


    


};