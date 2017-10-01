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

#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    std::string bootloader = property_get("ro.bootloader");
    if (bootloader.find("I317") != std::string::npos) {
        /* SGH-i317 (AT&T) */
        property_override("ro.product.model", "SGH-I317");
        property_override("ro.product.device", "t0lteatt");
        property_override("ro.build.description", "t0lteuc-user 4.4.2 KOT49H I317UCUCNJ1 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0lteuc/t0lteatt:4.4.2/KOT49H/I317UCUCNJ1:user/release-keys");
        property_override("ro.build.product", "t0lteatt");
    } else if (bootloader.find("I605") != std::string::npos) {
        /* SCH-I605 (Verizon) */
        property_override("ro.product.model", "SCH-I605");
        property_override("ro.product.device", "t0ltevzw");
        property_override("ro.build.description", "t0ltevzw-user 4.4.2 KOT49H I605VRUFND7 release-keys");
        property_override("ro.build.fingerprint", "Verizon/t0ltevzw/t0ltevzw:4.4.2/KOT49H/I605VRUFND7:user/release-keys");
        property_override("ro.build.product", "t0ltevzw");
    } else if (bootloader.find("T889") != std::string::npos) {
        /* SGH-T889 (T-Mobile) */
        property_override("ro.product.model", "SGH-T889");
        property_override("ro.product.device", "t0ltetmo");
        property_override("ro.build.description", "t0ltetmo-user 4.3 JSS15J T889UVUCMK7 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0ltetmo/t0ltetmo:4.3/JSS15J/T889UVUCMK7:user/release-keys");
        property_override("ro.build.product", "t0ltetmo");
    } else if (bootloader.find("L900") != std::string::npos) {
        /* SCH-L900 (Sprint) */
        property_override("ro.product.model", "SPH-L900");
        property_override("ro.product.device", "t0ltespr");
        property_override("ro.build.description", "t0ltespr-user 4.4.2 KOT49H L900VPUCNE2 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0ltespr/t0ltespr:4.4.2/KOT49H/L900VPUCNE2:user/release-keys");
        property_override("ro.build.product", "t0ltespr");
    } else if (bootloader.find("E250S") != std::string::npos) {
        /* SHV-E250S (SK Telecom) */
        property_override("ro.product.model", "SHV-E250S");
        property_override("ro.product.device", "t0lteskt");
        property_override("ro.build.description", "t0lteskt-user 4.4.2 KOT49H E250SKSUKNI2 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0lteskt/t0lteskt:4.4.2/KOT49H/E250SKSUKNI2:user/release-keys");
        property_override("ro.build.product", "t0lteskt");
    } else if (bootloader.find("E250K") != std::string::npos) {
        /* SHV-E250K (KT Olleh) */
        property_override("ro.product.model", "SHV-E250K");
        property_override("ro.product.device", "t0ltektt");
        property_override("ro.build.description", "t0ltektt-user 4.4.2 KOT49H E250KKTUKNI1 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0ltektt/t0ltektt:4.4.2/KOT49H/E250KKTUKNI1:user/release-keys");
        property_override("ro.build.product", "t0ltektt");
    } else if (bootloader.find("E250L") != std::string::npos) {
        /* SHV-E250L (LG Uplus) */
        property_override("ro.product.model", "SHV-E250L");
        property_override("ro.product.device", "t0ltelgt");
        property_override("ro.build.description", "t0ltelgt-user 4.4.2 KOT49H E250LKLUKNL1 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0ltelgt/t0ltelgt:4.4.2/KOT49H/E250LKLUKNL1:user/release-keys");
        property_override("ro.build.product", "t0ltelgt");  
    } else if (bootloader.find("SC02E") != std::string::npos) {
        /* SC-02E (NTT Docomo) */
	property_override("ro.product.model", "SC-02E");
	property_override("ro.product.device", "t0ltejpn");
	property_override("ro.build.description", "t0ltejpn-user 4.3 KOT49H SC02EOMUBNJ2 release-keys");
	property_override("ro.build.fingerprint", "samsung/t0ltejpn/t0ltejpn:4.4.2/KOT49H/SC02EOMUBNJ2:user/release-keys");
	property_override("ro.build.product", "t0ltejpn");
    } else {
        /* Fall back to GT-N7105 (International LTE) */
        property_override("ro.product.model", "GT-N7105");
        property_override("ro.product.device", "t0lte");
        property_override("ro.build.description", "t0ltexx-user 4.4.2 KOT49H N7105XXUFOB2 release-keys");
        property_override("ro.build.fingerprint", "samsung/t0ltexx/t0lte:4.4.2/KOT49H/N7105XXUFOB2:user/release-keys");
        property_override("ro.build.product", "t0lte");
    }
    std::string device = property_get("ro.product.device");
    INFO("Setting device to %s\n", device.c_str());
}
