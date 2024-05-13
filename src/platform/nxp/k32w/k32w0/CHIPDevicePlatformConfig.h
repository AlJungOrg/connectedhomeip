/*
 *
 *    Copyright (c) 2020 Project CHIP Authors
 *    Copyright (c) 2020 Google LLC.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *          Platform-specific configuration overrides for the chip Device Layer
 *          on K32W platforms using the NXP SDK.
 */

#pragma once

// ==================== Platform Adaptations ====================

#define K32W_NO_ERRORS 0
#define K32W_ENTRY_NOT_FOUND 1

#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_STATION 0
#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_AP 0

#ifndef CHIP_DEVICE_CONFIG_ENABLE_CHIPOBLE
#define CHIP_DEVICE_CHIP0BLE_DEBUG 0
#endif

/**
 * @def CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH
 *
 * Set unique id to maximum length if not defined to ensure the actual unique
 * id is retrieved instead of the default one (if factory data read fails).
 */
#ifndef CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH
#define CHIP_DEVICE_CONFIG_ROTATING_DEVICE_ID_UNIQUE_ID_LENGTH 32
#endif

#define CHIP_ADDRESS_RESOLVE_IMPL_INCLUDE_HEADER <lib/address_resolve/AddressResolve_DefaultImpl.h>

// ========== Platform-specific Configuration =========

// These are configuration options that are unique to the K32W platform.
// These can be overridden by the application as needed.

#ifndef CHIP_DEVICE_CONFIG_CERTIFICATION_DECLARATION
//-> format_version = 1
//-> vendor_id = 0xFFF1
//-> product_id_array = [ 0x8000, 0x8001, 0x8002, 0x8003, 0x8004, 0x8005, 0x8006, 0x8007, 0x8008, 0x8009, 0x800A, 0x800B,
// 0x800C, 0x800D, 0x800E, 0x800F, 0x8010, 0x8011, 0x8012, 0x8013, 0x8014, 0x8015, 0x8016, 0x8017, 0x8018, 0x8019, 0x801A,
// 0x801B, 0x801C, 0x801D, 0x801E, 0x801F, 0x8020, 0x8021, 0x8022, 0x8023, 0x8024, 0x8025, 0x8026, 0x8027, 0x8028, 0x8029,
// 0x802A, 0x802B, 0x802C, 0x802D, 0x802E, 0x802F, 0x8030, 0x8031, 0x8032, 0x8033, 0x8034, 0x8035, 0x8036, 0x8037, 0x8038,
// 0x8039, 0x803A, 0x803B, 0x803C, 0x803D, 0x803E, 0x803F, 0x8040, 0x8041, 0x8042, 0x8043, 0x8044, 0x8045, 0x8046, 0x8047,
// 0x8048, 0x8049, 0x804A, 0x804B, 0x804C, 0x804D, 0x804E, 0x804F, 0x8050, 0x8051, 0x8052, 0x8053, 0x8054, 0x8055, 0x8056,
// 0x8057, 0x8058, 0x8059, 0x805A, 0x805B, 0x805C, 0x805D, 0x805E, 0x805F, 0x8060, 0x8061, 0x8062, 0x8063 ]
//-> device_type_id = 0x0016
//-> certificate_id = "ZIG20142ZB330003-24"
//-> security_level = 0
//-> security_information = 0
//-> version_number = 0x2694
//-> certification_type = 0
//-> dac_origin_vendor_id is not present
//-> dac_origin_product_id is not present
#define CHIP_DEVICE_CONFIG_CERTIFICATION_DECLARATION                                                                               \
    {                                                                                                                              \
        0x30, 0x82, 0x02, 0x19, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x02, 0xa0, 0x82, 0x02, 0x0a, 0x30,    \
            0x82, 0x02, 0x06, 0x02, 0x01, 0x03, 0x31, 0x0d, 0x30, 0x0b, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04,      \
            0x02, 0x01, 0x30, 0x82, 0x01, 0x71, 0x06, 0x09, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0x0d, 0x01, 0x07, 0x01, 0xa0, 0x82,      \
            0x01, 0x62, 0x04, 0x82, 0x01, 0x5e, 0x15, 0x24, 0x00, 0x01, 0x25, 0x01, 0xe1, 0xee, 0x36, 0x02, 0x05, 0x00, 0x80,      \
            0x05, 0x01, 0x80, 0x05, 0x02, 0x80, 0x05, 0x03, 0x80, 0x05, 0x04, 0x80, 0x05, 0x05, 0x80, 0x05, 0x06, 0x80, 0x05,      \
            0x07, 0x80, 0x05, 0x08, 0x80, 0x05, 0x09, 0x80, 0x05, 0x0a, 0x80, 0x05, 0x0b, 0x80, 0x05, 0x0c, 0x80, 0x05, 0x0d,      \
            0x80, 0x05, 0x0e, 0x80, 0x05, 0x0f, 0x80, 0x05, 0x10, 0x80, 0x05, 0x11, 0x80, 0x05, 0x12, 0x80, 0x05, 0x13, 0x80,      \
            0x05, 0x14, 0x80, 0x05, 0x15, 0x80, 0x05, 0x16, 0x80, 0x05, 0x17, 0x80, 0x05, 0x18, 0x80, 0x05, 0x19, 0x80, 0x20,      \
            0x05, 0x1a, 0x80, 0x05, 0x1b, 0x80, 0x05, 0x1c, 0x80, 0x05, 0x1d, 0x80, 0x05, 0x1e, 0x80, 0x05, 0x1f, 0x80, 0x05,      \
            0x80, 0x05, 0x21, 0x80, 0x05, 0x22, 0x80, 0x05, 0x23, 0x80, 0x05, 0x24, 0x80, 0x05, 0x25, 0x80, 0x05, 0x26, 0x80,      \
            0x05, 0x27, 0x80, 0x05, 0x28, 0x80, 0x05, 0x29, 0x80, 0x05, 0x2a, 0x80, 0x05, 0x2b, 0x80, 0x05, 0x2c, 0x80, 0x05,      \
            0x2d, 0x80, 0x05, 0x2e, 0x80, 0x05, 0x2f, 0x80, 0x05, 0x30, 0x80, 0x05, 0x31, 0x80, 0x05, 0x32, 0x80, 0x05, 0x33,      \
            0x80, 0x05, 0x34, 0x80, 0x05, 0x35, 0x80, 0x05, 0x36, 0x80, 0x05, 0x37, 0x80, 0x05, 0x38, 0x80, 0x05, 0x39, 0x80,      \
            0x05, 0x3a, 0x80, 0x05, 0x3b, 0x80, 0x05, 0x3c, 0x80, 0x05, 0x3d, 0x80, 0x05, 0x3e, 0x80, 0x05, 0x3f, 0x80, 0x05,      \
            0x40, 0x80, 0x05, 0x41, 0x80, 0x05, 0x42, 0x80, 0x05, 0x43, 0x80, 0x05, 0x44, 0x80, 0x05, 0x45, 0x80, 0x05, 0x46,      \
            0x80, 0x05, 0x47, 0x80, 0x05, 0x48, 0x80, 0x05, 0x49, 0x80, 0x05, 0x4a, 0x80, 0x05, 0x4b, 0x80, 0x05, 0x4c, 0x80,      \
            0x05, 0x4d, 0x80, 0x05, 0x4e, 0x80, 0x05, 0x4f, 0x80, 0x05, 0x50, 0x80, 0x05, 0x51, 0x80, 0x05, 0x52, 0x80, 0x05,      \
            0x53, 0x80, 0x05, 0x54, 0x80, 0x05, 0x55, 0x80, 0x05, 0x56, 0x80, 0x05, 0x57, 0x80, 0x05, 0x58, 0x80, 0x05, 0x59,      \
            0x80, 0x05, 0x5a, 0x80, 0x05, 0x5b, 0x80, 0x05, 0x5c, 0x80, 0x05, 0x5d, 0x80, 0x05, 0x5e, 0x80, 0x05, 0x5f, 0x80,      \
            0x05, 0x60, 0x80, 0x05, 0x61, 0x80, 0x05, 0x62, 0x80, 0x05, 0x63, 0x80, 0x18, 0x24, 0x03, 0x16, 0x2c, 0x04, 0x13,      \
            0x5a, 0x49, 0x47, 0x32, 0x30, 0x31, 0x34, 0x32, 0x5a, 0x42, 0x33, 0x33, 0x30, 0x30, 0x30, 0x33, 0x2d, 0x32, 0x34,      \
            0x24, 0x05, 0x00, 0x24, 0x06, 0x00, 0x25, 0x07, 0x94, 0x26, 0x24, 0x08, 0x00, 0x18, 0x31, 0x7d, 0x30, 0x7b, 0x02,      \
            0x01, 0x03, 0x80, 0x14, 0x62, 0xfa, 0x82, 0x33, 0x59, 0xac, 0xfa, 0xa9, 0x96, 0x3e, 0x1c, 0xfa, 0x14, 0x0a, 0xdd,      \
            0xf5, 0x04, 0xf3, 0x71, 0x60, 0x30, 0x0b, 0x06, 0x09, 0x60, 0x86, 0x48, 0x01, 0x65, 0x03, 0x04, 0x02, 0x01, 0x30,      \
            0x0a, 0x06, 0x08, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x04, 0x03, 0x02, 0x04, 0x47, 0x30, 0x45, 0x02, 0x20, 0x24, 0xe5,      \
            0xd1, 0xf4, 0x7a, 0x7d, 0x7b, 0x0d, 0x20, 0x6a, 0x26, 0xef, 0x69, 0x9b, 0x7c, 0x97, 0x57, 0xb7, 0x2d, 0x46, 0x90,      \
            0x89, 0xde, 0x31, 0x92, 0xe6, 0x78, 0xc7, 0x45, 0xe7, 0xf6, 0x0c, 0x02, 0x21, 0x00, 0xf8, 0xaa, 0x2f, 0xa7, 0x11,      \
            0xfc, 0xb7, 0x9b, 0x97, 0xe3, 0x97, 0xce, 0xda, 0x66, 0x7b, 0xae, 0x46, 0x4e, 0x2b, 0xd3, 0xff, 0xdf, 0xc3, 0xcc,      \
            0xed, 0x7a, 0xa8, 0xca, 0x5f, 0x4c, 0x1a, 0x7c                                                                         \
    }
#endif

/**
 * @def CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY
 *
 * The delay before rebooting after an OTA process was finished.
 */
#ifndef CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY
#define CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY 3000
#endif // CHIP_DEVICE_LAYER_OTA_REBOOT_DELAY

/**
 * @def CONFIG_CHIP_K32W0_KVS_MOVE_KEYS_TO_SPECIFIC_STORAGE
 *
 * When enabled, the application can opt to move some keys from
 * current KVS storage to a dedicated storage, based on the key name.
 *
 * Currently, the mechanism supports moving keys and values for:
 * - subscriptions
 * - groups
 *
 * Note: the system is meant to ensure backwards compatibility. This should only
 * be used once, but, if this feature is still enabled after the first conversion,
 * the corresponding keys will not be found in KVS default storage. This does
 * not affect the functionality, but it introduces a delay in the initialization.
 */
#ifndef CONFIG_CHIP_K32W0_KVS_MOVE_KEYS_TO_SPECIFIC_STORAGE
#define CONFIG_CHIP_K32W0_KVS_MOVE_KEYS_TO_SPECIFIC_STORAGE 0
#endif // CONFIG_CHIP_K32W0_KVS_MOVE_KEYS_TO_SPECIFIC_STORAGE

/**
 * @def CONFIG_CHIP_K32W0_OTA_FACTORY_DATA_PROCESSOR
 *
 * Enables default OTA TLV factory data processor.
 * Disabled by default.
 */
#ifndef CONFIG_CHIP_K32W0_OTA_FACTORY_DATA_PROCESSOR
#define CONFIG_CHIP_K32W0_OTA_FACTORY_DATA_PROCESSOR 0
#endif // CONFIG_CHIP_K32W0_OTA_FACTORY_DATA_PROCESSOR

/**
 * @def CHIP_DEVICE_LAYER_ENABLE_PDM_LOGS
 *
 * Flag to enable PDM events logging. Disabled by default.
 */
#ifndef CHIP_DEVICE_LAYER_ENABLE_PDM_LOGS
#define CHIP_DEVICE_LAYER_ENABLE_PDM_LOGS 0
#endif // CHIP_DEVICE_LAYER_ENABLE_PDM_LOGS

// ========== Platform-specific Configuration Overrides =========
#ifndef CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE (6 * 1024)
#endif // CHIP_DEVICE_CONFIG_CHIP_TASK_STACK_SIZE

#ifndef CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE
#define CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE 3072
#endif // CHIP_DEVICE_CONFIG_THREAD_TASK_STACK_SIZE

// Max size of event queue
#define CHIP_DEVICE_CONFIG_MAX_EVENT_QUEUE_SIZE 25

#ifndef CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME
#define CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME "BLE App Task"
#endif // CHIP_DEVICE_CONFIG_BLE_APP_TASK_NAME

/**
 * @def CHIP_DEVICE_CONFIG_BLE_SET_PHY_2M_REQ
 *
 * Enables/disables the Gap_LeSetPhy request to switch to 2M; enabled by default.
 * May be disabled on applications for interoperability reasons.
 */
#ifndef CHIP_DEVICE_CONFIG_BLE_SET_PHY_2M_REQ
#define CHIP_DEVICE_CONFIG_BLE_SET_PHY_2M_REQ 1
#endif // CHIP_DEVICE_CONFIG_BLE_SET_PHY_2M_REQ

#define CHIP_DEVICE_CONFIG_ENABLE_WIFI_TELEMETRY 0
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY 0
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_TELEMETRY_FULL 0

#define CHIP_DEVICE_CONFIG_CHIPOBLE_ENABLE_ADVERTISING_AUTOSTART 0

#define CHIP_DEVICE_CONFIG_ENABLE_PAIRING_AUTOSTART 0

#define CHIP_DEVICE_CONFIG_THREAD_TASK_PRIORITY 3

#define CHIP_DEVICE_CONFIG_CHIP_TASK_PRIORITY 2

#if CHIP_ENABLE_OPENTHREAD
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD 1
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_SRP_CLIENT 1
#define CHIP_DEVICE_CONFIG_ENABLE_THREAD_DNS_CLIENT 1
#endif

#if CHIP_DEVICE_CONFIG_ENABLE_SED

#ifndef CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL
#define CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL chip::System::Clock::Milliseconds32(NXP_OT_IDLE_INTERVAL)
#endif // CHIP_DEVICE_CONFIG_ICD_SLOW_POLL_INTERVAL

#ifndef CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL
#define CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL chip::System::Clock::Milliseconds32(NXP_OT_ACTIVE_INTERVAL)
#endif // CHIP_DEVICE_CONFIG_ICD_FAST_POLL_INTERVAL

#endif

#define CHIP_DEVICE_CONFIG_ENABLE_TEST_SETUP_PARAMS 1

#include <platform/nxp/k32w/common/CHIPDevicePlatformRamStorageConfig.h>
