// code from https://blog.csdn.net/weixin_28991019/article/details/113052987
#include <stdio.h>
static unsigned char getCRC8(unsigned char *data, unsigned int len);

int main() {
   // printf() displays the string inside quotation
   unsigned char value = '1';
   unsigned char* a = &value;
   unsigned int  b = 1;
   int crc8 = getCRC8(a,b);
   printf("crc8 %d",crc8);
   return 0;
}

unsigned char getCRC8(unsigned char *data, unsigned int len){
    unsigned char i;
    unsigned char poly = 0x07;//与表中的Poly列对应
    unsigned char init = 0x00;//与表中的Init列对应

    unsigned char wChar = 0;

    while (len--)
    {
        wChar = *(data++);

        //RefIn为TRUE时执行，FALSE时删除
        //InvertUint8(&wChar,&wChar);

        init ^= wChar;
        for( i = 0;i < 8;i++)
        {
            if(init & 0x80)
            {
                init = (init <1) ^ poly;
            }
            else
            {
                init = init <1;
            }
        }
    }

    //RefOut为TRUE时执行，FALSE时删除
    //InvertUint8(&init,&init);

    //与XorOut进行异或，若为0时执行或不执行没有区别
    init=init^0x55;

    return (init);

}