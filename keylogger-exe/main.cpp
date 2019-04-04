// ./src/
#include <windows.h>
#include "headers/Base64.h"
#include "headers/Helper.h"
#include "headers/IO.h"
#include "headers/KeyConstrants.h"

int main()
{
   MSG msg;

   while(GetMessage(&msg, NULL, 0, 0)){
       TranslateMessage(&msg);
       DispatchMessage(&msg);
   }

   return 0;
}