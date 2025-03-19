
#include "TArrayInt.h"
#include <iostream>

TArrayInt::TArrayInt(int length){

   if ((length >0)&&(length<=Max_Length)){

     Flength = length;

     for (int i=0; i<Flength; i++)

      FArray[i]=0;

    } else Flength=0;

  }
TArrayInt::TArrayInt(){}

TArrayInt::~TArrayInt() {
    // Destructor implementation
}

void TArrayInt::SetArray (int Array[]){

    for (int i=0; i<Flength;i++)

    FArray[i]=Array[i];

  }

  int TArrayInt::GetElement(int index){

    return FArray[index];

   }

   void TArrayInt::SetElement(int index,int valor){

   FArray[index]=valor;

  }

  TArrayInt TArrayInt::GetArray()

     {

        TArrayInt c(Flength);

        for (int i=0; i<Flength;i++)

           c.FArray[i]=FArray[i];

         return c;

  }

 void TArrayInt::SetLength(int length) {

   Flength = length;

  }

  int TArrayInt::GetLength()

  {

   return Flength;

  }

 
int TArrayInt::Sum()

  {

   int result=0;

   for (int i=0; i<Flength;i++)

    result += FArray[i];

   return result;

  }

  float TArrayInt::Average()
  {
   float result;
   if (Flength >0)
    {
      result=Sum();
      result = result/Flength;
    }
    else
     result=0;
   return result;
  }



 int TArrayInt::CountZeros(){

   int result=0;

    for (int i=0; i<Flength;i++)

    if (FArray[i]==0) ++result;

   return result;

  }

 

 bool TArrayInt::IsEmpty(){

   bool result=false;

   if (Flength == 0) result=true;

   return result;

  }



 bool TArrayInt::IsFull(){

   bool result=false;

   if (Flength == Max_Length) result=true;

   return result;

  }

  bool TArrayInt::InsertLast(int value)
  {
   bool result;
   if (IsFull()==true) {result=false;}
    else
     {
      Flength++;
      FArray[Flength-1] = value;
      result = true;
     }
  return result; 
}


 
 