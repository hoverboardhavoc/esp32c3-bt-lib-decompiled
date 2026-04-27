/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_con_upd.o -> r_llc_rem_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_rem_con_upd_proc_err_cb(uint param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  if (param_2 == 2) {
    bVar1 = param_3[1];
_L191:
    iVar3 = 9;
_L185:
    uVar2 = (uint)bVar1;
    if (uVar2 != 0) {
      r_llc_rem_con_upd_proc_continue_hack(param_1,iVar3,uVar2);
    }
  }
  else {
    if (param_2 == 3) {
      if (param_3[1] == 0x10) {
        bVar1 = param_3[2];
        goto _L191;
      }
    }
    else if (param_2 == 0) {
      bVar1 = *param_3;
      iVar3 = 0xb;
      goto _L185;
    }
    iVar3 = 9;
    uVar2 = 0;
  }
  r_ble_log_internal_x1(0x804f008c,iVar3 << 0x18 | param_2 << 8 | param_1 | uVar2 << 0x10);
  return;
}

