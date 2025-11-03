/*
 * Last changed at upstream commit 099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * https://github.com/espressif/esp32c3-bt-lib/commit/099a7e1ab87dd977754fc4ad35678ab7ebf2f2a2
 * Upstream date: 2025-11-03 14:51:49 +0800
 * Upstream subject: feat(bt): Update bt lib for ESP32-C3 and ESP32-S3(0871069)
 * Source: libbtdm_app_flash -> lld.o -> r_lld_rpa_renew_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_rpa_renew_evt_canceled_cbk(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (_lld_rpa_renew_env == 0) {
    uVar2 = 0x4a5;
  }
  else {
    r_ble_log_internal_x1(0x2028004f,*(undefined1 *)(param_1 + 0x16));
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = r_sch_arb_insert(param_1);
    if (iVar1 == 0) {
      return;
    }
    uVar2 = 0x4a0;
  }
  r_assert_err(0,"lld.c",uVar2);
  return;
}

