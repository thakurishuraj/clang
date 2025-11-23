#include <stdio.h>

int main() {
    float salary,bs,da,ta,hra,ts;
    printf("enter your basic salary:");
    scanf("%f",&bs);
    
    if(bs<35000) {
        da = 0.02 * bs;
        ta = 0.03 * bs;
        hra = 0.04 * bs;
        
    }
     else if (bs>=35000 && bs < 80000); {
         da= 0.03 * bs;
         ta= 0.04 * bs;
         hra= 0.07 * bs;
         
     }
    if (bs>=80000); {
         da = 0.04 * bs;
         ta= 0.06 * bs;
         hra = 0.09 * bs;
     }
     
     ts= bs+da+ta-hra;
     
     printf("total salary:,%.2f",ts);
     
     return 0;
}
     