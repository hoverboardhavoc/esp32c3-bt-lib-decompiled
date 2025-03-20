/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_per_adv.o -> r_lld_per_adv_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_lld_per_adv_cleanup(uint param_1)

{
  int iVar1;
  
  if (*(int *)(&lld_per_adv_env + param_1 * 4) == 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x40) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1(0x40080004,param_1);
        return;
      }
    }
  }
  else {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x40) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x40080002,
                   (uint)*(ushort *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x4c) << 0x10 |
                   param_1);
      }
    }
    r_ke_free(*(undefined4 *)(&lld_per_adv_env + param_1 * 4));
    *(undefined4 *)(&lld_per_adv_env + param_1 * 4) = 0;
  }
  return;
}

