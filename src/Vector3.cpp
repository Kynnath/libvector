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
    double & Vector3::operator []( int const& i_arrayIndex )
    {
        return m_data[ i_arrayIndex ];
    }

    double const& Vector3::operator []( int const& i_arrayIndex ) const
    {
        return m_data[ i_arrayIndex ];
    }

    void Vector3::Add( Vector3 const& i_rhs )
    {
        m_data[ 0 ] += i_rhs[ 0 ];
        m_data[ 1 ] += i_rhs[ 1 ];
        m_data[ 2 ] += i_rhs[ 2 ];
    }

    void Vector3::Subtract( Vector3 const& i_rhs )
    {
        m_data[ 0 ] -= i_rhs[ 0 ];
        m_data[ 1 ] -= i_rhs[ 1 ];
        m_data[ 2 ] -= i_rhs[ 2 ];
    }

    void Vector3::Scale( double const& i_scaleFactor )
    {
        m_data[ 0 ] *= i_scaleFactor;
        m_data[ 1 ] *= i_scaleFactor;
        m_data[ 2 ] *= i_scaleFactor;
    }

    double Vector3::Magnitude() const
    {
        return sqrt( m_data[ 0 ] * m_data[ 0 ] + m_data[ 1 ] * m_data[ 1 ] + m_data[ 2 ] * m_data[ 2 ] );
    }

    double Vector3::DotProduct( Vector3 const& i_rhs ) const
    {
        return ( m_data[ 0 ] * i_rhs[ 0 ] + m_data[ 1 ] * i_rhs[ 1 ] + m_data[ 2 ] * i_rhs[ 2 ] );
    }

    bool Vector3::Equals( Vector3 const& i_rhs ) const
    {
        return ( m_data[ 0 ] == i_rhs[ 0 ] && m_data[ 1 ] == i_rhs[ 1 ] && m_data[ 2 ] == i_rhs[ 2 ] );
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
        double const xComponent ( i_lhs[ 1 ] * i_rhs[ 2 ] - i_lhs[ 2 ] * i_rhs[ 1 ] );
        double const yComponent ( i_lhs[ 2 ] * i_rhs[ 0 ] - i_lhs[ 0 ] * i_rhs[ 2 ] );
        double const zComponent ( i_lhs[ 0 ] * i_rhs[ 1 ] - i_lhs[ 1 ] * i_rhs[ 0 ] );

        Vector3 const crossProduct = { { xComponent, yComponent, zComponent } };

        return crossProduct;
    }
}
