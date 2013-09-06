/*
 * File:   Vector2.cpp
 * Author: JoPe
 *
 * Created on 6 de septiembre de 2013, 15:16
 */

#include "Vector2.hpp"

#include <cmath>

namespace vec
{
    Vector2::Vector2( double const& i_x, double const& i_y )
    : x( i_x )
    , y( i_y )
    {}

    void Vector2::Add( Vector2 const& i_rhs )
    {
        x += i_rhs.x;
        y += i_rhs.y;
    }

    void Vector2::Subtract( Vector2 const& i_rhs )
    {
        x -= i_rhs.x;
        y -= i_rhs.y;
    }

    void Vector2::Scale( double const& i_scaleFactor )
    {
        x *= i_scaleFactor;
        y *= i_scaleFactor;
    }

    double Vector2::Magnitude() const
    {
        return sqrt( x * x + y * y );
    }

    double Vector2::DotProduct( Vector2 const& i_rhs ) const
    {
        return ( x * i_rhs.x + y * i_rhs.y );
    }

    bool Vector2::Equals( Vector2 const& i_rhs ) const
    {
        return ( x == i_rhs.x && y == i_rhs.y );
    }

    Vector2 Add( Vector2 i_lhs, Vector2 const& i_rhs )
    {
        i_lhs.Add( i_rhs );
        return i_lhs;
    }

    Vector2 Subtract( Vector2 i_lhs, Vector2 const& i_rhs )
    {
        i_lhs.Subtract( i_rhs );
        return i_lhs;
    }

    Vector2 Scale( Vector2 i_lhs, double const& i_rhs )
    {
        i_lhs.Scale( i_rhs );
        return i_lhs;
    }

    double DotProduct( Vector2 const& i_lhs, Vector2 const& i_rhs )
    {
        return i_lhs.DotProduct( i_rhs );
    }
}