#include <iostream>
#include <eigen3/Eigen/Dense>

using namespace std;

int main(){
    cout << "transformations " << endl;
    Eigen::AngleAxis<double> T(M_PI/4, Eigen::Vector3d(1, 0, 0));
    

    Eigen::Vector3d v1(1, 0 , 0);
    Eigen::Vector3d v2(0, 1, 0);
    Eigen::Vector3d v_perp = v1.cross(v2);
    Eigen::Vector3d v_proj = v1.dot(v2)*v2;
    cout << "v1 x v2 \n" << v_perp << endl;
    cout << " v1 . v2 \n" << v_proj << endl;

    Eigen::Rotation2D<double> r(M_PI/4);
    cout << " rotation 2d : \n " << r.matrix() << endl;
    cout << " rotation 3d : \n " << T.matrix() << endl;

    // motion of a point
    Eigen::Vector2d pt_x(4, 0);
    cout << "2d point in rotated axes converted to base frame : \n" << r*pt_x << endl;
    cout << "2d point in base frame converted to rotated axes : \n " << (pt_x.transpose()*r.matrix()).transpose() << endl;
    cout << "2d point in base frame converted to rotated axes : \n " << r.inverse()*pt_x << endl; 

    Eigen::Translation2d tt(4, 0);
    Eigen::Translation3d tt3(0, 4 , 0);
    // Transformation obeys the natural sequence in which they are done
    // like we write in mathematics. 
    cout << "2d transformation in (r*tt) : \n" << (r*tt).matrix() <<endl;
    cout << "2d transformation in (tt*r) : \n" << (tt*r).matrix() <<endl;

    cout << "3d transformation (R * tt 3) : \n" << (T*tt3).matrix() <<endl;
    cout << " 3d Transformation (tt3 * R ) : \n" << (tt3*T).matrix() <<endl;

    Eigen::Isometry2d I = r*tt;
    Eigen::Isometry3d I3(T);
    cout << " Translation transformation : \n " << tt.translation() << endl;
    cout << " Pt x  homogeneous : \n" << pt_x.homogeneous() << endl;
    cout << " Isometry 2d : \n " << I.matrix() << endl;
    cout << " Isometry 3d at origin : \n " << I3.matrix() << endl;
}