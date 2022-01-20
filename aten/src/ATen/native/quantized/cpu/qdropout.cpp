#include <ATen/ATen.h>
#include <ATen/NativeFunctions.h>
#include <torch/library.h>
#include <ATen/quantized/Quantizer.h>
#include <ATen/native/quantized/cpu/quantized_ops.h>

namespace at {
namespace native {

DEFINE_DISPATCH(qdropout_stub);

Tensor quantized_dropout(
    const Tensor& qx, double output_scale, int64_t output_zero_point, const Scalar& p, const Scalar& scale, const Scalar& input_scale) {
  return qx;
}

TORCH_LIBRARY_IMPL(quantized, QuantizedCPU, m) {
  m.impl(TORCH_SELECTIVE_NAME("quantized::dropout"), quantized_dropout);
}

}}  // namespace at::native
