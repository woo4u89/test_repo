#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::cin;
using std::endl;
using std::string;

class checkPesel 
{
    private:
    const int64_t _pesel;
    int _psl[11];
    bool valid;
    const int w_k[11] = {1,3,7,9,1,3,7,9,1,3,1};

  public:
    checkPesel(int64_t const &pesel) : _pesel(pesel) 
    {
        setPsl();
    }
    //void setPesel(int64_t &pesel);
    void getPesel() const;
    void setPsl();
    bool checkSum();
};

void checkPesel::setPsl()
{
    int64_t temp = _pesel;
  for (int i=10; i >= 0; --i)
    { 
      _psl[i] = temp % 10;
      temp/=10;
      //cout << "psl[" << i << "]" << _psl[i] << endl;
     }
}

bool checkPesel::checkSum () 
{  
  valid = false;
  int _temp = 0;
  int c_11 = 0;
  for (int i = 0; i < 10 ;++i)
    {
      _temp = _temp + (_psl[i] * w_k[i]);
    }
    
    c_11 = ((_temp % 10) == 0) ? 0 : 10 - (_temp % 10);
    
  if (_psl[10] == c_11)
     {
        valid = true;
        cout << "The control digit is equal to " << c_11 << " and corresponds to the last PESEL digit." << endl;
     } 
  else 
    {
        cout << "The control digit is equal to " << c_11 << " and does not corresponds to the last PESEL digit." << endl;
    }
return valid;
}

void checkPesel::getPesel () const
{
int year =0, month=0, day=0;
string gender, validity;

   std::map <int, string>::iterator it;
   std::map <int, string> months = 
    {
    {1,"January"}, {2,"February"}, {3,"March"},
    {4,"April"}, {5,"May"}, {6,"June"},
    {7,"July"}, {8,"August"}, {9,"September"},
    {10,"October"}, {11,"November"}, {12,"December"} 
    };


if (_psl[2] < 2)
  {
    year = 1900 + 10*_psl[0] + _psl[1];
    month = 10*_psl[2] + _psl[3];
  }
else 
  {
    year = 2000 + 10*_psl[0] + _psl[1];
    month = (10*_psl[2] - 20) + _psl[3];
  }
  day = 10*_psl[4] + _psl[5];
  gender = (_psl[9] % 2 == 0) ? "Female" : "Male"; 
  
  validity = (valid) ? "PESEL number is correct." : "PESEL number is incorrect.";

  cout << "Date of birth: " << day << " " << months.find(month)->second << " " << year << endl;
  cout << "Gender: " << gender << endl; 
  cout << validity;

}


int main()
{
  int64_t pesel;
  bool chk = false;

  cout << "Enter PESEL number:" << endl;
  cin >> pesel;
  
  checkPesel a(pesel);
  //a.setPesel(pesel);
  a.checkSum();
  a.getPesel();

return 0;
}

