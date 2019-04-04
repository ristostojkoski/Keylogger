// ./app/src/
#include <windows.h>
#include "../../library/include/Base64.h"
#include "../../library/include/Helper.h"
#include "../../library/include/IO.h"
#include "../../library/include/KeyConstrants.h"

int main()
{
   MSG msg;

   while(GetMessage(&msg, NULL, 0, 0)){
       TranslateMessage(&msg);
       DispatchMessage(&msg);
   }

   return 0;
}