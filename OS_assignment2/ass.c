#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/shm.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <pthread.h>
#include <stdbool.h>
#include<time.h>

int main( int argc, char *argv[] )
{
    int i;
    FILE *fp;

    // If there are no command line parameters, complain and exit
    //
    if ( argc < 4 )
    {
        fprintf( stderr, "Usage: %s some_file_names\n", argv[0] );
        return 1;  // This exits the program, but you might choose to continue processing
                   // the other files.
    }else if(argc>4)
    {
      fprintf( stderr, "Exxcess files taken as input");
      return 2;
    }

    for ( i = 1; i < argc; i++ )
    {
        if ( (fp = fopen(argv[i], "r")) == NULL )
        {
            fprintf( stderr, "%s: Gah! I could not open file named %s!\n", argv[0], argv[i] );
            return 3;
        }

        
        fclose( fp );
    }

    return 0;
}