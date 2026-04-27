/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> ke_event.o -> r_ke_event_callback_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int r_ke_event_callback_set(uint param_1,int param_2)

{
  int iVar1;
  
  if ((0xe < param_1) || (param_2 == 0)) {
    r_assert_param(param_1,"ke_event.c",0x62);
    if (0xe < param_1) {
      iVar1 = 3;
      goto _L4;
    }
  }
  *(int *)(memset + param_1 * 4) = param_2;
  iVar1 = 0;
_L4:
  r_ble_log_internal_x2(0x400a0230,iVar1 << 8 | param_1);
  return iVar1;
}

