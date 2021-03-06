#include<iostream>
#include<eigen3/Eigen/Dense>

using namespace Eigen;

MatrixXd Lorentz_Gen(int index)
{
  MatrixXd g = MatrixXd::Zero(4,4);

  switch(index)
    {
    case 1 : g(0,1) = -1; g(1,0) = -1; break;
    case 2 : g(0,2) = -1; g(2,0) = -1; break;
    case 3 : g(0,3) = -1; g(3,0) = -1; break;
    case 4 : g(3,2) = -1; g(2,3) = 1; break;
    case 5 : g(3,1) = 1; g(1,3) = -1; break;
    case 6 : g(2,1) = -1; g(1,2) = 1; break;
    }
  
  return g;
}

double Inner_Product(MatrixXd x, MatrixXd y)
{
  MatrixXd p = x*y;

  return (0.5*p.trace());
}

MatrixXd Conmutator(MatrixXd x, MatrixXd y)
{
  int n = x.rows();
  MatrixXd c = MatrixXd::Zero(3,3);
  
  c = x*y - y*x;

  return c;
}

int main()
{
  MatrixXd Kill = MatrixXd::Zero(6,6);
  
  for(int i = 0; i < 6; i++)
    for(int j = 0; j < 6; j++)
    {
      Kill(i,j) = Inner_Product(Lorentz_Gen(i+1),Lorentz_Gen(j+1)); 
    }

  std::cout << "killing:"
	    << "\n"
	    <<
    Kill << "\n";
  std::cout << "it's inverse:" << "\n" << Kill.inverse() << "\n";
  return 0;
}
