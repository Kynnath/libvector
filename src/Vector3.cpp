/*
 * File:   Vector3.cpp
 * Author: JoPe
 *
 * Created on 25 de agosto de 2013, 17:02
 */

#include "VEC/Vector3.hpp"

#include <cmath>

namespace vec
{
    Vector3::Vector3( double const& i_x, double const& i_y, double const& i_z )
    : x( i_x )
    , y( i_y )
    , z( i_z )
    {}

    void Vector3::Add( Vector3 const& i_rhs )
    {
        x += i_rhs.x;
        y += i_rhs.y;
        z += i_rhs.z;
    }

    void Vector3::Subtract( Vector3 const& i_rhs )
    {
        x -= i_rhs.x;
        y -= i_rhs.y;
        z -= i_rhs.z;
    }

    void Vector3::Scale( double const& i_scaleFactor )
    {
        x *= i_scaleFactor;
        y *= i_scaleFactor;
        z *= i_scaleFactor;
    }

    double Vector3::Magnitude() const
    {
        return sqrt( x * x + y * y + z * z );
    }

    double Vector3::DotProduct( Vector3 const& i_rhs ) const
    {
        return ( x * i_rhs.x + y * i_rhs.y + z * i_rhs.z );
    }

    bool Vector3::Equals( Vector3 const& i_rhs ) const
    {
        return ( x == i_rhs.x && y == i_rhs.y && z == i_rhs.z );
    }

    Vector3 Add( Vector3 i_lhs, Vector3 const& i_rhs )
    {
        i_lhs.Add( i_rhs );
        return i_lhs;
    }

    Vector3 Subtract( Vector3 i_lhs, Vector3 const& i_rhs )
    {
        i_lhs.Subtract( i_rhs );
        return i_lhs;
    }

    Vector3 Scale( Vector3 i_lhs, double const& i_rhs )
    {
        i_lhs.Scale( i_rhs );
        return i_lhs;
    }

    double DotProduct( Vector3 const& i_lhs, Vector3 const& i_rhs )
    {
        return i_lhs.DotProduct( i_rhs );
    }

    Vector3 CrossProduct( Vector3 const& i_lhs, Vector3 const& i_rhs )
    {
        double xComponent ( i_lhs.y * i_rhs.z - i_lhs.z * i_rhs.y );
        double yComponent ( i_lhs.z * i_rhs.x - i_lhs.x * i_rhs.z );
        double zComponent ( i_lhs.x * i_rhs.y - i_lhs.y * i_rhs.x );

        return Vector3( xComponent, yComponent, zComponent );
    }
}
