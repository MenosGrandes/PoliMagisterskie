#include "stdafx.h"
#include "MyMath.h"

#pragma region Float3
float3 float3::ZERO = float3(0.0f, 0.0f, 0.0f);

float3::float3()
{
	values_[0] = values_[1] = values_[2] = 0.0f;
}

float3::~float3()
{
}

float3::float3(float v1, float v2, float v3)
{
	values_[0] = v1;
	values_[1] = v2;
	values_[2] = v3;
}
float float3::clip(float n, float lower, float upper) {
	return std::max(lower, std::min(n, upper));
}
float float3::Length()
{
	return sqrt((values_[0] * values_[0]) + (values_[1] * values_[1]) + (values_[2] * values_[2]));
}

float float3::LengthSquared()
{
	return (values_[0] * values_[0]) + (values_[1] * values_[1]) + (values_[2] * values_[2]);
}

void float3::Normalize()
{
	float length = this->Length();
	if (length >= EPSILON)
	{
		values_[0] /= length; 		
		values_[1] /= length;		
		values_[2] /= length;
	}
	else
		values_[0] = values_[1] = values_[2] = 0.0f;
}

float float3::DotProduct(float3 v)
{
	return (values_[0] * v.x() + values_[1] * v.y() + values_[2] * v.z());
}

float3 float3::CrossProduct(float3 v)
{
	/*return float3(this->y * v.z - this->z * v.y, this->z * v.x - this->x * v.z,
		this->x * v.y - this->y * v.x);*/
	return float3(values_[1] * v.z() - values_[2] * v.y(), values_[2] * v.x() - values_[0] * v.z(),
		values_[0] * v.y() - values_[1] * v.x());
}

void float3::Negate()
{
	values_[0] = -values_[0];
	values_[1] = -values_[1];
	values_[2] = -values_[2];
}

float3 float3::Reflect(float3 normal)
{
	return *this - (2 * this->DotProduct(normal) *normal);
}
/* Matematyczne metody statyczne */
float float3::DotProduct(float3 v1, float3 v2)
{
	return (v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z());
}

float3 float3::CrossProduct(float3 v1, float3 v2)
{
	return float3(v1.y() * v2.z() - v1.z() * v2.y(), v1.z() * v2.x() - v1.x() * v2.z(),
		v1.x() * v2.y() - v1.y() * v2.x());
}

/* Przeci¹¿enia operatorów */
std::ostream& operator<<(std::ostream &strm, const float3 &v)
{
	return strm << "FLOAT3 [" << v.values_[0] << ", " << v.values_[1] << ", " << v.values_[2] << "]" << endl;;
}

float3 operator+ (float3 &left, float3 &right)
{
	return float3(left.x() + right.x(), left.y() + right.y(), left.z() + right.z());
}

float3 operator- (float3 &left, float3 &right)
{
	return float3(left.x() - right.x(), left.y() - right.y(), left.z() - right.z());
}

float3 operator- (float3 &left)
{
	return float3(-left.x(), -left.y(), -left.z());
}

float3 operator* (float scalar, float3 & right)
{
	return float3(right.x() * scalar, right.y() * scalar, right.z() * scalar);
}

float3 operator* (float3 & left, float scalar)
{
	return float3(left.x() * scalar, left.y() * scalar, left.z() * scalar);
}

float3 operator* (float3 & left, float3 & right)
{
	return float3(left.x() * right.x(), left.y() * right.y(), left.z()* right.z());
}

bool operator== (float3 & left, float3 & right)
{
	return (left.x() == right.x() && left.y() == right.y() && left.z() == right.z());
}

bool operator!= (float3 & left, float3 & right)
{
	return (left.x() != right.x() || left.y() != right.y() || left.z() != right.z());
}

float3 operator+= (float3 & left, float3 & right)
{
	return float3(left.x() + right.x(), left.y() + right.y(), left.z() + right.z());
}

float3 operator/ (float3 & left, float scalar)
{
	float3 vector = float3();

	float inverse = 1.0f / scalar;
	vector.x() = left.x() * inverse;
	vector.y() = left.y() * inverse;
	vector.z() = left.z() * inverse;
	return vector;
}
#pragma endregion

#pragma region Float4
float4::float4()
{
	values_[0] = values_[1] = values_[2] = 0.0f;
	values_[3] = 1.0f;
}

float4::float4(float v1, float v2, float v3, float v4)
{
	values_[0] = v1;
	values_[1] = v2;
	values_[2] = v3;
	values_[3] = v4;
}

float4::~float4()
{
}

float float4::DotProduct(float4 v)
{
	return (values_[0] * v.x() + values_[1] * v.y() + values_[2] * v.z() + values_[3] * v.w());
}

std::ostream& operator<<(std::ostream &strm, const float4 &v)
{
	return strm << "FLOAT4 [" << v.values_[0] << ", " << v.values_[1] << ", " << v.values_[2] << "," << v.values_[3] << "]" <<endl;
}
#pragma endregion

#pragma region Float4x4
float4x4::float4x4()
{
	values_[0] = values_[1] = values_[2] = values_[3] = float4(0.0f, 0.0f, 0.0f, 0.0f);
}

float4x4::float4x4(float4 v1, float4 v2, float4 v3, float4 v4)
{
	values_[0] = v1;
	values_[1] = v2;
	values_[2] = v3;
	values_[3] = v4;
}
float4x4::~float4x4()
{
}

float4x4 float4x4::MultiplyFloat4x4ByFloat4x4(float4x4 A, float4x4 B)
{
	float4x4 matC;
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			for (int x = 0; x < 4; x++)
				matC[i][j] += A[x][j] * B[i][x];
//ki jk
		}
	}
	
	return matC;
}

float4 float4x4::MultiplyFloat4x4ByFloat4(float4x4 A, float4 B)
{
	float4 matC;

	//matC[0] = A[0][0] * B[0] + A[1][0] * B[1] + A[2][0] * B[2] + A[3][0] * B[3]; 
	//matC[1] = A[0][1] * B[0] + A[1][1] * B[1] + A[2][1] * B[2] + A[3][1] * B[3];
	//matC[2] = A[0][2] * B[0] + A[1][2] * B[1] + A[2][2] * B[2] + A[3][2] * B[3];
	//matC[3] = A[0][3] * B[0] + A[1][3] * B[1] + A[2][3] * B[2] + A[3][3] * B[3];

	matC[0] = A[0][0] * B[0] + A[1][0] * B[1] + A[2][0] * B[2] + A[3][0] * B[3];
	matC[1] = A[0][1] * B[0] + A[1][1] * B[1] + A[2][1] * B[2] + A[3][1] * B[3];
	matC[2] = A[0][2] * B[0] + A[1][2] * B[1] + A[2][2] * B[2] + A[3][2] * B[3];
	matC[3] = A[0][3] * B[0] + A[1][3] * B[1] + A[2][3] * B[2] + A[3][3] * B[3];
	/*for (int i = 0; i < 4; i++)
	{
		matC[i] = A[i][0] * B.x() + A[i][1] * B.y() + A[i][2] * B.z() + A[i][3] * B.w();
	}*/
	//for (int j = 0; j < 4; j++)
	//	cout << matC[j] << " ";
	//cout << endl;
	return matC;
}

float4 float4x4::MultiplyFloat4x4ByFloat3(float4x4 A, float3 B)
{
	float4 BExtended = float4(B[0], B[1], B[2], 1.0f);
	float4 matC;
	matC[0] = A[0][0] * BExtended[0] + A[1][0] * BExtended[1] + A[2][0] * BExtended[2] + A[3][0] * BExtended[3];
	matC[1] = A[0][1] * BExtended[0] + A[1][1] * BExtended[1] + A[2][1] * BExtended[2] + A[3][1] * BExtended[3];
	matC[2] = A[0][2] * BExtended[0] + A[1][2] * BExtended[1] + A[2][2] * BExtended[2] + A[3][2] * BExtended[3];
	matC[3] = A[0][3] * BExtended[0] + A[1][3] * BExtended[1] + A[2][3] * BExtended[2] + A[3][3] * BExtended[3];
	//for (int i = 0; i < 4; i++)
	//{
	//	matC[i] = A[i][0] * BExtended.x() + A[i][1] * BExtended.y() + A[i][2] * BExtended.z() + A[i][3] * BExtended.w();
	//}
	//for (int j = 0; j < 4; j++)
	//	cout << matC[j] << " ";
	//cout << endl;
	return matC;
}


float4x4 float4x4::TransponeFloat4x4_Product()
{
	float4x4 result;
	for (int i = 0; i<4; i++)
		for (int j = 0; j<4; j++)
			result[j][i] = values_[i][j];

	//for (int i = 0; i < 4; i++) {
	//	for (int j = 0; j < 4; j++)
	//		cout << result[i][j] << "\t";
	//	cout << endl;
	//}
	return result;
}

std::ostream& operator<<(std::ostream &strm, const float4x4 &v)
{
	strm << "Float4x4 \n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			strm << v[j][i] << "\t";
		strm << endl;
	}
	return strm << endl;
}
#pragma endregion

#pragma region Int3
int3::int3()
{
	values_[0] = values_[1] = values_[2] = 0;
}

int3::int3(int v1, int v2, int v3)
{
	values_[0] = v1;
	values_[1] = v2;
	values_[2] = v3;
}
int3::~int3()
{
}
std::ostream& operator<<(std::ostream &strm, const int3 &v)
{
	return strm << "INT3 [" << v.values_[0] << ", " << v.values_[1] << ", " << v.values_[2] << "]" << endl;
}
#pragma endregion