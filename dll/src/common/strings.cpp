#include "common.h"

#pragma warning(push, 0)
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <iterator>
#include <vector>
#include <set>
#include <regex>
#pragma warning(pop)

// trim from start
inline std::string ltrim( std::string s )
{
  s.erase( s.begin(), std::find_if( s.begin(), s.end(), std::not1( std::ptr_fun<int, int>( std::isspace ) ) ) );
  return s;
}

// trim from end
inline std::string rtrim( std::string s )
{
  s.erase( std::find_if( s.rbegin(), s.rend(), std::not1( std::ptr_fun<int, int>( std::isspace ) ) ).base(), s.end() );
  return s;
}

// trim from both ends
inline std::string trim( std::string s )
{
  return ltrim( rtrim( s ) );
}

struct case_insensitive_less : public std::binary_function< char, char, bool >
{
  bool operator () ( char x, char y ) const
  {
    return toupper( static_cast< unsigned char >( x ) ) <
           toupper( static_cast< unsigned char >( y ) );
  }
};

bool caseless_compare( const std::string& a, const std::string& b )
{
  return std::lexicographical_compare( a.begin(), a.end(),
                                       b.begin(), b.end(), case_insensitive_less() );
}

EXPORT int sort_char_array_all( char* array[], int array_len )
{
  return sort_char_array( array, 1, array_len );
}

EXPORT int sort_char_array( char* array[], int start_pos, int end_pos )
{
  //first copy input array to a vector
  std::vector<std::string> string_vector;
  string_vector.reserve( end_pos - start_pos + 1 );
  for ( int i = start_pos - 1; i <= end_pos - 1; ++i )
  {
    std::string val = std::string( array[i] );
    string_vector.push_back( rtrim( val ) );
  }

  //now sort vector
  std::sort ( string_vector.begin(), string_vector.end(), caseless_compare );

  //and copy back to array
  int vector_idx = 0;
  for ( int i = start_pos - 1; i <= end_pos - 1; ++i )
  {
    strcpy_s( array[ i ], 32000, string_vector[vector_idx].c_str() );
    vector_idx++;
  }

  return 1;
}
