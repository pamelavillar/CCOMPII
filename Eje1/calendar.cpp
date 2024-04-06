#include <array>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Calendar {

public:
  int mes, year, dia;

  Calendar(int y, int m, int d) {
    year = y;
    mes = m;
    dia = d;
  }

  bool calc_bisiesto(int year) {
    if (year % 400 == 00 || (year % 100 != 0 && year % 4 == 0))
      return true;

    else
      return false;
  }
  int finDeMes(int mes) {
    int dias[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && calc_bisiesto(year))
      return 29;
    else
      return dias[mes];
  }

  int dia_mes2(int year, int mes) { // BASADO EN EL METODO DE SAKAMOTO
    int dia_mes[12] = {0, 3, 3, 6, 1, 4,
                       6, 2, 5, 0, 3, 5}; // en base a Lunes 1 , 1 dC.
                                          //   an array of the leading number of
                                          //   days for each month -> enero 31
                                          //   dias = 7*4+(3),
    int desfase_anual = year;

    if (mes < 3 && calc_bisiesto(year)) {
      year -= 1;
    } // Se entiende pues que para enero y febrero no se añade el desfase
      // causado por el actual año bisiesto, entonces se mantiene el desfase del
      // año pasado

    int bisiestos = year / 4 - year / 100 + year / 400;

    return (desfase_anual + bisiestos + dia_mes[mes - 1]) % 7;
  }
};

int main() {
  string nom_dias[7] = {"D", "L", "M", "M", "J", "V", "S"};
  string nom_mes[12] = {"Enero",      "Febrero", "Marzo",     "Abril",
                        "Mayo",       "Junio",   "Julio",     "Agosto",
                        "Septiembre", "Octubre", "Noviembre", "Diciembre"};

  Calendar cal(0, 0, 0);

  int re = 1;
  while (re) {
    cout << "Ingrese un año" << endl;
    cin >> cal.year;
    cout << "Ingrese un mes" << endl;
    cout << "1.Enero, 2.Febrero, 3.Marzo, 4.Abril, 5.Mayo, 6.Junio, 7.Julio, "
            "8.Agosto,     9.Septiembre, 10.Octubre, 11.Noviembre, 12.Diciembre"
         << endl;

    cin >> cal.mes;

    cout << "\n----------" << nom_mes[cal.mes - 1] << " " << cal.year
         << "----------" << endl;

    for (int i = 0; i < 7; i++) {
      cout << setw(4) << nom_dias[i];
    }
    cout << endl;

    int actual = cal.dia_mes2(cal.year, cal.mes);

    for (int i = 0; i < actual; i++) {
      cout << setw(4) << " ";
    }

    for (int i = 1; i <= cal.finDeMes(cal.mes); i++) {
      cout << setw(4) << i;

      if (actual == 6) {
        cout << endl;
        actual = 0;
      } else
        actual += 1;
    }

    cout << "\n\nDesea calcular otro mes y año?: 1.Si, 0.No ----->";
    cin >> re;
  }
}