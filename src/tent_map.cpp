#include<iostream> 
#include<vector>

std::vector<double> tent_map(double a, double init_val, std::vector<double> x){
  x[0] = init_val;
  
  for (int i = 0; i < x.size()-1; ++i){
    if (x[i] < 0.5 and x[i] > 0.0){
        x[i+1] = 2*a*x[i];
      }
      else if (x[i] > 0.5 and x[i] < 1.0){
        x[i+1] = 2*a*(1-x[i]);
      }
  }

  return x;
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
  double init_val = 0.2;
  double a_1 = 0.4;
  double a_2 = 0.7;
  std::vector<double> x_1(n_iter, 0.0);
  std::vector<double> x_2(n_iter, 0.0);

  x_1 = tent_map(a_1, init_val, x_1);
  x_2 = tent_map(a_2, init_val, x_2);

  print_result(x_1,x_2);  


  return 0;
}
