#pragma once
#include <iostream>
class Particule;
class Systeme;
class Obstacle;
class Source;
class Plan;
class Dalle;


class SupportADessin
{
 public:
  virtual ~SupportADessin() = default;
  // on suppose ici que les supports ne seront ni copiés ni déplacés

  virtual void dessine(Particule const&) = 0;
  virtual void dessine(Systeme const&) = 0;
  virtual void dessine(Obstacle const&) = 0;
  virtual void dessine(Source const&) = 0;
  virtual void dessine(Plan const&) = 0;
  virtual void dessine(Dalle const&) = 0;
};
