
#ifndef STRING_INCLUDED 
#define STRING_INCLUDED 1

#include <iostream> 
#include <cstring>

struct string
{
   size_t len;
   char *p; 

   string( )
   {
      len = 0;
      p = new char[0];
   }

   string( const string& s ) 
   {
      len = s. len;
      p = new char[ len ];
      for( size_t i = 0; i != len; ++ i )
         p[i] = s.p[i];
   }

   string( const char* c )
   {
      std::cout << "constructing: " << c << "\n";
      len = strlen(c);
      p = new char[len];
      for( size_t i = 0; i != len; ++ i )
         p[i] = c[i];
   }

   ~string( )
   {
      delete[] p;  
   }
};

#endif

