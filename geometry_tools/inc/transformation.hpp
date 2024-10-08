#ifndef __TRANSFORMATION_HPP__
#define __TRANSFORMATION_HPP__

#include <Eigen/Dense>

#include "geometry_type.hpp"

/**
 * @brief Generates a rotation matrix for a rotation around the X-axis.
 *
 * @param phi The rotation angle in radians.
 * @return A 3x3 rotation matrix for a rotation around the X-axis.
 */
Eigen::Matrix3f R_x(float phi);

/**
 * @brief Generates a rotation matrix for a rotation around the Y-axis.
 *
 * @param beta The rotation angle in radians.
 * @return A 3x3 rotation matrix for a rotation around the Y-axis.
 */
Eigen::Matrix3f R_y(float beta);

/**
 * @brief Generates a rotation matrix for a rotation around the Z-axis.
 *
 * @param theta The rotation angle in radians.
 * @return A 3x3 rotation matrix for a rotation around the Z-axis.
 */
Eigen::Matrix3f R_z(float theta);

/**
 * @brief Calculates the combined rotation matrix from an array of Euler angles.
 *
 * @param angle An array of three floats representing the Euler angles
 * (in radians) in the order: [ROLL, PITCH, YAW].
 * @return A 3x3 rotation matrix representing the combined rotation.
 */
Eigen::Matrix3f rotationMatrix(float angle[]);

/**
 * @brief Calculates the combined rotation matrix from individual Euler angles.
 *
 * @param roll The rotation angle around the X-axis (in radians).
 * @param pitch The rotation angle around the Y-axis (in radians).
 * @param yaw The rotation angle around the Z-axis (in radians).
 * @return A 3x3 rotation matrix representing the combined rotation.
 */
Eigen::Matrix3f rotationMatrix(float roll, float pitch, float yaw);

/**
 * @brief Generates a translation matrix from a state array.
 *
 * @param state An array of three floats representing the translation distances 
 * in the order: [X, Y, Z].
 * @return A 4x4 translation matrix.
 */
Eigen::Matrix4f translationMatrix(float state[]);

/**
 * @brief Generates a translation matrix from individual x, y, and z values.
 *
 * @param x The translation distance along the X-axis.
 * @param y The translation distance along the Y-axis.
 * @param z The translation distance along the Z-axis.
 * @return A 4x4 translation matrix.
 */
Eigen::Matrix4f translationMatrix(float x, float y, float z);

/**
 * @brief Generates a scaling matrix from individual scaling factors.
 *
 * @param s_x The scaling factor along the X-axis.
 * @param s_y The scaling factor along the Y-axis.
 * @param s_z The scaling factor along the Z-axis.
 * @return A 4x4 scaling matrix.
 */
Eigen::Matrix4f scaleMatrix(float s_x, float s_y, float s_z);

/**
 * @brief Generates a scaling matrix from a scaling factors array.
 *
 * @param scale An array of three floats representing the scaling factors
 * in the order: [S_X, S_Y, S_Z].
 * @return A 4x4 scaling matrix.
 */
Eigen::Matrix4f scaleMatrix(float scale[]);

/**
 * @brief Extends a 3x3 rotation matrix to a 4x4 matrix for homogeneous coordinates.
 *
 * @param rotationMatrix A 3x3 rotation matrix.
 * @return A 4x4 matrix representing the same rotation, suitable for homogeneous coordinates.
 */
Eigen::Matrix4f extendRotationMatrix(const Eigen::Matrix3f &rotationMatrix);

/**
 * @brief Applies a combined rotation and translation transformation to a 3D vector.
 *
 * @param[out] out An array of three float pointers representing the 3D vector
 * to be transformed. The array should contain pointers to three float values.
 * @param[in] angle An array of three floats representing the Euler angles
 * (in radians) in the order: [ROLL, PITCH, YAW].
 * @param[in] state An array of three floats representing the translation distances
 * in the order: [X, Y, Z].
 */
void transformation(float out[], float angle[], float state[]);
#endif