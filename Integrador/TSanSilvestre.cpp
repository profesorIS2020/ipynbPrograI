#include <string> // Include the header file for the String class
#include "TSanSilvestre.h"
/**Implementación de las funciones miembros*/

TSanSilvestre::TSanSilvestre(std::string pName,std::string pDeport){
  aName=pName;
  aDeport=pDeport;
  for (int i=0; i<5; i++)
    aRecord[i]=0.0;
    aBirth.Day=0;
    aBirth.Mounth=0;
    aBirth.Year=0;
}

TSanSilvestre::~TSanSilvestre(){}


TDDate TSanSilvestre::GetBirth(){
 TDDate temporal;
 temporal.Day = aBirth.Day;
 temporal.Mounth = aBirth.Mounth;
 temporal.Year = aBirth.Year;
 return temporal;
}
void TSanSilvestre::SetBirth(TDDate pBirth){
 aBirth.Day=pBirth.Day;
 aBirth.Mounth=pBirth.Mounth;
 aBirth.Year=pBirth.Year;
}

std::string TSanSilvestre::GetName(){
  return aName;
}
std::string TSanSilvestre::GetDeporte(){
    return aDeport;
}

float TSanSilvestre::GetRecord(int pPos){
    return aRecord[pPos];
}
void TSanSilvestre::SetRecord(int pPos, float pValue){
    aRecord[pPos] = pValue;
}

bool TSanSilvestre::Compare(float pValue){
  float sum=0.0;
  float prom;
  int cont=0;
  for (int i=0; i<5; i++){
    if (aRecord[i] != 0.0){
       sum+=aRecord[i];
       cont++;
     }
    if ( cont>0 )
       prom=sum/cont;
   }
  if(pValue > prom)
    return true;
  else
    return false;
}

/*
void TSanSilvestre::SetName(std::string pName){
    aName = pName;
}
void TSanSilvestre::SetDeport(std::string pDeport){
  aDeport=pDeport;
}


*/
 

 