#include "mbed.h"


DigitalOut myled(LED1);
Serial pc(USBRX, USBTX);
Serial dev(p9, p10);

void dev_recv(){
    while(dev.readable()){
        pc.putc(dev.getc())    
    }    
}

void pc_recv(){
    while(pc.readable()){
        dev.putc(pc.getc());    
    }    
}

int main() {
    pc.baud(9600);
    device1.baud(115200);
    pc.attach(&pc_recv);
    dev.atach(&dev);
    pc.printf("Hello!! \r\n");
    
    while(1) {
        myled = 1;
        wait(1);
        myled = 0;
        wait(1);
    }
}