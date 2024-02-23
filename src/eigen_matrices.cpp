#include <eigen3/Eigen/Dense>
#include <iostream>
#include <ctime>

using namespace std;
int main(){
    Eigen::Matrix<double, 5, 5> mat = Eigen::Matrix<double, 5, 5>::Random();
    Eigen::Matrix<double, 5, 1> v = Eigen::Matrix<double, 5, 1>::Random()*10;
    cout << " matrix = : \n " << mat << endl;
    cout << " trace = : \n " << mat.trace() << endl;
    cout << " transpose = : \n " << mat.transpose() << endl;
    cout << " mat inverse = \n" << mat.inverse() << endl;
    cout << " mat determinannt = \n " << mat.determinant() << endl;

    // Eigen values of real symmetric matrix
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix<double, 5, 5>> eigen_solver(mat.transpose()*mat);
    cout << " Eigen values = \n " << eigen_solver.eigenvalues() << endl;
    cout << " Eigen vectors = \n " << eigen_solver.eigenvectors() << endl;

    // Solving equations 
    clock_t time_stt = clock();
    Eigen::Matrix<double, 5, 5> mat_ = mat.transpose()*mat;
    Eigen::Matrix<double, 5 , 1> x = mat_.colPivHouseholderQr().solve(v);
    cout << "x = \n" << x.transpose() << endl;

    // for positive definite matrix - cholesky decomposition is the best.
    // solving ldlt
    x = mat_.ldlt().solve(v);
    cout << " x = \n " << x.transpose() << endl;


}