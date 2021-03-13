#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char s;
int  k;
char c;
char uppertolower(char c)
{
    if (c >=65 && c <=90)
    {c = c - 'A' + 'a';}
    else if(c >= 97 && c <= 122)
    {c = c - 'a' + 'A';} 
    return c;
}

void encrymode(char character, int k)
{   
    while(character != '!')
    { if (character >=65 && character <=90)      
        {character = uppertolower(character);       
        character = character + k;
        if(character > 'z')
          {character = character - 'z' + 'a' -1;}
        else if(character < 'a')
          {character = character + 'z' - 'a' +1;}
        cout << character;}
        else if (character >=97 && character <= 122)
        {character = uppertolower(character);
        character = character + k;
        if(character > 'Z')
          {character = character - 'Z' + 'A' -1;}
        else if (character < 'A')
          {character = character + 'Z' - 'A' +1;}
          cout << character;}
      else
        {cout << character;}      
      cin >> character;
    }
}

void decrymode(char character, int k)
{   
    while(character != '!')
    { 
      if (character >=65 && character <=90)      
        {character = uppertolower(character);       
        character = character - k;
        if(character < 'a')
          {character = character + 'z' - 'a' +1;}
        else if (character > 'z')
          {character = character - 'z' + 'a' -1;}
        cout << character;}
            
      else if (character >=97 && character <= 122)
        {character = uppertolower(character);
        character = character - k;
        if(character < 'A')
          {character = character + 'Z' - 'A' +1;}
        else if (character > 'Z')
          {character = character - 'Z' + 'A' -1;}
          cout << character;}
      else
        {cout << character;}
      cin >> character;
    } 
}

char CaesarShift(char c, int k)
{
  while (abs(k)>26)
  {k = k%26;}
  if (s == 'e')
  {encrymode(c, k);}
  else if (s =='d')
  {decrymode(c, k);}
  return '!';
}

int main()
{ cin >> s >> k >> c;
  cout << CaesarShift(c, k) << endl;
   
}