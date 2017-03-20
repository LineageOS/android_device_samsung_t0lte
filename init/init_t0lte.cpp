/*
 * Copyright (C) 2017 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    std::string bootloader = property_get("ro.bootloader");
    if (bootloader.find("I317") != std::string::npos) {
        /* SGH-i317 (AT&T) */
        property_set("ro.product.model", "SGH-I317");
        property_set("ro.product.device", "t0lteatt");
        property_set("ro.product.name", "t0lteuc");
        property_set("ro.build.description", "t0lteuc-user 4.4.2 KOT49H I317UCUCNJ1 release-keys");
        property_set("ro.build.fingerprint", "samsung/t0lteuc/t0lteatt:4.4.2/KOT49H/I317UCUCNJ1:user/release-keys");
        property_set("ro.build.product", "t0lteatt");
    } else if (bootloader.find("L900") != std::string::npos) {
        /* SPH-L900 (Sprint) */
        property_set("ro.product.model", "SPH-L900");
        property_set("ro.product.device", "t0ltespr");
        property_set("ro.product.name", "t0ltespr");
        property_set("ro.build.description", "t0ltespr-user 4.4.2 KOT49H L900VPUCOH3 release-keys");
        property_set("ro.build.fingerprint", "samsung/t0ltespr/t0ltespr:4.4.2/KOT49H/L900VPUCOH3:user/release-keys");
        property_set("ro.build.product", "t0ltespr");
        property_set("telephony.lteOnCdmaDevice", "1");
        property_set("ril.subscription.types", "RUIM,NV");
        property_set("gsm.sim.operator.alpha", "sprint");
        property_set("gsm.sim.operator.numeric", "310120");
        property_set("gsm.operator.alpha", "sprint");
        property_set("gsm.operator.numeric", "310120");
        property_set("ro.telephony.default_network", "8");
        property_set("ro.ril.svdo", "true");
    } else {
        /* Fall back to N7105 */
        property_set("ro.product.model", "GT-N7105");
        property_set("ro.product.device", "t0lte");
        property_set("ro.product.name", "t0lte");
        property_set("ro.build.description", "t0ltexx-user 4.4.2 KOT49H N7105XXUFOB2 release-keys");
        property_set("ro.build.fingerprint", "samsung/t0ltexx/t0lte:4.4.2/KOT49H/N7105XXUFOB2:user/release-keys");
        property_set("ro.build.product", "t0lte");
    }
    std::string device = property_get("ro.product.device");
    INFO("Setting device to %s\n", device.c_str());
}
