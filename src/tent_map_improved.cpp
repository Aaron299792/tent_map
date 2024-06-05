#include<iostream> 
#include<vector>

std::vector<double> tent_map(double &init_val, std::vector<double> &a, std::vector<double> &x){
  int rows = a.size();
  int cols = x.size()/rows;

  for(int i = 0; i < rows; ++i){
    x[(i*cols)] = 0.2;
    for(int j = 0; j < (cols-1); ++j){
      if ( x[(i*cols) + j ] > 0.0 and x[ (i*cols) + j ] < 0.5){
        x[ (i*cols) + (j+1)] = 2*a[i]*x[(i*cols) + j];
      }
      else if( x[ (i*cols) + j ] > 0.5 and x[ (i*cols) + j ] < 1.0){
        x[ (i*cols) + (j+1)] = 2*a[i]*(1 - x[(i*cols) + j]);
      }
    }
  }
      
  return x;
}

std::vector<double> parameter(std::vector<double> &a, double stop){
  int size = a.size();
  double step = stop/size;
  for (int i = 0; i < size; ++i){
    a[i] = i*step;
  }
 
  return a;
}

void print_mat(std::vector<double> &mat, int &rows, int &cols){
  for (int j = 0; j < cols; ++j){
    for(int i = 0; i < rows; ++i){
      std::cout << mat[j + (i*cols) ] << " ";
    }
    std::cout << std::endl;
  }
}

int main(){
  
  int n_iter = 20;
  int n_alpha = 100;
  double init_val = 0.2;

  std::vector<double> x(n_alpha*n_iter, 0.0);
  std::vector<double> a(n_alpha, 0.0);

  a = parameter(a, 1.0);
  x = tent_map(init_val,a,x);
  print_mat(x, n_alpha, n_iter);
  return 0;
}
