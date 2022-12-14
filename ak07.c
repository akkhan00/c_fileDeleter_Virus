#include <stdio.h>
#include <string.h>
#include "virusFunc.h"


int main(int argc, char * argv[]){

    char existDrivesName[20][10] = {};

    detectDrives(existDrivesName);

    printf("## in my man file lllllllllll\n");
    for (int i = 0; i<3; i++){
        printf("%s\n", existDrivesName[i]);
    }

    return 0;
}
