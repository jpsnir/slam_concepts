#include <iostream>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

using namespace Eigen;
using namespace std;

int main(){
    Matrix3d rot_mat = Matrix3d::Identity();
    AngleAxisd rotation_vec(M_PI/4, Vector3d(0, 0, 1));
    cout.precision(3);
    Matrix3d rotation_matrix = rotation_vec.toRotationMatrix();
    cout << " Rotation matrix = \n " << rotation_matrix << endl;
    cout << " Rotation matrix with matrix function = \n " << rotation_vec.matrix() << endl; 
    Vector3d v(1, 0, 0);
    Vector3d v_rotated = rotation_vec*v;
    cout << " v rotated = \n " << v_rotated << endl;

    Vector3d euler_angles = rotation_matrix.eulerAngles(2, 1, 0); // zyx order - roll pitch yaw order. 
    cout << " yaw pitch roll = " << euler_angles.transpose() << endl;

    Isometry3d T = Isometry3d::Identity();
    T.setIdentity();
    T.rotate(rotation_vec).translate(v);
    cout << " transformation after rotation : \n" << T.matrix() << endl;

    T.setIdentity();
    T.rotate(rotation_vec).pretranslate(v);
    cout << " transformation : : \n" << T.matrix() << endl;

    T.setIdentity();
    T.translate(v).rotate(rotation_vec);
    cout << " transformation  : \n" << T.matrix() << endl;
    Eigen::Rotation2Dd r(M_PI/2);
    Eigen::Projective2d P  =  Eigen::Projective2d::Identity();
    cout << "Projective transform : \n" << P.matrix() << endl;
    cout << "Projective Transform r, t, s : \n" << (P.rotate(r).translate(Vector2d(1,2))).matrix() << endl;

    Quaterniond q1(-0.5, 0.4, -0.1, 0.2); q1.normalize();
    Quaterniond q2 (0.35, 0.2, 0.3, 0.1); q2.normalize();

    Eigen::Isometry3d T1 = Isometry3d::Identity();
    T1.rotate(q1).pretranslate(Vector3d(0.3, 0.1, 0.1));
    Eigen::Isometry3d T2 = Isometry3d::Identity();
    T2.rotate(q2).pretranslate(Vector3d(-0.1, 0.5, 0.3));
    Vector3d p1(0.5, 0, 0.2);
    Vector3d p2 = T2*T1.inverse()*p1;
    cout << "point transformed to second coordinate frame : \n " << p2 << endl;

}
