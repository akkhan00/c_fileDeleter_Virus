#include <stdio.h>
#include <string.h>
#include <windows.h>

void addSomething(char arr[][10]){
	strcpy(arr[4], "withfunc");
}


int main()
{
	/*
		arr = {{0,1,2,3,4}}
	*/
	char storeDrives[10][4] = {};
    char buf[255];
    // get the drive letters as a set of strings
    int sz = GetLogicalDriveStrings(sizeof(buf), buf);
    if( sz > 0)
    {
        // buf now contains a list of all the drive letters.  Each drive letter is
        // terminated with '\0' and the last one is terminated by two consecutive '\0' bytes.
        char* p1 = buf;
        char* p2;
        int index = 0;
        while( *p1 != '\0' && (p2 = strchr(p1,'\0')) != NULL )
        {
            printf("%s\n", p1);
            strcpy(storeDrives[index++], p1);
            p1 = p2+1;
        }
    }
    else
    {
        // Oops! something went wrong so display the error message
        DWORD dwError = GetLastError();
        FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, 0, dwError, 0, buf, sizeof(buf), 0);
        printf("%s\n", buf);

    }

    printf("#####################\n");
    for(int i = 0; i<3; i++){
    	printf("%s\n", storeDrives[i]);
    }
}
