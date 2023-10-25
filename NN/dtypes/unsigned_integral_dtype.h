#pragma once
#include "./as_dtype.h"
#include "../devices/includes.h"
#include <concepts>
#include <cuda_runtime.h>
#include <curand_kernel.h>
namespace NN {
	namespace Dtypes {


		//describes the dtype for a signed integral type
		template<typename T> requires std::is_unsigned_v<T>
		class AsDtype<T> {
		public:
			using Type = T;


			static T constexpr additiveIdentity = (T)0;

			static T constexpr multiplicativeIdentity = (T)1;

			static inline __host__ __device__ T init(unsigned int seed) {
				return ((((T)(seed % 100)) / 10));
			}

		};
	}
}