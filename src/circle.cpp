// Copyright 2022 UNN-CS
#include "circle.h"
#include <cmath>

namespace {
const double kPi = 3.14159265358979323846;
}

Circle::Circle(double r) : radius(0.0), ference(0.0), area(0.0) {
  setRadius(r);
}

void Circle::UpdateFromRadius() {
  ference = 2.0 * kPi * radius;
  area = kPi * radius * radius;
}

void Circle::UpdateFromFerence() {
  radius = ference / (2.0 * kPi);
  area = kPi * radius * radius;
}

void Circle::UpdateFromArea() {
  radius = std::sqrt(area / kPi);
  ference = 2.0 * kPi * radius;
}

void Circle::setRadius(double r) {
  if (r < 0.0) {
    radius = 0.0;
    UpdateFromRadius();
    return;
  }
  radius = r;
  UpdateFromRadius();
}

void Circle::setFerence(double f) {
  if (f < 0.0) {
    ference = 0.0;
    UpdateFromFerence();
    return;
  }
  ference = f;
  UpdateFromFerence();
}

void Circle::setArea(double a) {
  if (a < 0.0) {
    area = 0.0;
    UpdateFromArea();
    return;
  }
  area = a;
  UpdateFromArea();
}

double Circle::getRadius() const {
  return radius;
}

double Circle::getFerence() const {
  return ference;
}

double Circle::getArea() const {
  return area;
}
