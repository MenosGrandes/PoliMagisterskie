#include "Sphere.h"

Sphere::Sphere(Vector3Bf center, d_type::Bfloat radius):m_center(center),m_radius(radius),IRaycastable()
{
    m_sqRadius=m_radius*m_radius;
}


Vector3Bf Sphere::getCenter() const
{
    return m_center;
}

d_type::Buint Sphere::getRadius() const
{
    return m_radius;
}

void Sphere::setCenter(const Vector3Bf center)
{
    m_center=center;
}

void Sphere::setRadius(d_type::Buint radius)
{
    m_radius=radius;
}

Vector3BfVector Sphere::intersect(const Ray& ray) const
{
//http://stackoverflow.com/questions/6533856/ray-sphere-intersection


#define M_INTER
#ifdef MY_INTER

    d_type::Bfloat a=1;
    d_type::Bfloat b=2.0f*Vector3Bf::dotProduct(ray.getDestination(),ray.getOrigin() )- Vector3Bf::dotProduct(ray.getOrigin(),m_center ) ;

    d_type::Bfloat lengthSqRayOriginSphereCenter=(ray.getOrigin()-m_center).lengthSquared();

    d_type::Bfloat c=lengthSqRayOriginSphereCenter - m_sqRadius;

    d_type::Bfloat delta=b*b - 4*a*c;
    std::cout<<delta<<"\n";
#endif // MY_INTER
#ifdef M_INTER

    FastSqrt sqrtf;
    Vector3Bf direction=ray.getDirection();
    Vector3Bf oc=ray.getOrigin()-m_center;

    d_type::Bfloat a=direction.lengthSquared();

    d_type::Bfloat b=(Vector3Bf::dotProduct(oc,direction*2.0f));

    d_type::Bfloat c=oc.lengthSquared() - m_sqRadius;

    d_type::Bfloat delta=b*b - 4*a*c;
    std::vector<Vector3Bf> vec;
    if(delta>0)
    {

        d_type::Bfloat t1 = ((-1)*b-sqrtf.sqrt7(delta))/(2*a);
        if(t1> F_EPSILON)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t1*direction));
        }
        d_type::Bfloat t2 = ((-1)*b+sqrtf.sqrt7(delta))/(2*a);

        if(t2>F_EPSILON)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t2*direction));
        }

    }
    else if(delta==0)
    {
        d_type::Bfloat t = -b/(2*a);
        if(t>0)
        {
            vec.push_back(Vector3Bf(ray.getOrigin()+t*direction));
        }

    }
    return vec;



#endif // M_INTER
#ifdef GLM_INTERSECTION

    d_type::Bfloat Epsilon = std::numeric_limits<d_type::Bfloat>::epsilon();

    Vector3Bf diff= m_center- ray.getOrigin(); // difference between origin of RAY and center of Sphere
    d_type::Bfloat t0= (Vector3Bf::dotProduct(diff,ray.getNormalizedDirection())); // -
    d_type::Bfloat dSquared = Vector3Bf::dotProduct(diff, diff) - (t0 * t0);
    if( dSquared > m_sqRadius )
    {
        return false;
    }
    d_type::Bfloat t1 = sqrtf( m_sqRadius - dSquared );
    dist = t0 > t1 + Epsilon ? t0 - t1 : t0 + t1;
    return dist > Epsilon;
#endif // GLM_INTERSECTION
#ifdef DISCRIMINANTA_INTERSECTION

    d_type::Bfloat a=Vector3Bf::dotProduct(ray.getDirectionMinusOrigin(),ray.getDirectionMinusOrigin());
    d_type::Bfloat b=2*ray.getDirectionMinusOrigin().x*(ray.getDirection().x-m_center.x)+
                     2*ray.getDirectionMinusOrigin().y*(ray.getDirection().y-m_center.y)+
                     2*ray.getDirectionMinusOrigin().z*(ray.getDirection().z-m_center.z);

    d_type::Bfloat c=Vector3Bf::dotProduct(m_center,m_center) +Vector3Bf::dotProduct(ray.getOrigin(),ray.getOrigin()) +( -2*(Vector3Bf::dotProduct(m_center,ray.getOrigin())));
    d_type::Bfloat discriminanta =b*b - 4* a*c;

    if(discriminanta<0)
    {
        dist=0;
        return RAY_MISS;
    }
    else if (discriminanta==0)
    {
        dist=(-b-0)/(2*a);
        return RAY_HIT_POINT;
    }
    else
    {
        dist=(-b-sqrtf(discriminanta))/(2*a);
        return  RAY_HIT_POINTS;

    }
#endif // DISCRIMINANTA_INTERSECTION
#ifdef FTIMS_INTERSECTION
    Vector3Bf v_tmp=ray.getOrigin() - m_center; // (0,0,-20) - (0,0,0) = (0,0,-20) ||
    d_type::Bfloat b= -(Vector3Bf::dotProduct(v_tmp,ray.getDirection())); // -(0,0,0) ||
    d_type::Bfloat det=( b*b )-Vector3Bf::dotProduct(v_tmp,v_tmp) - (m_sqRadius); // (0*0)-(400) + 100 = -396.837708 ||

    if(det>0)
    {
        det=sqrtf(det);
        d_type::Bfloat i1=b-det;
        d_type::Bfloat i2=b+det;
        if(i2 > 0)
        {
            if(i1<0)
            {
                if(i2<dist)
                {
                    dist=i2;
                    return RAY_HIT_POINTS;
                }
            }
            else
            {
                if(i1< dist)
                {
                    dist=i1;
                    return RAY_HIT_POINT;
                }

            }
        }
    }
    dist=0;
    return RAY_MISS;


#endif // FTIMS_INTERSECTION
#ifdef BLABLA_INTERSECTION
    const Vector displacement = vantage - Center();
    const double a = direction.MagnitudeSquared();
    const double b = 2.0 * DotProduct(direction, displacement);
    const double c = displacement.MagnitudeSquared() - radius*radius;

    // Calculate the radicand of the quadratic equation solution formula.
    // The radicand must be non-negative for there to be real solutions.
    const double radicand = b*b - 4.0*a*c;
    if (radicand >= 0.0)
    {
        // There are two intersection solutions, one involving
        // +sqrt(radicand), the other -sqrt(radicand).
        // Check both because there are weird special cases,
        // like the camera being inside the sphere,
        // or the sphere being behind the camera (invisible).
        const double root = sqrt(radicand);
        const double denom = 2.0 * a;
        const double u[2] =
        {
            (-b + root) / denom,
            (-b - root) / denom
        };

        for (int i=0; i < 2; ++i)
        {
            if (u[i] > EPSILON)
            {
                Intersection intersection;
                const Vector vantageToSurface = u[i] * direction;
                intersection.point = vantage + vantageToSurface;

                // The normal vector to the surface of
                // a sphere is outward from the center.
                intersection.surfaceNormal =
                    (intersection.point - Center()).UnitVector();

                intersection.distanceSquared =
                    vantageToSurface.MagnitudeSquared();

                intersection.solid = this;
                intersectionList.push_back(intersection);
            }
        }
    }
#endif // BLABLA_INTERSECTION

}
