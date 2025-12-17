#include <stdio.h>
#include "funcs.h"
#include <math.h>

#define MODE_CCM 1
#define MODE_DCM 2
#define TARGET_VOUT 1
#define TARGET_VIN 2


void menu_item_1(void) {
    int mode, target;
    flaot L, R, f, D, vin, vout, K, k_crit, result;

    printf("\n <[O'o]> Buck converter Design <[O'o]> \n");
    printf("     <|>                           <|>\n");

    printf("\n1. Continuous Mode (CCM)\n2. Discontinuous Mode (DCM)\nSelect Mode:");
    scanf("%d", &mode);
    getchar();

    printf("\n1. Calculate Vout\n Calculate Vin\nSelect Target");
    scanf("%d",&target);
    getchar();
    
 // Instead of reapeting the lines of values entering process // 
    get_common_input(&L, &R, &f, &D);
 // Safety Check for K (Duty Ratio) // 
    k = (2*L*f) / R;
    k_crit = 1 - D;
 // Warning if Mode selection doesn't match the physics results // the ? method is shorter way for if-else where it could be implmented shortly // 
    int calculated_mode = (k>k_crit) ? MODE_CCM : MODE_DCM;
    if (calculated_mode != mode) {
        printf("\n <[O'o]>  ⚠ WARNING: Safety check conifrming that you are in %s\n ", (calculated_mode == MODE_CCM) ? "CCM" : "DCM\n");
        printf("     <|>\n");
    }
    // Voltage calculation // 
    if (target == TARGET_VOUT){
       printf("\n Enter the input voltage: ");
        scanf("%f",&vin);
        getchar();
        if (mode == MODE_CCM){
            result = D*vin;
        } else {
            printf("(Using DCM Approx)\n");
            float Gain = 2.0/(1.0+sqrt(1.0+(4.0*k)/(D*D)));
            result = vin * Gain;
        }
        vout = result; 
    } else {
        printf("\n Enter Vout: ");
        scanf("%f",&vout);
        getchar();
        if (mode == MODE_CCM){
            result = vout / D;
        }else{
            printf("Using DCM Approx)\n");
            result = 0.0;
        }
        vin = result;
    }
    printf("\n>>   <[0'0]> RESULT: %.2F VOLTS\n",result);
    printf("         <|>\n");
    
    /* you can call a function from here that handles menu 1 */
}

void menu_item_2(void) {
    int mode, target;
    flaot L, R, f, D, vin, vout, K, k_crit, result;

    printf("\n <[O'o]> Boost converter Design <[O'o]> \n");
    printf("     <|>                            <|>\n");

    printf("\n1. Continuous Mode (CCM)\n2. Discontinuous Mode (DCM)\nSelect Mode:");
    scanf("%d", &mode);
    getchar();

    printf("\n1. Calculate Vout\n Calculate Vin\nSelect Target");
    scanf("%d",&target);
    getchar();
    
 // Instead of reapeting the lines of values entering process // 
    get_common_input(&L, &R, &f, &D);
 // Safety Check for K (Duty Ratio) // 
    k = (2*L*f) / R;
    k_crit = (1.0-D) * (1.0-D);
 // Warning if Mode selection doesn't match the physics results // the ? method is shorter way for if-else where it could be implmented shortly // 
    int calculated_mode = (k>k_crit) ? MODE_CCM : MODE_DCM;
    if (calculated_mode != mode) {
        printf("\n <[O'o]>  ⚠ WARNING: Safety check conifrming that you are in %s\n ", (calculated_mode == MODE_CCM) ? "CCM" : "DCM\n");
        printf("     <|>\n");
    }
    // Voltage calculation // 
   if (target == TARGET_VOUT){
       printf("\n Enter the input voltage: ");
        scanf("%f",&vin);
        getchar();
        if (mode == MODE_CCM){
            result = vin / (1-D);
            vout = result;
        } 
    } else {
        printf("\n Enter Vout: ");
        scanf("%f",&vout);
        getchar();
        if (mode == MODE_CCM){
            result = vout * (1-D);
            vin = result;
        }
    }
    printf("\n>>   <[0'0]> RESULT: %.2F VOLTS\n",result);
    printf("         <|>\n");
    /* you can call a function from here that handles menu 2 */
}

void menu_item_3(void) {
    int mode, target;
    flaot L, R, f, D, vin, vout, K, k_crit, result;

    printf("\n <[O'o]> Buck-Boost converter Design <[O'o]> \n");
    printf("     <|>                                 <|>\n");

    printf("\n1. Continuous Mode (CCM)\n2. Discontinuous Mode (DCM)\nSelect Mode:");
    scanf("%d", &mode);
    getchar();

    printf("\n1. Calculate Vout\n Calculate Vin\nSelect Target");
    scanf("%d",&target);
    getchar();
    
 // Instead of reapeting the lines of values entering process // 
    get_common_input(&L, &R, &f, &D);
 // Safety Check for K (Duty Ratio) // 
    k = (2*L*f) / R;
    k_crit = pow(1-D,2);
 // Warning if Mode selection doesn't match the physics results // the ? method is shorter way for if-else where it could be implmented shortly // 
    int calculated_mode = (k>k_crit) ? MODE_CCM : MODE_DCM;
    if (calculated_mode != mode) {
        printf("\n <[O'o]>  ⚠ WARNING: Safety check conifrming that you are in %s\n ", (calculated_mode == MODE_CCM) ? "CCM" : "DCM\n");
        printf("     <|>\n");
    }
    // Voltage calculation // 
   if (target == TARGET_VOUT){
       printf("\n Enter the input voltage: ");
        scanf("%f",&vin);
        getchar();
        if (mode == MODE_CCM){
            result = -vin * (D*(1-D));
            vout = result;
        } // the DCM case needs to be reconsidered since integrating and implementing them in the code very complex //
    } else {
        printf("\n Enter Vout: ");
        scanf("%f",&vout);
        getchar();
        if (mode == MODE_CCM){
            result = -vout * ((1-D)/D);
            vin = result;
        }
    }
    printf("\n>>   <[0'0]> RESULT: %.2F VOLTS\n",result);
    printf("         <|>\n");
    /* you can call a function from here that handles menu 3 */
}

void menu_item_4(void) {
    int mode, target;
    flaot L, R, f, D, vin, vout, K, k_crit, result;

    printf("\n <[O'o]> Cuk converter Design <[O'o]> \n");
    printf("     <|>                          <|>\n");

    printf("\n1. Continuous Mode (CCM)\n2. Discontinuous Mode (DCM)\nSelect Mode:");
    scanf("%d", &mode);
    getchar();

    printf("\n1. Calculate Vout\n Calculate Vin\nSelect Target");
    scanf("%d",&target);
    getchar();
    
 // Instead of reapeting the lines of values entering process // 
    get_common_input(&L, &R, &f, &D);
 // Safety Check for K (Duty Ratio) // 
    k = (2*L*f) / R;
    k_crit = pow(1.0 - D)*(1.0-D);
 // Warning if Mode selection doesn't match the physics results // the ? method is shorter way for if-else where it could be implmented shortly // 
    int calculated_mode = (k>k_crit) ? MODE_CCM : MODE_DCM;
    if (calculated_mode != mode) {
        printf("\n <[O'o]>  ⚠ WARNING: Safety check conifrming that you are in %s\n ", (calculated_mode == MODE_CCM) ? "CCM" : "DCM\n");
        printf("     <|>\n");
    }
    // Voltage calculation // 
   if (target == TARGET_VOUT){
       printf("\n Enter the input voltage: ");
        scanf("%f",&vin);
        getchar();
        if (mode == MODE_CCM){
            result = -vin * (D*(1.0-D));
        }else{
           if(k <= 0.000001) {
               printf(" [ERROR] Load R is too high (Opne circuit)! \n)");
               return;
           } 
            vout = result;
        } else{
        printf("\n Enter Vout: ");
        scanf("%f",&vout);
        getchar();
        if (mode == MODE_CCM){
            result = -vout * ((1.0-D)/D);
        }else {
            result = -vout * sqrt(k) / D;
        }
            vin = result;
    }
    printf("\n>>   <[0'0]> RESULT: %.2F VOLTS\n",result);
    printf("         <|>\n");
    /* you can call a function from here that handles menu 4 */
}
