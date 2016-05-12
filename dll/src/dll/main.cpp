#include "dll_header.h"
#include <iostream>
#include <fstream>
#include <time.h>

int testVal = 0;

/** Writes a message to a (hardcoded) log file
 * @param message message to write
 */
void writeToLog( char* message )
{
  std::ofstream logFile;
  logFile.open( "d:\\test.log", std::ios::app );
  logFile << message << "\n";
  logFile.close();
}


BOOL WINAPI DllMain( HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved )
{
  UNUSED( hinstDLL );
  UNUSED( lpvReserved );

  srand ( ( unsigned int )time( NULL ) );
  switch ( fdwReason )
  {
    case DLL_PROCESS_ATTACH:
      // attach to process
      // return FALSE to fail DLL load
      break;

    case DLL_PROCESS_DETACH:
      // detach from process
      break;

    case DLL_THREAD_ATTACH:
      // attach to thread
      break;

    case DLL_THREAD_DETACH:
      // detach from thread
      break;
  }
  return TRUE; // succesful
}
