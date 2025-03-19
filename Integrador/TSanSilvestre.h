#include <string> // Include the header file for the String class

struct TSDate{
   int Day;
   int Mounth;
   int Year;
  };
 typedef struct TSDate TDDate;
class TSanSilvestre{
private:
std::string aName; // Use std::string instead of String
TDDate aBirth;
std::string aDeport;
float aRecord[5];

public:
    TSanSilvestre(std::string pName="", std::string pDeport="");
    ~TSanSilvestre();
    
    TDDate GetBirth();
    void SetBirth(TDDate pBirth);
    std::string GetName();
    std::string GetDeporte();
    void SetRecord(int pPos, float pValue);
    float GetRecord(int pPos);
    bool Compare(float pValue);
};