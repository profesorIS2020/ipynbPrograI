#include <iostream>
#include "TSanSilvestre.h"
int main(){
    TDDate fecha;
    fecha.Day=10;
    fecha.Mounth=02;
    fecha.Year=1990;
    TSanSilvestre *deportista;
    deportista = new TSanSilvestre("Juan","Atletismo");
    deportista->SetBirth(fecha);
    std::cout << "La fecha de nacimiento del deportista es: " << deportista->GetBirth().Day << ", " << deportista->GetBirth().Mounth << ", " << deportista->GetBirth().Year << std::endl;
    std::cout << "El nombre del deportista es: " << deportista->GetName() << std::endl;
     std::cout << "El deporte es: " << deportista->GetDeporte() << std::endl;
   deportista->SetRecord(0,10.0);
   deportista->SetRecord(1,11.0);
   deportista->SetRecord(2,12.0);
   deportista->SetRecord(3,13.0);
   deportista->SetRecord(4,14.0);
   std::cout << "El record 1 es: " << deportista->GetRecord(0) << std::endl;
   std::cout << "El record 2 es: " << deportista->GetRecord(1) << std::endl;
   std::cout << "El record 3 es: " << deportista->GetRecord(2) << std::endl;
   std::cout << "El record 4 es: " << deportista->GetRecord(3) << std::endl;
   std::cout << "El record 5 es: " << deportista->GetRecord(4) << std::endl;
   std::cout << "El promedio es: " << deportista->Compare(30.5) << std::endl;
   delete deportista;
   return 0;
 }

 

 

