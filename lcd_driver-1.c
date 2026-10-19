#include<lpc21xx.h>
#include"header.h"

void lcd_data(unsigned char data)
{

        unsigned int temp;
        // higher nibbel
        IOCLR1=0xfe<<16;
        temp =(data&0xf0)<<16;
        IOSET1=temp;
        IOSET1=1<<17;
        IOCLR1=1<<18;
        IOSET1=1<<19;
        delay_ms(2);
        IOCLR1=1<<19;

        //lower nibble
        IOCLR1=0xfe<<16;
        temp=(data&0x0f)<<20;
        IOSET1=temp;
        IOSET1=1<<17;
        IOCLR1=1<<18;
        IOSET1=1<<19;
        delay_ms(2);
        IOCLR1=1<<19;

}
void lcd_cmd(unsigned char cmd)
{
        unsigned int temp;

        IOCLR1=0xfe<<16;
        temp=(cmd&0xf0)<<16;
        IOSET1=temp;
        IOCLR1=1<<17;
        IOCLR1=1<<18;
        IOSET1=1<<19;
        delay_ms(2);
        IOCLR1=1<<19;

        IOCLR1=0xfe<<16;
        temp=(cmd&0x0f)<<20;
        IOSET1=temp;
        IOCLR1=1<<17;
        IOCLR1=1<<18;
        IOSET1=1<<19;
        delay_ms(2);
        IOCLR1=1<<19;

}
void lcd_init()
{
        IODIR1=0xfe<<16;
        PINSEL0|=0x0;
        lcd_cmd(0x02);
        lcd_cmd(0x28);
        lcd_cmd(0x0e);
        lcd_cmd(0x01);
}

void lcd_string(char *ptr)
{
        while(*ptr!=0)
        {
                lcd_data(*ptr);
                ptr++;
        }
}
void lcd_int(int num)
{
        int a[20],i;

        if(num==0)
        {
                lcd_data('0');
        }
        if(num<0)
        {
                num=-num;
                lcd_data('0');
        }

        i=0;
        while(num>0)
        {
                a[i]=num%10+48;
                num=num/10;
                i++;
        }

        for(i=i-1;i>=0;i--)
        {
                lcd_data(a[i]);
        }

}
void lcd_float(float num)
{
        int a[20],i,n1,fra;

        if(num==0)
        {
                lcd_data('0');
        }
        if(num<0)
        {
                num=-num;
                lcd_data('-');
        }

        n1=(int)num;
        fra=n1-num;

        i=0;
        while(n1>0)
        {
                a[i]=n1%10+48;
                n1/=n1;
                i++;

        }
        for(i=i-1;i>=0;i--)
        {
                lcd_data(a[i]);
        }

        i=0;
        while(fra>=0)
        {
                a[i]=fra%10+48;
                fra/=fra;
                i++;
        }
                            for(i=i-1;i>=0;i--)
lcd_data(a[i]);

}
