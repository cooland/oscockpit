#include <stdio.h>
#include <stdlib.h>
#include "hidapi.h"

#if defined _WIN32 || defined _WIN64
    #include <windows.h>
#else
    #include <unistd.h>
#endif // _WIN32 || _WIN64

#define MAX_STR 255
//VID and PID for custom devices discrimination by serial number
//https://github.com/obdev/v-usb/blob/master/usbdrv/USB-IDs-for-free.txt
//#define VID 0x0477
#define VID 0x27d9
//#define PID 0x5620
#define PID 0x16c0


int main(int argc, char* argv[])
{
    int res;
    unsigned char buf[63];
    wchar_t wstr[MAX_STR];
    hid_device *handle;
    int i;
    struct hid_device_info *devs, *cur_dev;

    //Init the hidapi lib
    if(!hid_init()==0){
        printf("Error hidinit\n");
        return -1;
    }
/*
    devs=hid_enumerate(0x0,0x0);
    if (devs==NULL){
        printf("No custom HID devices\n");
        return -1;
    }
    cur_dev=devs;
    while (cur_dev){
        printf("Device found\n type: %04hx %04hx path: %s\n serial number: %ls",
               cur_dev->vendor_id,
               cur_dev->product_id,
               cur_dev->path,
               cur_dev->serial_number);
        printf("\n");
        printf(" Manufacturer: %ls\n", cur_dev->manufacturer_string);
        printf(" Product: %ls\n", cur_dev->product_string);
        printf(" Release: %d\n", cur_dev->release_number);
        printf(" Interface: %d\n", cur_dev->interface_number);
        printf("\n");
        cur_dev=cur_dev->next;
    }
    hid_free_enumeration(devs);
*/
    //open the device using VID PID and optionaly Serial number
    ////handle = hid_open(0x4d8, 0x3f, L"12345");
    //online guid gen https://www.guidgenerator.com/online-guid-generator.aspx
    handle=hid_open(VID,PID,L"9088a05a-bc89-4c60-9c2a-4d80e86a385d");
    //handle=hid_open(VID,PID,NULL);
    if (!handle){
        printf("Unable to open device");
        return 1;
    }
        //read the manufacturer string
        res=hid_get_manufacturer_string(handle,wstr,MAX_STR);
        if (res<0){
            printf("Unable to read manufacturer string\n");
        }
        wprintf(L"Manufacturer string: %s\n",wstr);

        //read the product string
        res=hid_get_product_string(handle,wstr,MAX_STR);
        if (res<0){
            printf("Unable to read product string\n");
        }
        wprintf(L"Product string: %ls \n",wstr);

        //read the serial number string
        res=hid_get_serial_number_string(handle,wstr,MAX_STR);
        if(res<0){
            printf("Unable to read serial number string\n");
        }
        wprintf(L"Serial number string: %ls \n",wstr);

        //set the hid_read function to non-blocking
        hid_set_nonblocking(handle, true);

        //try to read from device
        /*while(1){
            res=hid_read(handle,buf,sizeof(buf));

                //print the returned buffer
                if (res>0){
                    printf("Data read:\n");
                    for (int j=0;j<res;j++){
                        printf("%02hx ",buf[j]);
                    }
                    printf("\n");
                }
                else{
                    if (res==0){
                        printf("Error data read: null data given\n");
                    }else{
                    printf("Error data read: %ls \n", hid_error(handle));
                    }
                }
        }*/

        //try to write to device
        unsigned char tmp_buf[64];
        memset(tmp_buf,0x0,sizeof(tmp_buf));
        while(1){
                tmp_buf[0]=0x1;
                tmp_buf[63]=0x10;
                res=hid_write(handle,tmp_buf,sizeof(tmp_buf));

                if (res<0){
                    //printf("Unable to write()\n");
                    printf("Error write: %ls", hid_error(handle));
                    printf("\n");
                }
                else{
                    printf("write() OK\n");
                }



                res=hid_read(handle,buf,sizeof(buf));

                //print the returned buffer
                if (res>0){
                    printf("Data read:\n");
                    for (int j=0;j<res;j++){
                        printf("%02hx ",buf[j]);
                    }
                    printf("\n");
                }
                else{
                    if (res==0){
                        printf("Error data read: null data given\n");
                    }else{
                    printf("Error data read: %ls \n", hid_error(handle));
                    }
                }

                Sleep(500);
        }


        int delay=500;
        memset (buf,0x0,sizeof(buf)); //заполняем buf 0
        unsigned char buf1[63];
        memset (buf1,0x0,sizeof(buf1));
        int res1=0;

        while(1){
                //toggle LED (cmd 0x80) The first byte is the report number (0x1)
                for (int i=0;i<4;i++){

                buf[0] = 0x1;
                buf[1] = i;
                res=hid_write(handle,buf,sizeof(buf));
                if (res<0){
                    printf("Unable to write()\n");
                    printf("Error: %ls \n", hid_error(handle));
                }

                res1=hid_read(handle,buf1,sizeof(buf1));

                //print the returned buffer
                if (res1>0){
                    printf("Data read:\n");
                    for (int j=0;j<res1;j++){
                        printf("%02hx ",buf1[j]);
                    }
                    printf("\n");
                }
                else{
                    if (res1==0){
                        printf("Error data read: null data given\n");
                    }else{
                    printf("Error data read: %ls \n", hid_error(handle));
                    }
                }

                Sleep(delay);
                }
        }

        //request state (cmd 0x81) the first byte is the report number (0x0)
        buf[0]=0x0;
        buf[1]=0x81;
        res=hid_write(handle,buf,16);
        if (res<0){
            printf("Unable to write 2\n");
        }

        //read requested state for non-blocking
        res=0;
        while(res==0){
            res=hid_read(handle,buf,sizeof(buf));
            if (res==0){
                printf("Waiting...\n");
            }
            if (res<0){
                printf("Unable to read\n");
            }
                Sleep(500);

        }

        //print the returned buffer
        printf("Data read:\n");
        for (i=0;i<res;i++){
            printf("%02hx ",buf[i]);
        }
        printf("\n");

        hid_close(handle);
        //finalize the hidapi lib
        res=hid_exit();

        #ifdef _WIN32
            system("pause");
        #endif // _WIN32
    return 0;
}
