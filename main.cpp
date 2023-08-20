#include "mbed.h"


DigitalOut myled(LED1);
BufferedSerial pc(USBTX, USBRX);
BufferedSerial dev(D1, D0);

void dev_recv(){
    while(1){
        char recv_data;
        if (dev.read(&recv_data, 1) > 0){
        pc.write(&recv_data, 1);
        }

    }  
}

void pc_recv(){
    while(1) {
        char recv_data;
    if (pc.read(&recv_data, 1) > 0){
        dev.write(&recv_data, 1); 
    }   
    }    
}

int main() {
    pc.set_baud(9600);
    dev.set_baud(115200);
    Thread pc_thread;
    Thread dev_thread;

    pc_thread.start(pc_recv);
    dev_thread.start(dev_recv);
    
    printf("Hello!! \r\n");
    
    while(1) {
        myled = !myled;
        wait_us(10000);
    
    }
}