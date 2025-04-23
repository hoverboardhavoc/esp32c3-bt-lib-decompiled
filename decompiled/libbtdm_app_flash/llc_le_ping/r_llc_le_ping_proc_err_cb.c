/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_le_ping_proc_err_cb(undefined4 param_1,uint param_2,undefined1 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (param_2 == 1) {
    if (param_3[1] == '\x12') {
      uVar3 = 0;
      goto _L23;
    }
  }
  else {
    if (param_2 < 2) {
      uVar3 = *param_3;
_L23:
      uVar1 = r_llc_proc_get(0,uVar3);
      iVar2 = r_llc_proc_state_get();
      if (iVar2 == 1) {
        iVar2 = r_llc_proc_state_get(uVar1);
        if (iVar2 == 0) {
          llc_ll_ping_req_pdu_send(param_1);
          r_llc_proc_timer_set(param_1,0,1);
          return;
        }
        if (iVar2 != 1) {
          uVar1 = r_llc_proc_state_get(uVar1);
          r_assert_param(param_1,uVar1,"llc_le_ping.c",0xf5);
          return;
        }
      }
      r_llc_proc_timer_set(param_1,0,0);
      r_llc_proc_unreg(param_1,0);
      return;
    }
    if (1 < (param_2 - 2 & 0xff)) {
      r_assert_param("llc_le_ping.c",0x12e);
      return;
    }
  }
  return;
}

