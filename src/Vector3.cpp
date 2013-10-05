/*
 * File:   Vector3.cpp
 * Author: JoPe
 *
 * Created on 25 de agosto de 2013, 17:02
 */

#include "VEC/Vector3.hpp"

#include <cassert>
#include <cmath>

namespace vec
{
    double & Vector3::operator []( int const& i_arrayIndex )
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 3 );
        return m_data[ i_arrayIndex ];
    }

    double const& Vector3::operator []( int const& i_arrayIndex ) const
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 3 );
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
        return sqrt( DotProduct( *this ) );
    }

    double Vector3::DotProduct( Vector3 const& i_rhs ) const
    {
        return ( m_data[ 0 ] * i_rhs[ 0 ] + m_data[ 1 ] * i_rhs[ 1 ] + m_data[ 2 ] * i_rhs[ 2 ] );
    }

    bool Vector3::Equals( Vector3 const& i_rhs ) const
    {
        return ( m_data[ 0 ] == i_rhs[ 0 ] && m_data[ 1 ] == i_rhs[ 1 ] && m_data[ 2 ] == i_rhs[ 2 ] );
    }

    void Vector3::Normalize()
    {
        double const magnitude ( Magnitude() );

        assert( magnitude != 0.0 );

        m_data[ 0 ] /= magnitude;
        m_data[ 1 ] /= magnitude;
        m_data[ 2 ] /= magnitude;
    }

    Vector3 Add( Vector3 c_lhs, Vector3 const& i_rhs )
    {
        c_lhs.Add( i_rhs );
        return c_lhs;
    }

    Vector3 Subtract( Vector3 c_lhs, Vector3 const& i_rhs )
    {
        c_lhs.Subtract( i_rhs );
        return c_lhs;
    }

    Vector3 Scale( Vector3 c_lhs, double const& i_rhs )
    {
        c_lhs.Scale( i_rhs );
        return c_lhs;
    }

    double Magnitude( Vector3 const& i_vector )
    {
        return i_vector.Magnitude();
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

    Vector3 Normalize( Vector3 c_vector )
    {
        c_vector.Normalize();
        return c_vector;
    }
}
