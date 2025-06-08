#pragma once
#include <atltypes.h>
#include <afx.h>
class CCircle {
private:
  int center_x;
  int center_y;
  int radius;

public:
  CCircle() : center_x(0), center_y(0), radius(0) {}

  CCircle(int x, int y, int r) : center_x(x), center_y(y), radius(r) {}

  int GetCenterX() const { return center_x; }
  int GetCenterY() const { return center_y; }
  int GetRadius()  const { return radius; }

  void SetCenterX(int x) { center_x = x; }
  void SetCenterY(int y) { center_y = y; }
  void SetRadius(int r) { radius = r; }
};
