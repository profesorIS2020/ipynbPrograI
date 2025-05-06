//---------------------------------------------------------------------------

#ifndef PilaColaH
#define PilaColaH

//-------Clases para lanzar excepciones-------------------------------------
class EListException{};
class EListOutOfMemory : public EListException{};
class EListOutOfRange : public EListException{};
class EVacia : public EListException{};

//-------Clases Abstractas--------------------------------------------------
class TListaS
{
public:
  TListaS(int);
  ~TListaS();
  void Anadir(void*);
  void* Eliminar(int);
  int Longitud(){return longitud;}
  bool Vacia(){return !longitud;}
protected:
  int longitud;
  int tamano;
  void** elementos;
};



class TPilaSec : public TListaS
{
public:
  TPilaSec(int valor) : TListaS(valor){primero = -1;}
  ~TPilaSec(){};
  void Anadir(void*);
  void* Primero()const;
  void* Eliminar();
  int Longitud(){return longitud;}
  bool Vacia(){return !longitud;}
protected:
  int primero;
private:
};


//---------------------------------------------------------------------------
#endif
 