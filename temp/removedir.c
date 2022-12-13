#include <stdio.h>
#include <unistd.h>

int main(){
  int ret = rmdir("delta");
  if(ret == 0){
    printf("Succesfully delted\n");
  }else{
    printf("Unable to remove folder\n");
  }
  return 0;
}
