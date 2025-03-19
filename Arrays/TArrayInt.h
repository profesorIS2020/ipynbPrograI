#define Max_Length 30


class TArrayInt{
private:
  int Flength;
  int FArray[Max_Length];
 public:
  TArrayInt(int length);
  TArrayInt();
  ~TArrayInt();
  void SetArray (int Array[]);
  TArrayInt GetArray();
  void SetElement(int index,int valor);
  int GetElement(int index);
  int GetLength();
  void SetLength(int length); 
  int Sum();
  float Average();
  int CountZeros();
  bool IsEmpty();
  bool IsFull();
  bool InsertLast(int value);
 };

 // Path: TArrayInt.cpp
