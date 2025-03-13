/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef VENDOR_LINEAGE_TOUCH_V1_0_TOUCHSCREENGESTURE_H
#define VENDOR_LINEAGE_TOUCH_V1_0_TOUCHSCREENGESTURE_H

#include <vendor/lineage/touch/1.0/ITouchscreenGesture.h>

#include <map>

namespace {
typedef struct {
    int32_t swipe_id;
    int32_t keycode;
    const char* name;
} GestureInfo;
}  // anonymous namespace

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace implementation {

using ::android::hardware::Return;
using ::android::hardware::Void;

class TouchscreenGesture : public ITouchscreenGesture {
   public:
   TouchscreenGesture();

    // Methods from ::vendor::lineage::touch::V1_0::ITouchscreenGesture follow.
    Return<void> getSupportedGestures(getSupportedGestures_cb resultCb) override;
    Return<bool> setGestureEnabled(
        const ::vendor::lineage::touch::V1_0::Gesture& gesture, bool enable) override;

   private:
    std::map<int32_t, GestureInfo> kGestureInfoMap;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor

#endif  // VENDOR_LINEAGE_TOUCH_V1_0_TOUCHSCREENGESTURE_H
