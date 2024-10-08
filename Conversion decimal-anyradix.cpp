#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

void ConversionInt(long double DecimalNumber, int radix) //function for conversion integer part of number
{
   double intpart, fracpart;
   long int x, i, y;
   int number[10];

   fracpart = modf(DecimalNumber, &intpart); //deviding number in frational and integer part 

   for (i = 0; intpart > 0; i++) //algorythm of conversion integer part
   {
      x = floor(intpart / radix);
      y = intpart - x * radix;
      if (y > 9){
         number[i] = y + 55;
      } else {
         number[i] = y;
      }
      intpart = x;
   }

   for (i = i - 1; i >= 0; i--) //loop for printing integer numbers after conversion
   {
      if (number[i] > 9){
         cout << (char)number[i];
      } else {
         cout << number[i];
      }
   }
};

void ConversionFrac(long double DecimalNumber, int radix, int S) // function for conversion fractional part
{
   double x, y, intpart, fracpart;
   long int i, j;
   long int numberfrac[S];

   fracpart = modf(DecimalNumber, &intpart);
   
   for (i = 0; i <= S; i++) //algorythm of conversion fractional part
   {
      y = floor(fracpart * radix);
      if (y > 9){
         numberfrac[i] = y + 55;
      } else {
         numberfrac[i] = y;
      }
      x = fracpart * radix - y;
      
      fracpart = x;
   }

   cout << ".";

   for (i = 0; i < S; i++) //loop for printing fractional numbers in revers order after conversion
   {
      if (numberfrac[i] > 9){
         cout << (char)numberfrac[i];
      } else {
         cout << numberfrac[i];
      }
   }
  
};

double S2(double E_sup, int Tradix) //function for 
{
   double S2;

   S2 = (log(1 / E_sup)) / (log(Tradix));
   S2 = ceil(S2);
   return S2;
};

double S1(double E_sup)
{
   double S1;

   S1 = (log(1 / E_sup)) / (log(10));
   S1 = ceil(S1);
   return S1;
};


int main()
{
   cout << "-------------------------------------------------------------------" << endl;
   cout << "Project: Conversion of numbers" << endl
        << endl;

   double E_sup, S, Sdecimal;
   long double InitialNumber;
   int Tradix;

   cout << "Enter the initial decimal number: ";
   cin >> InitialNumber;
   cout << "Enter radix of the target numeral system: ";
   cin >> Tradix;
   cout << "Required precission of the converted number: ";
   cin >> E_sup;

   
   S = S2(E_sup, Tradix);
   Sdecimal = S1(E_sup);


   cout << "------------------------------------------------------------------- \n THE INITIAL DATA:" << endl;
   cout << "   1.1 The initial decimal number: x_10 = " << fixed << setprecision(Sdecimal) << InitialNumber << endl;
   cout << "   1.2 The radix of the target numeral system: r = " << Tradix << endl;
   cout << "   1.3 The required precission of the coverted number: epsilon_sup = " << scientific << E_sup << fixed << endl;
   cout << "THE RESULTS OF THE CONVERSION:" << endl;
   cout << "   2.1 The required number of the significant numerals s = " << S << endl;
   cout << "   2.2 The result of the conversion: x_" << Tradix << " = ";
   ConversionInt(InitialNumber, Tradix);
   ConversionFrac(InitialNumber, Tradix, S);
   cout << endl << "-------------------------------------------------------------------" << endl;
}
