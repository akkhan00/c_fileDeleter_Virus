#include <stdio.h>
#include <sys/stat.h>

int isDirectory(const char *path){
  struct stat statbuf;
  if(stat(path, &statbuf)!= 0){
    return 0;
  }else{
    return S_ISDIR(statbuf.st_mode);
  }
}

int main(){
  int result = isDirectory("./abc.folder");
  if(result){
    printf("It's a direcotry\n");
  }else{
    printf("It's not a directory\n");
  }
}
