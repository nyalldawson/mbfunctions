#include "common.h"

#pragma warning(push, 0)
#include <regex>
#pragma warning(pop)

bool validateExpression( std::string e )
{
  if ( e.empty() )
  {
    return false;
  }
  try
  {
    std::tr1::regex( e );
    return true;
  }
  catch ( ... )
  {
    return false;
  };
}

EXPORT int regex_test( char* cInput, char* cMatch )
{
  // recast input char to string
  std::string sInput = std::string( cInput );

  // setup regex
  std::tr1::regex rx( cMatch );

  // do search
  if ( regex_search( sInput, rx ) )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

EXPORT const char* regex_match( char* cInput, char* cMatch )
{
  // recast input char to string
  std::string sInput = std::string( cInput );

  // setup regex
  std::tr1::regex rx( cMatch );
  std::tr1::smatch mResults;

  // run search
  if ( regex_search( sInput, mResults, rx ) )
  {
    // convert boost::sub_match to string
    std::string sMatch = std::string() + mResults.str( 1 );
    char* cmatch = new char [sMatch.length() + 1];
    strcpy_s( cmatch, sMatch.length() + 1, sMatch.c_str() );
    return cmatch;
  }
  else
  {
    return ( char* )"";
  }
}

EXPORT int regex_match_multiple( char* cInput, char* cMatch, char* cMatches[] )
{
  // recast input char to string
  std::string sInput = std::string( cInput );

  if ( !validateExpression( std::string( cMatch ) ) )
  {
    return -1;
  }

  // setup regex
  std::tr1::smatch mResults;
  std::tr1::regex rx( cMatch );

  // run search
  if ( regex_search( sInput, mResults, rx ) )
  {
    // note first match in mResults is entire matched string, which we don't want
    // so start at 1
    for ( unsigned int i = 1; i < mResults.size(); ++i )
    {
      // convert boost::sub_match to string
      std::string sMatch = std::string() + mResults.str( i );

      // copy to results array as char (for mapinfo's benefit)
      strcpy_s( cMatches[ i - 1 ], 32600, sMatch.c_str() );
    }

    // return number of hits
    return ( int )mResults.size() - 1;
  }
  else
  {
    // no match
    return 0;
  }
}

EXPORT int regex_match_all( char* cInput, char* cMatch, char* cMatches[] )
{
  // recast niput char to string
  std::string sInput = std::string( cInput );

  // setup regex
  std::tr1::smatch mResults;
  std::tr1::regex rx( cMatch );

  // do search
  regex_search( sInput, mResults, rx );

  // copy matches to output array
  int submatches[] = {1};
  std::tr1::sregex_token_iterator i( sInput.begin(), sInput.end(), rx, submatches );
  std::tr1::sregex_token_iterator j;
  unsigned count = 0;
  while ( i != j )
  {
    count++;
    strcpy_s( cMatches[count - 1], 32000, i->str().c_str() );
    i++;
  }
  // return number of matches
  return count ;
}

EXPORT int regex_replace( char* cInput, char* cMatch, char* cReplace, char* cDest )
{
  // recast input chars to string
  std::string sInput = std::string( cInput );
  std::string sReplace = std::string( cReplace );

  // setup regex
  std::tr1::regex rx( cMatch );

  std::string sReplaced = std::tr1::regex_replace( sInput, rx, sReplace );

  strcpy_s( cDest, 32000, sReplaced.c_str() );
  if ( sReplaced != sInput )
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
