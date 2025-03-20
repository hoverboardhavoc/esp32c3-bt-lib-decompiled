/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
 * Source: libbtdm_app_flash -> lld_test.o -> r_lld_test_evt_canceled_cbk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_test_evt_canceled_cbk(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (_lld_test_env != param_1) {
    r_assert_err(0,"lld_test.c",0x1ba);
  }
  if (param_1 == 0) {
    uVar2 = 0x1ce;
  }
  else {
    iVar1 = r_sdk_config_get_opts_ext();
    if ((*(uint *)(iVar1 + 0x28) & 0x400) != 0) {
      iVar1 = r_sdk_config_get_opts_ext();
      if (*(byte *)(iVar1 + 0x2c) < 3) {
        r_ble_log_internal_x1
                  (0x402e0006,
                   CONCAT11(*(undefined1 *)(param_1 + 0x2a),*(undefined1 *)(param_1 + 0x26)));
      }
    }
    if (*(char *)(param_1 + 0x2a) != '\0') {
      r_assert_err(0,"lld_test.c",0x1c1);
    }
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = r_sch_arb_insert(param_1);
    uVar2 = 0x1c9;
    if (iVar1 == 0) {
      return;
    }
  }
  r_assert_err(0,"lld_test.c",uVar2);
  return;
}

