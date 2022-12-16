#include <stdio.h>
#include <string.h>
#include "virusFunc.h"
#include <dirent.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char * argv[]){
    clock_t  start, end;
    start = clock();

    // array of drives connected to computer
    char existDrivesArray[10][10] = {};
    int drivesArryLength = 0;
    // detect every drives and the array length
    detectDrives(existDrivesArray, &drivesArryLength); // will detect drives and the conut of drives
    printf("Detected Drives Length Is: %d\n", drivesArryLength);


    // for(int i = 0; i < drivesArryLength; i++){
    //     if(strcmp(existDrivesArray[i], "C:\\")==0){
    //         printf("%s\n", existDrivesArray[i]);
    //         printf("C Drive Detected\n");
    //     }
    // }

    for(int i = 0; i < drivesArryLength; i++){
        if(strcmp(existDrivesArray[i], "D:\\")==0){
            listFilesRecursively(existDrivesArray[i]);
        }
    }

    end = clock();

    double time_taken = ((double) end - start)/CLOCKS_PER_SEC;
    printf("Total time taken is: %f\n", time_taken);

    return 0;
}
