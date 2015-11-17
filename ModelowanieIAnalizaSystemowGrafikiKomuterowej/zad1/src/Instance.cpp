#include "Instance.h"
Matrix4 Instance::m_forwardMatrix;
Instance::Instance():IRaycastable(),
        m_object(nullptr),
        m_invMatrix(),
        m_transformoTexture(true),
        m_bbox(-1, 1, -1, 1, -1, 1)
{

}

Instance::~Instance()

{

}

Instance::Instance(const IRaycastable* obj_ptr):IRaycastable(),m_object(obj_ptr),m_bbox(obj_ptr->getBoundingBox())
{
}

Instance::Instance(const Instance& instance):IRaycastable(),m_object(instance.m_object),m_invMatrix(instance.m_invMatrix),m_transformoTexture(instance.m_transformoTexture),
        m_bbox(instance.m_bbox)

{

}



void Instance::computeBoundingBox(void)
{
        Box b = m_bbox;
        int size = 8;
        Vector3Bf p[size];

        p[0] = Vector3Bf(b.x0, b.y0, b.z0);
        p[1] = Vector3Bf(b.x1, b.y0, b.z0);
        p[2] = Vector3Bf(b.x0, b.y1, b.z0);
        p[3] = Vector3Bf(b.x1, b.y1, b.z0);
        p[4] = Vector3Bf(b.x0, b.y0, b.z1);
        p[5] = Vector3Bf(b.x1, b.y0, b.z1);
        p[6] = Vector3Bf(b.x0, b.y1, b.z1);
        p[7] = Vector3Bf(b.x1, b.y1, b.z1);


        d_type::Bfloat minX = 1.0E10, minY = 1.0E10, minZ = 1.0E10;
        d_type::Bfloat maxX = -1.0E10, maxY = -1.0E10, maxZ = -1.0E10;

        for (int j = 0; j < size; j++)
        {
                // order shouldn't matter here, right?
                p[j] = m_forwardMatrix * p[j];

                minX = std::min(minX, p[j].x);
                minY = std::min(minY, p[j].y);
                minZ = std::min(minZ, p[j].z);

                maxX = std::max(maxX, p[j].x);
                maxY = std::max(maxY, p[j].y);
                maxZ = std::max(maxZ, p[j].z);
        }

        m_bbox = Box(Vector3Bf(minX, minY, minZ), Vector3Bf(maxX, maxY, maxZ));

//      box = new Box(Point3D(minX, minY, minZ), Point3D(maxX, maxY, maxZ));
//      box->set_material(new Phong());
//      Box* bot_ptr = box;

        // reset forward_matrix for next instance to use
        m_forwardMatrix.set_identity();

}

Box Instance::getBoundingBox(void) const
{
return m_bbox;
}

d_type::BBool Instance::shadowHit(const Ray& ray, d_type::Bfloat& tmin) const
{
        Ray inv_ray(ray);
        inv_ray.getOrigin() = m_invMatrix * inv_ray.getOrigin();
        inv_ray.getDirection() = m_invMatrix * inv_ray.getDirection();

        if (m_object->shadowHit(inv_ray, tmin)) {

                if (m_object->getMaterial())
                        m_material = m_object->getMaterial();


                return (true);
        }
        return (false);

}

d_type::BBool Instance::intersect(const Ray& ray, double& tmin, Info& sr) const
{
         Ray inv_ray(ray);
        inv_ray.getOrigin() = m_invMatrix * inv_ray.getOrigin();
        inv_ray.getDirection() = m_invMatrix * inv_ray.getDirection();



        if (m_object->intersect(inv_ray, tmin, sr)) {
                sr.m_normal = m_invMatrix * sr.m_normal;
                Vector3Bf::normalize(sr.m_normal);

                // if object has material, use that
                if (m_object->getMaterial())
                        m_material = m_object->getMaterial();

                if (!m_transformoTexture)
                        sr.m_localHitPoint = ray.getOrigin() + tmin * ray.getDirection();

                return (true);
        }
        return (false);

}

void Instance::translate(const d_type::Bfloat dx, const d_type::Bfloat dy, const d_type::Bfloat dz)
{
        Matrix4 inv_translation_matrix;  //temp inverse translation matrix
        Matrix4 translation_matrix;      // temp translation matrix

        inv_translation_matrix.m[0][3] = -dx;
        inv_translation_matrix.m[1][3] = -dy;
        inv_translation_matrix.m[2][3] = -dz;

        // post-multiply for inverse trans
        m_invMatrix = m_invMatrix * inv_translation_matrix;

        translation_matrix.m[0][3] = dx;
        translation_matrix.m[1][3] = dy;
        translation_matrix.m[2][3] = dz;

        m_forwardMatrix = translation_matrix * m_forwardMatrix;   // pre-multiply

}

void Instance::rotateX(const d_type::Bfloat theta)
{

        float radians = theta * PI_ON_180;

        Matrix4 inv_rotation_matrix;     //temp inverse rotation matrix
        Matrix4 rotation_matrix; // temp rotation matrix

        inv_rotation_matrix.m[1][1] = cos(radians);
        inv_rotation_matrix.m[1][2] = sin(radians);
        inv_rotation_matrix.m[2][1] = -sin(radians);
        inv_rotation_matrix.m[2][2] = cos(radians);

        // post multiply
        m_invMatrix = m_invMatrix * inv_rotation_matrix;

        rotation_matrix.m[1][1] = cos(radians);
        rotation_matrix.m[1][2] = -sin(radians);
        rotation_matrix.m[2][1] = sin(radians);
        rotation_matrix.m[2][2] = cos(radians);

        // pre-multiply
        m_forwardMatrix = rotation_matrix * m_forwardMatrix;

}

void Instance::rotateY(const d_type::Bfloat theta)
{
float radians = theta * PI_ON_180;

        Matrix4 inv_rotation_matrix;     //temp inverse rotation matrix
        Matrix4 rotation_matrix; // temp rotation matrix

        inv_rotation_matrix.m[0][0] = cos(radians);
        inv_rotation_matrix.m[0][2] = -sin(radians);
        inv_rotation_matrix.m[2][0] = sin(radians);
        inv_rotation_matrix.m[2][2] = cos(radians);

        // post multiply
        m_invMatrix = m_invMatrix * inv_rotation_matrix;

        rotation_matrix.m[0][0] = cos(radians);
        rotation_matrix.m[0][2] = sin(radians);
        rotation_matrix.m[2][0] = -sin(radians);
        rotation_matrix.m[2][2] = cos(radians);

        // pre-multiply
       m_forwardMatrix = rotation_matrix * m_forwardMatrix;

}

void Instance::rotateZ(const d_type::Bfloat theta)
{
float radians = theta * PI_ON_180;

        Matrix4 inv_rotation_matrix;     //temp inverse rotation matrix
        Matrix4 rotation_matrix; // temp rotation matrix

        inv_rotation_matrix.m[0][0] = cos(radians);
        inv_rotation_matrix.m[0][1] = sin(radians);
        inv_rotation_matrix.m[1][0] = -sin(radians);
        inv_rotation_matrix.m[1][1] = cos(radians);

        // post multiply
        m_invMatrix = m_invMatrix * inv_rotation_matrix;

        rotation_matrix.m[0][0] = cos(radians);
        rotation_matrix.m[0][1] = -sin(radians);
        rotation_matrix.m[1][0] = sin(radians);
        rotation_matrix.m[1][1] = cos(radians);

        // pre-multiply
        m_forwardMatrix = rotation_matrix * m_forwardMatrix;

}

void Instance::shear(const d_type::Bfloat xy, const d_type::Bfloat xz, const d_type::Bfloat yx, const d_type::Bfloat yz, const d_type::Bfloat zx, const d_type::Bfloat zy)
{
        Matrix4 inv_shear_matrix;  // temp inverse shear matrix
        Matrix4 shear_matrix;    // temp sheer matrix

        inv_shear_matrix.m[0][0] = 1 - yz * zy;
        inv_shear_matrix.m[0][1] = -yx + yz * zx;
        inv_shear_matrix.m[0][2] = -zx + yx * zy;
        inv_shear_matrix.m[1][0] = -xy + xz * zy;
        inv_shear_matrix.m[1][1] = 1 - xz * zx;
        inv_shear_matrix.m[1][2] = -zy + xy * zx;
        inv_shear_matrix.m[2][0] = -xz + xy * yz;
        inv_shear_matrix.m[2][1] = -yz + xz * yx;
        inv_shear_matrix.m[2][2] = 1 - xy * yx;

        float inv_determinant = 1 / (1 - xy * yx - xz * zx - yz * zy + xy * yz * zx + xz * yx * zy);

        // post multiply
        m_invMatrix = m_invMatrix * (inv_shear_matrix.scalar_mult(inv_determinant));

        shear_matrix.m[0][1] = yx;
        shear_matrix.m[0][2] = zx;
        shear_matrix.m[1][0] = xy;
        shear_matrix.m[1][2] = zy;
        shear_matrix.m[2][0] = xz;
        shear_matrix.m[2][1] = yz;

        // pre-multiply
        m_forwardMatrix = shear_matrix * m_forwardMatrix;

}

void Instance::scale(const d_type::Bfloat x_scale, const d_type::Bfloat y_scale, const d_type::Bfloat z_scale)
{

        Matrix4 inv_scale_matrix;        // temp inverse scale matrix
        Matrix4 scale_matrix;    // temp scale matrix

        inv_scale_matrix.m[0][0] = 1 / x_scale;
        inv_scale_matrix.m[1][1] = 1 / y_scale;
        inv_scale_matrix.m[2][2] = 1 / z_scale;

        // post-multiply
        m_invMatrix = m_invMatrix * inv_scale_matrix;

        scale_matrix.m[0][0] = x_scale;
        scale_matrix.m[1][1] = y_scale;
        scale_matrix.m[2][2] = z_scale;

        // pre multiply
        m_forwardMatrix = scale_matrix * m_forwardMatrix;

}



void Instance::reflectAcrossXaxis()
{
        Matrix4 inv_reflect_matrix;      // temp inverse reflect matrix
        Matrix4 reflect_matrix;  // temp reflect matrix

        inv_reflect_matrix.m[0][0] = -1;

        // post multiply
        m_invMatrix = m_invMatrix * inv_reflect_matrix;

        reflect_matrix.m[1][1] = -1;
        reflect_matrix.m[2][2] = -1;

        // pre-multiply
        m_forwardMatrix = reflect_matrix * m_forwardMatrix;


}

void Instance::reflectAcrossYaxis()
{
    Matrix4 inv_reflect_matrix;      // temp inverse reflect matrix
        Matrix4 reflect_matrix;  // temp reflect matrix

        inv_reflect_matrix.m[1][1] = -1;

        // post multiply
        m_invMatrix = m_invMatrix * inv_reflect_matrix;

        reflect_matrix.m[0][0] = -1;
        reflect_matrix.m[2][2] = -1;

        // pre-multiply
        m_forwardMatrix = reflect_matrix * m_forwardMatrix;

}

void Instance::reflectAcrossZaxis()
{
Matrix4 inv_reflect_matrix;      // temp inverse reflect matrix
        Matrix4 reflect_matrix;  // temp reflect matrix

        inv_reflect_matrix.m[2][2] = -1;

        // post multiply
        m_invMatrix = m_invMatrix * inv_reflect_matrix;

        reflect_matrix.m[0][0] = -1;
        reflect_matrix.m[1][1] = -1;

        // pre-multiply
        m_forwardMatrix = reflect_matrix * m_forwardMatrix;

}

void Instance::transformTexture(const bool trans)
{
m_transformoTexture = trans;

}
void Instance::scale(const d_type::Bfloat s)
{
     scale(s,s,s);
}
