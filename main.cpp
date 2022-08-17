#include <Arduino.h>

int ;


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}


/*
Javascript: 

function ptInTriangle(p, p0, p1, p2) {
    var A = 1/2 * (-p1.y * p2.x + p0.y * (-p1.x + p2.x) + p0.x * (p1.y - p2.y) + p1.x * p2.y);
    var sign = A < 0 ? -1 : 1;
    var s = (p0.y * p2.x - p0.x * p2.y + (p2.y - p0.y) * p.x + (p0.x - p2.x) * p.y) * sign;
    var t = (p0.x * p1.y - p0.y * p1.x + (p0.y - p1.y) * p.x + (p1.x - p0.x) * p.y) * sign;
    
    return s > 0 && t > 0 && (s + t) < 2 * A * sign;
}


Python: 

[px, py] = [397.00520849227905,75.015625] #[177.00520849227905,127.015624545455]
[p0x, p0y] = [67, 475]
[p1x, p1y] = [162,78]
[p2x, p2y] = [353,369]

A = 1/2 * (-p1y * p2x + p0y * (-p1x + p2x) + p0x * (p1y - p2y) + p1x * p2y)
sign = numpy.sign(A)
s = (p0y * p2x - p0x * p2y + (p2y - p0y) * px + (p0x - p2x) * py) * sign
t = (p0x * p1y - p0y * p1x + (p0y - p1y) * px + (p1x - p0x) * py) * sign

print(A)
print(sign)
print(s)
print(t)

final = s > 0 and t > 0 and (s + t) < 2 * A * sign

print(final)

C:




*/