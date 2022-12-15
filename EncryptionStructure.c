#include <stdio.h>
#include "virusFunc.h"
#include <string.h>


typedef struct{
	char a[6];
	char b[6];
	char c[6];
	char d[6];
	char e[6];
	char f[6];
	char g[6];
	char h[6];
	char i[6];
	char j[6];
	char k[6];
	char l[6];
	char m[6];
	char n[6];
	char o[6];
	char p[6];
	char q[6];
	char r[6];
	char s[6];
	char t[6];
	char u[6];
	char v[6];
	char w[6];
	char x[6];
	char y[6];
	char z[6];
	char dot[6];
}AK_Encryption;



int main(void){

	AK_Encryption some = {
			"0xyz9",
			"2wxy7",
			"9vwx2",
			"6uvw3",
			"6tuv3",
			"4stu2",
			"4rst2",
			"3qrs2",
			"2pqr5",
			"3opq1",
			"2nop7",
			"2mno1",
			"2lmn3",
			"8klm7",
			"8jkl7",
			"1ijk4",
			"1hij2",
			"g4hi3",
			"5fgh6",
			"9efg7",
			"0def8",
			"1cef7",
			"2bef9",
			"abc85",
			"2yyy2",
			"2zzz1",
			"2d291"
	};
	printf("a is: %s and b is : %s\n", some.a, some.b);

	// st
	return 0;
}

// "a b c d e f g h i j k l m n o p q r s t u v w x y z";

// "a == 0xyz9";
// "b == 2wxy7";
// "c == 9vwx2";
// "d == 6uvw3";
// "e == 6tuv3";
// "f == 4stu2";
// "g == 4rst2";
// "h == 3qrs2";
// "i == 2pqr5";
// "j == 3opq1";
// "k == 2nop7";
// "l == 2mno1";
// "m == 2lmn3";
// "n == 8klm7";
// "o == 8jkl7";
// "p == 1ijk4";
// "q == 1hij2";
// "r == g4hi3";
// "s == 5fgh6";
// "t == 9efg7";
// "u == 0def8";
// "v == 1cef7";
// "w == 2bef9";
// "x == abc85";
// "y == 2yyy2";
// "z == 2zzz1";
// ". == 2d291";

// "khalfan == 2nop73qrs20xyz92mno14stu20xyz98klm7"