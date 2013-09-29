/*
 * File:   Vector2.hpp
 * Author: JoPe
 *
 * Created on 6 de septiembre de 2013, 15:16
 */

#ifndef VECTOR2_HPP
#define	VECTOR2_HPP

namespace vec
{
    struct Vector2
    {
        double m_data[ 2 ];

        Vector2() = default;
        double & operator[]( int const& i_arrayIndex );
        double const& operator[]( int const& i_arrayIndex ) const;
        void Add( Vector2 const& i_rhs );
        void Subtract( Vector2 const& i_rhs );
        void Scale( double const& i_scaleFactor );
        double Magnitude() const;
        double DotProduct( Vector2 const& i_rhs ) const;
        bool Equals( Vector2 const& i_rhs ) const;
        void Normalize();
    };

    Vector2 Add( Vector2 c_lhs, Vector2 const& i_rhs );
    Vector2 Subtract( Vector2 c_lhs, Vector2 const& i_rhs );
    Vector2 Scale( Vector2 c_lhs, double const& i_rhs );
    double DotProduct( Vector2 const& i_lhs, Vector2 const& i_rhs );
    Vector2 Normalize( Vector2 c_vector );
}

#endif	/* VECTOR2_HPP */

