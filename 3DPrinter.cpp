#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0), EPS = 1e-8;

struct Vector {
  double x, y, z;

  Vector(double xx = 0, double yy = 0, double zz = 0) : x(xx), y(yy), z(zz) { }
  Vector(const Vector &p1, const Vector &p2)
    : x(p2.x - p1.x), y(p2.y - p1.y), z(p2.z - p1.z) { }
  Vector(const Vector &p1, const Vector &p2, double t)
    : x(p1.x + t*p2.x), y(p1.y + t*p2.y), z(p1.z + t*p2.z) { }
  double norm() const { return sqrt(x*x + y*y + z*z); }
  bool operator==(const Vector&p) const{
    return abs(x - p.x) < EPS && abs(y - p.y) < EPS && abs(z - p.z) < EPS;
  }
};

double dot(Vector p1, Vector p2) { return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z; }
double angle(Vector p1,Vector p2) {  return acos(dot(p1, p2)/p1.norm()/p2.norm()); }
Vector cross(Vector p1, Vector p2) {
  return Vector(p1.y*p2.z-p2.y*p1.z, p2.x*p1.z-p1.x*p2.z, p1.x*p2.y-p2.x*p1.y); }
Vector operator+(Vector p1,Vector p2){ return Vector(p1.x+p2.x,p1.y+p2.y,p1.z+p2.z); }
Vector operator-(Vector p1,Vector p2){ return Vector(p1.x-p2.x,p1.y-p2.y,p1.z-p2.z); }
Vector operator*(double c,Vector v){ return Vector(c*v.x, c*v.y, c*v.z); }

// Compute the volume of a convex polyhedron (input is an array of triangular faces)
typedef tuple<Vector,Vector,Vector> tvvv;
double volume_polyhedron(vector<tvvv>& p){
  Vector c,p0,p1,p2; double v, volume = 0;
  for(int i=0;i<p.size();i++)
    c = c + get<0>(p[i]) + get<1>(p[i]) + get<2>(p[i]);
  c = 1/(3.0*p.size())*c;
  for(int i=0;i<p.size();i++){
    tie(p0,p1,p2) = p[i], v = dot(p0,cross(p1,p2)) / 6;
    if(dot(cross(p2-p1,p0-p1),c-p0) > 0) volume -= v;
    else volume += v;
  }
  return volume;
}


int main() {
  int polyhedra;
  cin >> polyhedra;
  double volume = 0;
  for (int a = 0; a < polyhedra; a++) {
    //For every polyhedra
    int faces = 0;
    cin >> faces;
    vector<tvvv> shape;
    for (int b = 0; b < faces; b++) {
      vector<Vector> vertex;
      int vertices;
      cin >> vertices;
      for (int i = 0; i < vertices; i++) {
        double x, y, z;
        cin >> x >> y >> z;
        vertex.push_back(Vector(x,y,z));
      }
      //Create faces
      for (int i = 1; i < vertices-1; i++) {
        shape.push_back(make_tuple(vertex[0],vertex[i],vertex[i+1]));
      }
    }
    volume += volume_polyhedron(shape);
  }
  cout << fixed << setprecision(2);
  cout << volume << endl;
}
