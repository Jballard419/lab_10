#include "Kruskal.cpp"
#include <fstream>
int main(int argc, char const *argv[]) {
  /* code */
  if (argc != 2)
  {
    std::cout << "file didn't load use like this " << '\n';
    std::cout << "./Skew_Heap data.txt" << '\n';
  }
  std::ifstream in(argv[1]);

  int value;

  int** array;


  while(in>>value)
  {
    const int dummy = value;
    array [dummy][dummy];
    for (int i = 0; i < value; i++) {
      for (int j = 0; j < value; j++) {
          in>>array[i][j];
      }
    }
    Kruskal(array, value);



  }

}
