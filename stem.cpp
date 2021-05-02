#include "stem.h"
using namespace std;


bool Stem::cons(string str, int i){
   switch (str[i]){
      case 'a':
         return false;
	 break;
      case 'e':
         return false;
	 break;
      case 'i':
	 return false;
	 break;
      case 'o':
	 return false;
	 break;
      case 'u':
         return false;
	 break;
      case 'y': 
	 if(i==0) {
            return true;
	 }
         else {
            return false;
	 }
	 break;

      default:
	 return true;
   }
}

int Stem::m(string str) {
   int k = str.length();
   int n = 0;

   for (int i = 1; i < k; i++) {
      if (!cons(str, i-1) && cons(str, i)) n++;
   }
   return n;

}


bool Stem::vowel(string str)
{  int k = str.length();
   
   for (int i = 0; i <= k; i++){
      if(!cons(str, i)){
	 return true;
      }
   }
   return false;
}


bool Stem::cvc(string str,int i)
{  if (i < 2 || !cons(str,i) || cons(str,i-1) || !cons(str,i-2)){
      return false;
   }
   else {
      char c = str[i];
      if (c == 'w' || c == 'x' || c == 'y'){
         return false;
      }
   }
   return true;
}


bool Stem::end(string str, string end) 
{  int k = str.length();
   int e = end.length();
   if (k <= e) return false;
   else if (str.substr(k-e, e) == end) return true;
   else return false;
} 

string Stem::step1ab(string str)
{  int k = str.length();

   if(str[k-1] == 's'){
      if (end(str,"sses")){
         str.replace(k-4, 4, "ss");
      }
      else if (end(str, "ies")){
         str.replace(k-3, 3, "i");
      }
      else if (str[k-2] != 's'){
         str.replace(k-1, 1, "");
      }
   }
   
   else if (end(str,"eed") && m(str)>0) {
      str.replace(k-1, 1, "");
   }

   else if (vowel(str)){
      if (end(str,"ed")) {
         str.replace(k-2, 2, "");
      }
      if (end(str,"ing")) {
         str.replace(k-3, 3, "");
      }
   }


   k = str.length();

   if (end(str,"at")){
         str.replace(k-2, 2, "ate");
   }
   else if (end(str,"bl")) {
       str.replace(k-2, 2, "ble");
   }
   else if (end(str,"iz")) {
	str.replace(k-2, 2, "ize");
   }
   else if (str[k-1]==str[k-2] && str[k-1] != 'l' && str[k-1] != 's' && str[k-1] != 'z'){
     str.replace(k-1, 1, "");
   }

   else if (m(str) == 1 && cvc(str, k-1)){  
	str=str+"e";
   }

   return str;
}

string Stem::step1c(string str)
{  int k = str.length();


   if (str[k-1]=='y' && vowel(str)){
      str[k-1] = 'i';
   }

   return str;
}

string Stem::step2(string str)
{  int k = str.length();
   if (m(str)>0) {

   if (end(str,"ational")) str.replace(k-7, 7, "ate");
   else if (end(str,"tional")) str.replace(k-6,6,"tion");
   else if (end(str,"enci")) str.replace(k-4,4,"ence");
   else if (end(str,"anci")) str.replace(k-4,4,"ance");
   else if (end(str,"izer")) str.replace(k-4,4,"ize");
   else if (end(str,"bli")) str.replace(k-3,3,"ble");
   else if (end(str,"abli")) str.replace(k-4,4,"able");
   else if (end(str,"alli")) str.replace(k-4,4,"al");
   else if (end(str,"entli")) str.replace(k-5,5,"ent");
   else if (end(str,"eli")) str.replace(k-3,3,"e");
   else if (end(str,"ousli")) str.replace(k-5,5,"ous");
   else if (end(str,"ization")) str.replace(k-7,7,"ize");
   else if (end(str,"ation")) str.replace(k-5,5,"ate");
   else if (end(str,"ator")) str.replace(k-4,4,"ate");
   else if (end(str,"alism")) str.replace(k-5,5,"al");
   else if (end(str,"iveness")) str.replace(k-7,7,"ive");
   else if (end(str,"fulness")) str.replace(k-7,7,"ful");
   else if (end(str,"ousness")) str.replace(k-7,7,"ous");
   else if (end(str,"aliti")) str.replace(k-5,5,"al");
   else if (end(str,"iviti")) str.replace(k-5,5,"ive");
   else if (end(str,"biliti")) str.replace(k-6,6,"ble");
   }
   return str;
}

string Stem::step3(string str) 
{  int k = str.length();
   if (m(str)>0) {

   if (end(str,"icate")) str.replace(k-5,5,"ic");
   else if (end(str,"ative")) str.replace(k-5,5,"");
   else if (end(str,"alize")) str.replace(k-5,5,"al");
   else if (end(str,"iciti")) str.replace(k-5,5,"ic");
   else if (end(str,"ical")) str.replace(k-4,4,"ic");
   else if (end(str,"ful")) str.replace(k-3,3,"");
   else if (end(str,"ness")) str.replace(k-4,4,"");
   }
   return str;
}

string Stem::step4(string str)
{  int k = str.length();
  if (m(str)>1) {

   if (end(str,"al")) str.replace(k-2,2,"");
   else if (end(str,"ance")) str.replace(k-4,4,"");
   else if (end(str,"ence")) str.replace(k-4,4,"");
   else if (end(str,"er")) str.replace(k-2,2,"");
   else if (end(str,"ic")) str.replace(k-2,2,"");
   else if (end(str,"able")) str.replace(k-4,4,"");
   else if (end(str,"ible")) str.replace(k-4,4,"");
   else if (end(str,"ant")) str.replace(k-3,3,"");
   else if (end(str,"ement")) str.replace(k-5,5,"");
   else if (end(str,"ment")) str.replace(k-4,4,"");
   else if (end(str,"ent")) str.replace(k-3,3,"");
   else if (end(str,"ion") && (str[k-4] == 's' || str[k-4] == 't')) str.replace(k-3,3,"");
   else if (end(str,"ou")) str.replace(k-2,2,"");
   else if (end(str,"ism")) str.replace(k-3,3,"");
   else if (end(str,"ate")) str.replace(k-3,3,"");
   else if (end(str,"iti")) str.replace(k-3,3,"");
   else if (end(str,"ous")) str.replace(k-3,3,"");
   else if (end(str,"ive")) str.replace(k-3,3,"");
   else if (end(str,"ize")) str.replace(k-3,3,"");
  }
   return str; 
}


string Stem::step5(string str)
{  int k = str.length();

   if (str[k-1] == 'e')
   {   if (m(str) > 1 || (m(str) == 1 && !cvc(str, k-2))) str.replace(k-1,1,"");
   }
  
   else if (m(str) > 1 && end(str, "ll")) str.replace(k-1,1,"");

  return str;

}


string Stem::stem(string str)
{  str = step1ab(str);
   str = step1c(str);
   str = step2(str);
   str = step3(str);
   str = step4(str);
   str = step5(str);
   
   return str;
}

void Stem::inout(string str) {
   int stemmed = 0;
   stringstream iss(str);
   string word;
   
   while (iss >> word) {
   cout << stem(word) << " ";
   if (stem(word) != word) stemmed++;
      
   }

   cout << endl;
   cout << "Number of unique stemmed words: " << stemmed << endl;

}
