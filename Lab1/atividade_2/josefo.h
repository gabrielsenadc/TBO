#ifndef josefo_h
#define josefo_h

typedef struct circleType circleType;

circleType * createCircle(int n, int m);

void execute(circleType * circle);

void freeCircle(circleType * circle);


#endif