# File Deleter Virus in C
this virus will delete the files in all drives except ***C:***

## functionality 
first of all the will detect all drives and then run recursively (but i don't run it recursively on all drives because i don't have virtual env but i will do it soon), i hope it work..
i have also made a function which will copy picture to target directory which you want and then set the desktop wallpaper to that picture when the deletion is finished.

## Project structure
this file in `temp` and **testRoot** directory are my research so you can delete it or just study it.


## exceptions
first of all i implement the threading functionality to remove recursively but it's remove half drives item and some of them remain. so i removed the threading functionality but i will try again!.

# Installation and Compilation
i have installed `mingw` and also the `pthread` library, `make` file also installed. so you just type

```bash
make
```
this will compile the hole files and make the exe named `ak07.exe`. now you read to run and destroy(format) the drives except **c:/**.

# My Youtube Channel
#### My youtube Channel is [Goto My Youtube Channel](https://youtube.com/@akk07/)

# Todos to add into this project !
- [x] Contribute into this project.
- [ ] Speed the Deleting functionality.
- [ ] Fix other issues if exists.