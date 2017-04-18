
class Polygon{
public:
  Polygon(){}

  virtual int area() = 0;

  void SetParams(int width, int height)
  { w = width; h = height; }

protected:
      int w, h;
};

class Rectangle : public Polygon{
public:
  Rectangle(){}
  int area() { return w * h; }
};

class Triangle : public Polygon{
public:
  Triangle(){}
  int area() { return w * h / 2.; }
};
