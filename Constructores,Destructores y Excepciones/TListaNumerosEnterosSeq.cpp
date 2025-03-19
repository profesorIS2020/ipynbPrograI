//---------------------------------------------------------------------------



#include "TListaNumerosEnterosSeq.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
// ListaNumerosEnterosSeq
//---------------------------------------------------------------------------
TListaNumerosEnterosSeq::TListaNumerosEnterosSeq(int total)
{
  tamano = total;
  longitud = 0;
  elementos = new int[tamano];
}

TListaNumerosEnterosSeq::TListaNumerosEnterosSeq(int nuevoElemento, int total)
{
  tamano = total;
  elementos = new int[tamano];
  elementos[0] = nuevoElemento;
  longitud = 1;
}

TListaNumerosEnterosSeq::~TListaNumerosEnterosSeq()
{
  delete [] elementos;
  longitud = 0;
  tamano = 0;
}

void TListaNumerosEnterosSeq::Anadir(int elementoNuevo)
{
  if (tamano > longitud)
     elementos[longitud] = elementoNuevo;
  else
  {
    if (tamano == longitud)
    {
      tamano *= 2; // duplicar tama�o
      int* nuevoArreglo = new int[tamano];
      for (int i = 0; i <= longitud - 1; i++) // copiar la primera parte
        nuevoArreglo[i] = elementos[i];
      nuevoArreglo[longitud] = elementoNuevo; // colocar el nuevo elemento
      delete [] elementos;
      elementos = nuevoArreglo;
    }
  }
  longitud++;
}

int TListaNumerosEnterosSeq::Eliminar(int pos)
{
  if ((pos < 0) || (pos >= longitud)) throw EListOutOfRange(); //Posici�n fuera de rango
  int elementoDevolver = elementos[pos];
  for (int i = pos + 1; i < longitud; i++)
    elementos[i - 1] = elementos[i];
  longitud--;
  return elementoDevolver;
}

void TListaNumerosEnterosSeq::Insertar(int nuevoElemento, int pos)
{
  if (pos < 0 || pos >= longitud) throw EListOutOfRange();
  if (tamano == longitud) // factor de carga es 1
  {
    tamano *= 2; // Duplicar el tama�o del arreglo
    int* nuevoArreglo = new int[tamano];
    for (int i = 0; i < pos; i++) // copiar la primera parte
      nuevoArreglo[i] = elementos[i];
    nuevoArreglo[pos] = nuevoElemento; // colocar el nuevo elemento
    for (int i = pos + 1; i < longitud + 1; i++) // copiar la segunda parte
      nuevoArreglo[i] = elementos[i - 1];
    delete [] elementos;
    elementos = nuevoArreglo;
  }
  else
  {// factor de carga es < 1
    for (int i = longitud; i > pos; i--)
      elementos[i] = elementos[i - 1];
    elementos[pos] = nuevoElemento;
  }
  longitud++;
}

int TListaNumerosEnterosSeq::Obtener(int pos)
{
 if ((pos < 0) || (pos >= longitud)) throw EListOutOfRange(); //Posici�n fuera de rango
 return elementos[pos];
}




