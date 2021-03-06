/*
 * File:   Vector3.cpp
 * Author: JoPe
 *
 * Created on 25 de agosto de 2013, 17:02
 */

#include "Vector3.hpp"

#include <cassert>
#include <cmath>
#include <cstring>

namespace vec
{
    double & Vector3::operator []( int const& i_arrayIndex )
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 3 );
        return m_data[ (long long unsigned int)i_arrayIndex ];
    }

    double const& Vector3::operator []( int const& i_arrayIndex ) const
    {
        assert( i_arrayIndex >= 0 && i_arrayIndex < 3 );
        return m_data[ (long long unsigned int)i_arrayIndex ];
    }

    Vector3 & Vector3::Add( Vector3 const& i_rhs )
    {
        m_data[ 0 ] += i_rhs[ 0 ];
        m_data[ 1 ] += i_rhs[ 1 ];
        m_data[ 2 ] += i_rhs[ 2 ];
        return *this;
    }

    Vector3 & Vector3::Subtract( Vector3 const& i_rhs )
    {
        m_data[ 0 ] -= i_rhs[ 0 ];
        m_data[ 1 ] -= i_rhs[ 1 ];
        m_data[ 2 ] -= i_rhs[ 2 ];
        return *this;
    }

    Vector3 & Vector3::Scale( double const& i_scaleFactor )
    {
        m_data[ 0 ] *= i_scaleFactor;
        m_data[ 1 ] *= i_scaleFactor;
        m_data[ 2 ] *= i_scaleFactor;
        return *this;
    }

    double Vector3::DotProduct( Vector3 const& i_rhs ) const
    {
        return ( m_data[ 0 ] * i_rhs[ 0 ] + m_data[ 1 ] * i_rhs[ 1 ] + m_data[ 2 ] * i_rhs[ 2 ] );
    }

    double Vector3::MagnitudeSquared() const
    {
        return DotProduct( *this );
    }

    double Vector3::Magnitude() const
    {
        return sqrt( MagnitudeSquared() );
    }

    bool Vector3::Equals( Vector3 const& i_rhs ) const
    {
        return ( memcmp( this, &i_rhs, sizeof( Vector3 ) ) == 0 );
    }

    Vector3 & Vector3::Normalize()
    {
        double const magnitude ( Magnitude() );

        assert( magnitude > 0.0 );

        m_data[ 0 ] /= magnitude;
        m_data[ 1 ] /= magnitude;
        m_data[ 2 ] /= magnitude;

        return *this;
    }

    Vector3 Add( Vector3 c_lhs, Vector3 const& i_rhs )
    {
        return c_lhs.Add( i_rhs );
    }

    Vector3 Subtract( Vector3 c_lhs, Vector3 const& i_rhs )
    {
        return c_lhs.Subtract( i_rhs );
    }

    Vector3 Scale( Vector3 c_lhs, double const& i_rhs )
    {
        return c_lhs.Scale( i_rhs );
    }

    double DotProduct( Vector3 const& i_lhs, Vector3 const& i_rhs )
    {
        return i_lhs.DotProduct( i_rhs );
    }

    double MagnitudeSquared( Vector3 const& i_vector )
    {
        return i_vector.MagnitudeSquared();
    }

    double Magnitude( Vector3 const& i_vector )
    {
        return i_vector.Magnitude();
    }

    Vector3 CrossProduct( Vector3 const& i_lhs, Vector3 const& i_rhs )
    {
        double const xComponent ( i_lhs[ 1 ] * i_rhs[ 2 ] - i_lhs[ 2 ] * i_rhs[ 1 ] );
        double const yComponent ( i_lhs[ 2 ] * i_rhs[ 0 ] - i_lhs[ 0 ] * i_rhs[ 2 ] );
        double const zComponent ( i_lhs[ 0 ] * i_rhs[ 1 ] - i_lhs[ 1 ] * i_rhs[ 0 ] );

        return Vector3 { { xComponent, yComponent, zComponent } };
    }

    Vector3 Normalize( Vector3 c_vector )
    {
        return c_vector.Normalize();
    }
}
