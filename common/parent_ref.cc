#include "common/parent_ref.h"

namespace google {
namespace api {
namespace expr {

absl::optional<RefProvider> SharedValue::SelfRefProvider() const {
  if (!owns_value()) {
    // No reference needed.
    return RefProvider(nullptr);
  }
  if (unowned()) {
    // Not shareable.
    return absl::nullopt;
  }
  return RefProvider(this);
}

}  // namespace expr
}  // namespace api
}  // namespace google
