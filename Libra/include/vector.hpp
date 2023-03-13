#pragma once
#include <array>
#include <ostream>

namespace base
{
	template <typename T, size_t S>
	class Vector
	{
	public:

		Vector(std::initializer_list<T> l){
			int i = 0;
			for (auto t : l)
			{
				vec_array[i] = t;
				++i;
			}
		}
		Vector() = default;

		//The use of size is to get the size of the vector in the compile time
		constexpr size_t size() const
		{
			return S;
		}

		//Index based access
		T& operator[] (size_t index)
		{
			return vec_array[index];
		}


		const T& operator[] (size_t index) const
		{
			return vec_array[index];
		}
		
		//Returning actual data
		T* Data()
		{
			return vec_array;
		}

		const T* Data() const
		{
			return vec_array;
		}

		//Performs element-wise addition of vectors 
		Vector<T, S> operator+ (const Vector& right) const
		{
			//static base::Vector<T, S> vec_result;  
			// Check if this is a good idea. This prevents the copying if returned as a reference
			Vector<T, S> vec_result;
			for (auto i = 0; i < S; ++i)
			{
				vec_result[i] = vec_array[i] + right.vec_array[i];
			}
			return vec_result;
		}

		//Performs element-wise addition of vectors 
		Vector<T, S> operator- (const Vector& right) const
		{
			//static base::Vector<T, S> vec_result;  
			// Check if this is a good idea. This prevents the copying if returned as a reference
			Vector<T, S> vec_result;
			for (auto i = 0; i < S; ++i)
			{
				vec_result[i] = vec_array[i] + right.vec_array[i];
			}
			return vec_result;
		}

		//Performs dot product. Implemented as a function as . operator is not overloadable
		Vector<T, S> dot(const Vector& right) const
		{
			Vector<T, S> vec_result;
			for (auto i = 0; i < S; ++i)
			{
				vec_result[i] = vec_array[i] * right.vec_array[i];
			}
			return vec_result;
		}

		//Performs matrix multiplication operation
		T operator* (const Vector& right) const
		{   
			T val_result = 0;
			for (auto i = 0; i < S; ++i)
			{
				val_result += vec_array[i] * right.vec_array[i];
			}
			return val_result;
		}

	private:

		inline friend std::ostream& operator<<(std::ostream& os, const Vector<T, S> target)
		{
			for (auto t : target.vec_array)
			{
				os << t;
				std::cout << ",";
			}
			return os;
		}
		T vec_array[S];
	};


}

//template <typename T, size_t S>
//std::ostream& operator<<(std::ostream& os, const base::Vector<T, S> target);


