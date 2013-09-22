/*
 * File:   Vector3.hpp
 * Author: JoPe
 *
 * Created on 25 de agosto de 2013, 17:02
 */

#ifndef VECTOR3_HPP
#define	VECTOR3_HPP

namespace vec
{
    struct Vector3
    {
        double x, y, z;

        Vector3() = default;
        Vector3( double const& i_x, double const& i_y, double const& i_z );
        void Add( Vector3 const& i_rhs );
        void Subtract( Vector3 const& i_rhs );
        void Scale( double const& i_scaleFactor );
        double Magnitude() const;
        double DotProduct( Vector3 const& i_rhs ) const;
        bool Equals( Vector3 const& i_rhs ) const;
    };

    Vector3 Add( Vector3 i_lhs, Vector3 const& i_rhs );
    Vector3 Subtract( Vector3 i_lhs, Vector3 const& i_rhs );
    Vector3 Scale( Vector3 i_lhs, double const& i_rhs );
    double DotProduct( Vector3 const& i_lhs, Vector3 const& i_rhs );
    Vector3 CrossProduct( Vector3 const& i_lhs, Vector3 const& i_rhs );
}
#endif	/* VECTOR3_HPP */

