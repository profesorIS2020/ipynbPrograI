//---------------------------------------------------------------------------

#ifndef EstructurasH
#define EstructurasH
//---------------------------------------------------------------------------
//------------Clases para lanzar Excepciones --------------------------------
class EListException{};
class EListOutOfRange : public EListException{};
//------------Clase TListaNumerosEnterosSeq -----------------------------------------------
class TListaNumerosEnterosSeq
{
public:
  TListaNumerosEnterosSeq(int);
  TListaNumerosEnterosSeq(int, int);
  ~TListaNumerosEnterosSeq ();
  void Anadir(int);
  int Eliminar(int);
  void Insertar(int, int);
  int Longitud(){return longitud;}
  int Obtener(int);
  bool Vacia(){return !longitud;}
protected:
  int longitud;
  int tamano;
  int* elementos;
};
//---------------------------------------------------------------------------
#endif
