/*
 * Last changed at upstream commit d2414a5dd958b32ca53382b441d24d97a0345a55
 * https://github.com/espressif/esp32c3-bt-lib/commit/d2414a5dd958b32ca53382b441d24d97a0345a55
 * Upstream date: 2025-03-20 20:11:19 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(03d0f8a6)
 * Source: libbtdm_app_flash -> ke_event.o -> r_ke_event_callback_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_ke_event_callback_set(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((0xe < param_1) || (param_2 == 0)) {
    r_assert_param(param_1,param_2,"ke_event.c",0x62);
    if (0xe < param_1) {
      iVar2 = 3;
      goto _L4;
    }
  }
  *(int *)(memset + param_1 * 4) = param_2;
  iVar2 = 0;
_L4:
  iVar1 = r_sdk_config_get_opts_ext();
  if ((*(uint *)(iVar1 + 0x28) & 2) != 0) {
    iVar1 = r_sdk_config_get_opts_ext();
    if (*(byte *)(iVar1 + 0x2c) < 3) {
      r_ble_log_internal_x2(0x40050002,iVar2 << 8 | param_1,param_2);
    }
  }
  return iVar2;
}

