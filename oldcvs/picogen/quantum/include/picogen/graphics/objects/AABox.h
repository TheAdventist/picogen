/***************************************************************************
 *            AABox.h
 *
 *  Sat May 24 11:42:00 2008
 *  Copyright  2008  Sebastian Mach
 *  seb@greenhybrid.net
 ****************************************************************************/

/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; version 3 of the License, or (at your
 *  option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */


#ifndef _AABOX_H
#define _AABOX_H

#ifndef INSIDE_OBJECTS_H
namespace picogen{ namespace graphics{ namespace objects{
#endif // #ifndef INSIDE_OBJECTS_H


class AABox : public picogen::graphics::objects::abstract::IIntersectable
{
    public:
        typedef enum face_t{
            x_negative=0,
            x_positive=1,
            y_negative=2,
            y_positive=3,
            z_negative=4,
            z_positive=5
        };

	private:
		typedef picogen::misc::prim::real real;
		typedef picogen::misc::geometrics::Vector3d Vector3d;
		typedef picogen::misc::geometrics::Ray Ray;
		typedef picogen::misc::geometrics::BoundingBox BoundingBox;
		typedef picogen::graphics::material::abstract::IBRDF IBRDF;
		typedef picogen::graphics::structs::intersection_t intersection_t;
		typedef picogen::graphics::objects::abstract::IIntersectable IIntersectable;
		typedef picogen::graphics::image::color::Color Color;
		typedef picogen::misc::functions::vector_to_scalar::PerlinNoise PerlinNoise;

	private:


        const picogen::graphics::material::abstract::IBRDF* brdfs[6];
        const picogen::graphics::material::abstract::IShader* shaders[6];
        bool enable[6];
        bool enableOutside_;

	public:
        AABox();
        virtual ~AABox();
		virtual bool Intersect( param_out(intersection_t,intersection), param_in(Ray,ray) ) const;

		void setBRDF( face_t face, const picogen::graphics::material::abstract::IBRDF* const brdf );
        void setShader( face_t face, const picogen::graphics::material::abstract::IShader* const shader );
        void setBRDF( const picogen::graphics::material::abstract::IBRDF* const brdf );
        void setShader( const picogen::graphics::material::abstract::IShader* const shader );
        void enableFace( face_t face, bool enable );
        void enableOutside( bool enable );
};

#ifndef INSIDE_OBJECTS_H
} } } // namespace picogen{ namespace graphics{ namespace objects{
#endif // #ifndef INSIDE_OBJECTS_H


#endif /* _AABOX_H */