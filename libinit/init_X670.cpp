/*
 * Copyright (C) 2021-2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include "vendor_init.h"

#define FINGERPRINT_X670 "Infinix/X670-GL/Infinix-X670:12/SP1A.210812.016/240224V150:user/release-keys"

static const variant_info_t X670_info = {
    .hwc_value = "",
    .sku_value = "",
    .vendor_sku_value = "",           // Replace with actual ro.boot.vendor.sku if different
    .brand = "Infinix",
    .device = "Infinix-X670",
    .marketname = "Infinix X670",
    .model = "X670",
    .mod_device = "X670-GL",
    .build_fingerprint = FINGERPRINT_X670,
    .nfc = true,                         // Set to true if your device has NFC
};

static const std::vector<variant_info_t> variants = {
    X670_info,
};

void vendor_load_properties() {
    set_dalvik_heap();
    search_variant(variants);

    // SafetyNet workaround
    property_override("ro.boot.verifiedbootstate", "green");
}
