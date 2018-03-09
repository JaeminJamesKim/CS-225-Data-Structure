// your code here!
#include "potd.h"
#include <iostream>
#include <string>
#include <cmath>

int *potd::raise(int *arr){
  int count = 0;
    while(arr[count] >= 0){count++;}
    int * newarr = new int [count + 1];
    newarr[count] = arr[count];
  for(int j = 0; j<count-1; j++){
      newarr[j]=pow(arr[j], arr[j+1]);
  }
  newarr[count-1]=arr[count-1];
  newarr[count]=arr[count];
  return newarr;

//   int count = 0;
//     while(arr[count] >= 0){count++;}
//     int * newarr = new int [count + 1];
//     newarr[count] = arr[count];     // last element remains the same
//     for(int i = 0; i < count; i++){
//         newarr[i] = pow(arr[i], power);
//     }
//     return newarr;
// }



}
