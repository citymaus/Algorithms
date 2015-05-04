/*
  LITTLE ENDIAN
       higher memory
          ----->
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    A
    |
   &x

  BIG ENDIAN
    +----+----+----+----+
    |0x00|0x00|0x00|0x01|
    +----+----+----+----+
    A
    |
   &x

int x = 0x76543210;
Big endian format:
------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x76 | 0x54 | 0x32 | 0x10 |
			 
Little endian format:
---------------------
Byte address  | 0x01 | 0x02 | 0x03 | 0x04 | 
              +++++++++++++++++++++++++++++
Byte content  | 0x10 | 0x32 | 0x54 | 0x76 |
*/
bool isLittleEndian()
{
  int x = 0x76543210;
  char *y = (char*) &x;

  return (*y == 0x10);
}

/* OR */
main()
{
   int num = 1;
   if(*(char *)&num == 1)
   {
      printf("\nLittle-Endian\n");
   }
   else
  {
      printf("Big-Endian\n");
  } 
}