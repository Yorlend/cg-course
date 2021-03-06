#include <cmath>
#include "matrix.hpp"

Matrix::Matrix()
{
    for (double &elem : data)
        elem = 0.0;
}

Matrix::Matrix(const double *mat)
{
    for (int i = 0; i < 16; i++)
        data[i] = mat[i];
}

Matrix Matrix::identity()
{
    Matrix res = Matrix();

    for (int i = 0; i < 16; i += 5)
        res.data[i] = 1;

    return res;
}

Matrix Matrix::translate(double dx, double dy, double dz)
{
    Matrix res = identity();

    res.data[3] = dx;
    res.data[7] = dy;
    res.data[11] = dz;

    return res;
}

Matrix Matrix::translate(const Vector &offset)
{
    return translate(offset.getX(), offset.getY(), offset.getZ());
}

Matrix Matrix::rotate(const Vector &axis, double angle)
{
    Matrix res = identity();
    double x = axis.getX(), y = axis.getY(), z = axis.getZ();
    double c = std::cos(angle), s = std::sin(angle);
    double imc = 1 - c;

    res.data[0] = c + x * x * imc;
    res.data[1] = x * y * imc - z * s;
    res.data[2] = x * z * imc + y * s;
    res.data[4] = x * y * imc + z * s;
    res.data[5] = c + y * y * imc;
    res.data[6] = y * z * imc - x * s;
    res.data[8] = x * z * imc - y * s;
    res.data[9] = y * z * imc + x * s;
    res.data[10] = c + z * z * imc;

    return res;
}

Matrix Matrix::rotate(const Vector &angles)
{
    auto mx = rotate(Vector(1, 0, 0), angles.getX());
    auto my = rotate(Vector(0, 1, 0), angles.getY());
    auto mz = rotate(Vector(0, 0, 1), angles.getZ());

    return mz * my * mx;
}

Matrix Matrix::rotate(const Vector &offset, const Vector &angles)
{
    return translate(-offset) * rotate(angles) * translate(offset);
}

Matrix Matrix::scale(double fx, double fy, double fz)
{
    Matrix res = identity();

    res.data[0] = fx;
    res.data[5] = fy;
    res.data[10] = fz;

    return res;
}

Matrix Matrix::scale(const Vector &factors)
{
    return scale(factors.getX(), factors.getY(), factors.getZ());
}

Matrix Matrix::scale(const Vector &offset, const Vector &factors)
{
    return translate(-offset) * scale(factors) * translate(offset);
}

Matrix Matrix::perspective(double fov, double near, double far)
{
    Matrix res;
    double s = 1 / std::tan(fov / 2);

    res.data[0] = s;
    res.data[5] = s;
    res.data[10] = far / (far - near);
    res.data[11] = near * far / (near - far);
    res.data[14] = 1;

    return res;
}

double Matrix::det() const
{
    double res = 0;

    res += data[0] * data[5] * data[10] * data[15];
    res += data[1] * data[6] * data[11] * data[12];
    res += data[2] * data[7] * data[8] * data[13];
    res += data[3] * data[4] * data[9] * data[14];

    res -= data[0] * data[7] * data[10] * data[13];
    res -= data[1] * data[4] * data[11] * data[14];
    res -= data[2] * data[5] * data[8] * data[15];
    res -= data[3] * data[6] * data[9] * data[12];

    return res;
}

Matrix Matrix::operator*(const Matrix &right) const
{
    Matrix res;

    for (int i = 0; i < 16; i += 4)
        for (int j = 0; j < 4; j++)
            for (int k = 0, k4 = 0; k < 4; k++, k4 += 4)
                res.data[i + j] += data[i + k] * right.data[k4 + j];

    return res;
}

Matrix Matrix::operator*(double val) const
{
    Matrix res;

    for (int i = 0; i < 16; i++)
        res.data[i] = val * data[i];

    return res;
}

Vector Matrix::operator*(const Vector &vec) const
{
    return Vector(
        vec.getX() * data[0] + vec.getY() * data[1] + vec.getZ() * data[2] + vec.getW() * data[3],
        vec.getX() * data[4] + vec.getY() * data[5] + vec.getZ() * data[6] + vec.getW() * data[7],
        vec.getX() * data[8] + vec.getY() * data[9] + vec.getZ() * data[10] + vec.getW() * data[11],
        vec.getX() * data[12] + vec.getY() * data[13] + vec.getZ() * data[14] + vec.getW() * data[15]);
}

Matrix Matrix::inverse() const
{
    Matrix inv;

    inv.data[0] = data[5] * data[10] * data[15] -
                  data[5] * data[11] * data[14] -
                  data[9] * data[6] * data[15] +
                  data[9] * data[7] * data[14] +
                  data[13] * data[6] * data[11] -
                  data[13] * data[7] * data[10];

    inv.data[4] = -data[4] * data[10] * data[15] +
                  data[4] * data[11] * data[14] +
                  data[8] * data[6] * data[15] -
                  data[8] * data[7] * data[14] -
                  data[12] * data[6] * data[11] +
                  data[12] * data[7] * data[10];

    inv.data[8] = data[4] * data[9] * data[15] -
                  data[4] * data[11] * data[13] -
                  data[8] * data[5] * data[15] +
                  data[8] * data[7] * data[13] +
                  data[12] * data[5] * data[11] -
                  data[12] * data[7] * data[9];

    inv.data[12] = -data[4] * data[9] * data[14] +
                   data[4] * data[10] * data[13] +
                   data[8] * data[5] * data[14] -
                   data[8] * data[6] * data[13] -
                   data[12] * data[5] * data[10] +
                   data[12] * data[6] * data[9];

    inv.data[1] = -data[1] * data[10] * data[15] +
                  data[1] * data[11] * data[14] +
                  data[9] * data[2] * data[15] -
                  data[9] * data[3] * data[14] -
                  data[13] * data[2] * data[11] +
                  data[13] * data[3] * data[10];

    inv.data[5] = data[0] * data[10] * data[15] -
                  data[0] * data[11] * data[14] -
                  data[8] * data[2] * data[15] +
                  data[8] * data[3] * data[14] +
                  data[12] * data[2] * data[11] -
                  data[12] * data[3] * data[10];

    inv.data[9] = -data[0] * data[9] * data[15] +
                  data[0] * data[11] * data[13] +
                  data[8] * data[1] * data[15] -
                  data[8] * data[3] * data[13] -
                  data[12] * data[1] * data[11] +
                  data[12] * data[3] * data[9];

    inv.data[13] = data[0] * data[9] * data[14] -
                   data[0] * data[10] * data[13] -
                   data[8] * data[1] * data[14] +
                   data[8] * data[2] * data[13] +
                   data[12] * data[1] * data[10] -
                   data[12] * data[2] * data[9];

    inv.data[2] = data[1] * data[6] * data[15] -
                  data[1] * data[7] * data[14] -
                  data[5] * data[2] * data[15] +
                  data[5] * data[3] * data[14] +
                  data[13] * data[2] * data[7] -
                  data[13] * data[3] * data[6];

    inv.data[6] = -data[0] * data[6] * data[15] +
                  data[0] * data[7] * data[14] +
                  data[4] * data[2] * data[15] -
                  data[4] * data[3] * data[14] -
                  data[12] * data[2] * data[7] +
                  data[12] * data[3] * data[6];

    inv.data[10] = data[0] * data[5] * data[15] -
                   data[0] * data[7] * data[13] -
                   data[4] * data[1] * data[15] +
                   data[4] * data[3] * data[13] +
                   data[12] * data[1] * data[7] -
                   data[12] * data[3] * data[5];

    inv.data[14] = -data[0] * data[5] * data[14] +
                   data[0] * data[6] * data[13] +
                   data[4] * data[1] * data[14] -
                   data[4] * data[2] * data[13] -
                   data[12] * data[1] * data[6] +
                   data[12] * data[2] * data[5];

    inv.data[3] = -data[1] * data[6] * data[11] +
                  data[1] * data[7] * data[10] +
                  data[5] * data[2] * data[11] -
                  data[5] * data[3] * data[10] -
                  data[9] * data[2] * data[7] +
                  data[9] * data[3] * data[6];

    inv.data[7] = data[0] * data[6] * data[11] -
                  data[0] * data[7] * data[10] -
                  data[4] * data[2] * data[11] +
                  data[4] * data[3] * data[10] +
                  data[8] * data[2] * data[7] -
                  data[8] * data[3] * data[6];

    inv.data[11] = -data[0] * data[5] * data[11] +
                   data[0] * data[7] * data[9] +
                   data[4] * data[1] * data[11] -
                   data[4] * data[3] * data[9] -
                   data[8] * data[1] * data[7] +
                   data[8] * data[3] * data[5];

    inv.data[15] = data[0] * data[5] * data[10] -
                   data[0] * data[6] * data[9] -
                   data[4] * data[1] * data[10] +
                   data[4] * data[2] * data[9] +
                   data[8] * data[1] * data[6] -
                   data[8] * data[2] * data[5];

    double det = 1 / (data[0] * inv.data[0] + data[1] * inv.data[4] + data[2] * inv.data[8] + data[3] * inv.data[12]);

    for (double &i : inv.data)
        i *= det;

    return inv;
}

double Matrix::at(size_t row, size_t col) const
{
    return data[row * 4 + col];
}

Vector Matrix::row(size_t index) const
{
    return Vector(at(index, 0), at(index, 1), at(index, 2), at(index, 3));
}

Vector Matrix::col(size_t index) const
{
    return Vector(at(0, index), at(1, index), at(2, index), at(3, index));
}

Matrix Matrix::fpsModel(const Vector &eye, Vector look)
{
    look.normalize();

    double pitch = std::acos(-look.getZ() / std::sqrt(1 - look.getY()));
    double yaw = std::asin(look.getY());

    return fpsModel(eye, pitch, yaw);
}

Matrix Matrix::fpsModel(const Vector &eye, double pitch, double yaw)
{
    double cosPitch = std::cos(pitch);
    double sinPitch = std::sin(pitch);
    double cosYaw = std::cos(yaw);
    double sinYaw = std::sin(yaw);

    Vector x_axis = Vector(cosYaw, 0, -sinYaw);
    Vector y_axis = Vector(sinYaw * sinPitch, cosPitch, cosYaw * sinPitch);
    Vector z_axis = Vector(sinYaw * cosPitch, -sinPitch, cosPitch * cosYaw);

    Matrix res;

    res.data[0] = x_axis.getX();
    res.data[1] = x_axis.getY();
    res.data[2] = x_axis.getZ();
    res.data[3] = -x_axis.dot(eye);

    res.data[4] = y_axis.getX();
    res.data[5] = y_axis.getY();
    res.data[6] = y_axis.getZ();
    res.data[7] = -y_axis.dot(eye);

    res.data[8] = z_axis.getX();
    res.data[9] = z_axis.getY();
    res.data[10] = z_axis.getZ();
    res.data[11] = -z_axis.dot(eye);

    res.data[15] = 1;

    return res.inverse();
}

Matrix Matrix::trsModel(const Vector &position, const Vector &rotation, const Vector &scale)
{
    return Matrix::scale(scale) * rotate(rotation) * translate(position);
}

Matrix operator*(double val, const Matrix &mat)
{
    return mat * val;
}

Vector operator*(const Vector &vec, const Matrix &mat)
{
    return mat * vec;
}
