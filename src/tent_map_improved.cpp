#include<iostream> 
#include<vector>

std::vector<double> tent_map(double init_val, std::vector<double> a, std::vector<double> x){

  for(int i = 0; i < a.size(); ++i){
    x[(i*x.size)] = 0.2;
    for(int j = 0; i < x.size()-1; ++j){
      if ([ (i*x.size()) + j ] > 0.0 and x[ (i*x.size()) + j ] < 0.5){
        x[ (i*x.size() + (j+1))] = 2*a[i]*x[(i*x.size()) + j];
      }
      else if(x[ (i*x.size()) + j ] > 0.5 and [ (i*x.size()) + j ] < 1.0){
        x[ (i*x.size() + (j+1))] = 2*a[i]*(1 - x[(i*x.size()) + j]);
      }

  return x;
}

void alpha(std::vector<double> a, double stop){
  double step = stop/a.size();
  for (int i = 0; i < a.size(); ++i){
    a[i] = i*step;
  }
}

void print_result(std::vector<double> x_1, std::vector<double> x_2){
  if (x_1.size() != x_2.size()){
    std::cout << "La función no aplica para vectores de distinto tamaño" << std::endl;
    exit(1);
  }

  for(int i = 0; i < x_1.size(); ++i){
    std::cout << i+1 << " " << x_1[i] << " " << x_2[i] << std::endl;
  }
}

int main(){
  
  int n_iter = 20;
  int n_alpha = 280;
  double init_val;

  std::vector<double> x(n_alpha*n_iter, 0.0);
  std::vecotr<double> a(n_alpha, 0.0);

  return 0;
}
