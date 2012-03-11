int main( int argc, char** argv )
{
   __asm__(  
      "sub    $0x20,%esp"
      "movl   $0x80af108,0x18(%esp)"
      "movl   $0x0,0x1c(%esp)"
      "mov    0x18(%esp),%eax"
      "movl   $0x0,0x8(%esp)"
      "lea    0x18(%esp),%edx"
      "mov    %edx,0x4(%esp)"
      "mov    %eax,(%esp)"
      "call   0x8053380 <execve>"
      ".string \"/bin/sh\""
   );

   return 1;
}
