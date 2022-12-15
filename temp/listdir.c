#include <stdio.h>
#include <dirent.h>

int main(){
  struct dirent *d;

  DIR *dr;

  dr = opendir("f:");
  if(dr != NULL){
    printf("List of files & folders\n");
    for (d=readdir(dr); d!=NULL; d=readdir(dr)){
      printf("%s\n", d->d_name);
    }
    closedir(dr);
  }else{
    printf("\nError occurend while opening the curent directory!");
  }
  return 0;
}
