#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "genann.h"

int main(int argc, char *argv[])
{
    const char *save_name = "example/iris.ann";
    FILE *saved = fopen(save_name, "r");
    genann *ann = genann_read(saved);
    double max = -100.0;
    double min = 100.0;
    
    /* Take a random guess at the ANN weights. */
    for (int i = 0; i < ann->total_weights; ++i) {
      if (ann->weight[i] > max) {
          max = ann->weight[i];
      }
      if (ann->weight[i] < min) {
          min = ann->weight[i];
      }
      
    }
    double average = (min + max) /2.0;
    printf("%f/%f %f\n", min, max, average);
    

}