/*
 * SPDX-FileCopyrightText: The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "GloveModeService"

#include "GloveMode.h"

#include <fstream>

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace implementation {

const std::string kFilmStatusPath = "/sys/devices/virtual/input/lge_touch/film_status";

Return<bool> GloveMode::isEnabled() {
    std::ifstream file(kFilmStatusPath);
    int enabled;
    file >> enabled;

    if(enabled == 1)
        return true;

    return false;
}

Return<bool> GloveMode::setEnabled(bool enabled) {
    std::ofstream file(kFilmStatusPath);
    file << (enabled ? "1" : "0");
    return !file.fail();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
