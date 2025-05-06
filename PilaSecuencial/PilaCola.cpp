//---------------------------------------------------------------------------

#include "PilaCola.h"

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
// Implementaciones
//---------------------------------------------------------------------------

//---------TlistaS ----------------------------------------------------------
TListaS::TListaS(int total)
{
  tamano = total;
  longitud = 0;
  elementos = new void*[tamano];
}

TListaS::~TListaS()
{
  for(int i = 0; i < longitud; i++)
  delete [] elementos;
  longitud = 0;
  tamano = 0;
}

void TListaS::Anadir(void* elementoNuevo)
{
  if (tamano > longitud)
    elementos[longitud] = elementoNuevo;
  else
  {
    if (tamano == longitud)
    {
      tamano *= 2; // duplicar tama�o
      void** nuevoArreglo = new void*[tamano];
      for (int i = 0; i <= longitud - 1; i++) // copiar la primera parte
        nuevoArreglo[i] = elementos[i];
      nuevoArreglo[longitud] = elementoNuevo; // colocar el nuevo elemento
      delete [] elementos;
      elementos = nuevoArreglo;
    }
  }
  longitud++;
}

void* TListaS::Eliminar(int pos)
{
  if ((pos < 0) || (pos >= longitud)) throw EListOutOfRange(); //Posici�n fuera de rango
  void* elementoDevolver = elementos[pos];
  for (int i = pos + 1; i < longitud; i++)
    elementos[i - 1] = elementos[i];
  longitud--;
  return elementoDevolver;
}

//---------PilaSec-----------------------------------------------------------
void TPilaSec :: Anadir(void* elementoNuevo)
{
  TListaS :: Anadir(elementoNuevo);
  primero++;
};

void* TPilaSec :: Primero() const
{
  if (longitud == 0) throw EVacia();
    return elementos[primero];
};

void* TPilaSec :: Eliminar()
{
  if (longitud == 0) throw EVacia();
  void* elementoDevolver = elementos[primero];
  longitud--;
  primero--;
  return elementoDevolver;
};
//---------------------------------------------------------------------------
