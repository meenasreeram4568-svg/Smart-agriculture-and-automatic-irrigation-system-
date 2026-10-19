 #include<lpc21xx.h>
#include"header.h"
u8 sec,min,hrs,dd,mm,yy,y1=20;
u8 flag;


void rtc(void){
               rtc_read();
                convert_dec();
                uart0_display();
}

void rtc_read(void){
        sec=i2c_read(0xD1,0x0);
        min=i2c_read(0xD1,0x1);
        hrs=i2c_read(0xD1,0x2);
        dd=i2c_read(0xD1,0x4);
        mm=i2c_read(0xD1,0x5);
        yy=i2c_read(0xD1,0x6);
}

void convert_dec(void){
        sec=bcd_dec(sec);
        min=bcd_dec(min);
        hrs=bcd_dec(hrs);
        dd=bcd_dec(dd);
        mm=bcd_dec(mm);
        yy=bcd_dec(yy);
}
void uart0_display(void){
        uart0_string("\r\nRTC Date : ");
        uart0_tx(dd/10+48);
        uart0_tx(dd%10+48);
        uart0_tx('/');

        uart0_tx(mm/10+48);
        uart0_tx(mm%10+48);
        uart0_tx('/');

        uart0_tx(y1/10+48);
        uart0_tx(y1%10+48);
        uart0_tx(yy/10+48);
        uart0_tx(yy%10+48);

        uart0_string("\r\nRTC Time : ");
        uart0_tx(hrs/10+48);
        uart0_tx(hrs%10+48);
        uart0_tx(':');

        uart0_tx(min/10+48);
        uart0_tx(min%10+48);
        uart0_tx(':');

        uart0_tx(sec/10+48);
        uart0_tx(sec%10+48);

}

unsigned char bcd_dec(unsigned char bcd){
         char res=0;
        res=((bcd>>4)*10)+(bcd&0xF);
        return res;
}
void rtc_write(void){
        i2c_write(0xD0,0x0,0x00);
        i2c_write(0xD0,0x1,0x18);
        i2c_write(0xD0,0x2,0x12);

        i2c_write(0xD0,0x4,0x14);
        i2c_write(0xD0,0x5,0x10);
        i2c_write(0xD0,0x6,0x26);
} 

void uart0_diaplay(void);

