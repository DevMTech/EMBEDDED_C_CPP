#include <iostream>
#include <windows.h>

#include "Helper.h"
#include "Base64.h"
#include "KeyConstants.h"
#include "IO.h"
//#include "Timer.h"

using namespace std;

int main()
{
    // cout << "Hello world!" << endl;

    MSG Msg;

    while(GetMessage(&Msg, NULL, 0, 0)) // MAIN THREAD
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return 0;
}
