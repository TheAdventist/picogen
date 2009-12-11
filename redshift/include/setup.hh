//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Copyright (C) 2009  Sebastian Mach (*1983)
// * mail: phresnel/at/gmail/dot/com
// * http://phresnel.org
// * http://picogen.org
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#ifndef SETUP_HH_INCLUDED_20090303
#define SETUP_HH_INCLUDED_20090303

#include <kallisto/common.hh>

#define DefineFinalizer(x) \
        class x##Finalize { \
        private: \
                friend class x ; \
                x##Finalize() {} \
                x##Finalize(x##Finalize const &) {} \
        }
#define DoFinalize(x) virtual x##Finalize


///////////////////////////////////////////////////////////////////////////////
// Assimilate kallisto-types and define some convenience types.
///////////////////////////////////////////////////////////////////////////////
namespace redshift {

        enum {
                ALLOW_LOGSPAM = 1
        };

        typedef float real_t;
        typedef kallisto::fixed_point_t<int64_t,16>          fixed_point_t;        

        // Cartesian Types
        typedef kallisto::Point<kallisto::CARTESIAN,
                                fixed_point_t>               CartesianPoint;
        typedef kallisto::Normal<kallisto::CARTESIAN,real_t> CartesianNormal;
        typedef kallisto::Vector<kallisto::CARTESIAN,real_t> CartesianVector;


        // Std-Types
        typedef CartesianPoint  Point;
        typedef CartesianNormal Normal;
        typedef CartesianVector Vector;

        typedef kallisto::Sphere<Point,long double>  Sphere;
        typedef kallisto::Ray<Point,Vector>          Ray;
        typedef kallisto::OrthonormalBasis<Vector>   OrthonormalBasis;
        
}
        
namespace redshift {       
        // Makes function calls more save.
        // Pretty much like using the out-keyword in some other languages.
        // Note that 'out' is always explicit, while 'in' can be implicit.
        template <typename T> struct in {
                
                T const &value;
                
                in (T const &value_)
                : value (value_) {
                }
                
                inline T const * operator -> () const {
                        return &value;
                }
                
                inline T const & operator * () const {
                        return value;
                }
        };
        
        template <typename T> struct ref {
                
                T const &value;
                
                ref (T const &value_)
                : value (value_) {
                }
                
                inline T const * operator -> () const {
                        return &value;
                }
                
                inline T const & operator * () const {
                        return value;
                }
        };

        template <typename T> struct out {
                
                T &value;
                
                explicit out (T &value_)
                : value (value_) {
                }
                
                inline T * operator -> () {
                        return &value;
                }
                
                inline T & operator * () {
                        return value;
                }
        };
        
        template <typename T> inline in<T> in_ (T const &value) {
                return in<T> (value);
        }
        
        template <typename T> inline ref<T> ref_ (T &value) {
                return ref<T> (value);
        }
        
        template <typename T> inline out<T> out_ (T &value) {
                return out<T> (value);
        }
}

#include "basictypes/rgb.hh"
namespace redshift {
        //class Rgb;
        typedef Rgb Color;
}

///////////////////////////////////////////////////////////////////////////////
// Some constants.
///////////////////////////////////////////////////////////////////////////////
namespace redshift {
        namespace static_config {
                enum { debug = 0 }; // should be set by #define macro
        }
        
        namespace constants {
                template<typename T> inline T km2m (T const &v) {
                        return T(1000) * v;
                }
                static double const earth_radius_m     = km2m (12756.0);
                static double const sun_radius_m       = km2m (1.392 * 10.0e9);
                static double const jupiter_radius_m   = km2m (133708.0);
                //static float const sun_radius_km 1,3914
        }
}

#include "smart_ptr.hh"

#endif // SETUP_HH_INCLUDED_20090303
