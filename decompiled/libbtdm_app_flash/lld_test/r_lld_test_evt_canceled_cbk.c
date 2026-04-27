/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
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
    r_assert_err(0,0x10000,0x1be);
  }
  if (param_1 == 0) {
    uVar2 = 0x1d2;
  }
  else {
    r_ble_log_internal_x1
              (0x40260168,CONCAT11(*(undefined1 *)(param_1 + 0x2a),*(undefined1 *)(param_1 + 0x26)))
    ;
    if (*(char *)(param_1 + 0x2a) != '\0') {
      r_assert_err(0,0x10000,0x1c5);
    }
    *(char *)(param_1 + 0x16) = *(char *)(param_1 + 0x16) + rwip_priority;
    iVar1 = r_sch_arb_insert(param_1);
    uVar2 = 0x1cd;
    if (iVar1 == 0) {
      return;
    }
  }
  r_assert_err(0,0x10000,uVar2);
  return;
}

