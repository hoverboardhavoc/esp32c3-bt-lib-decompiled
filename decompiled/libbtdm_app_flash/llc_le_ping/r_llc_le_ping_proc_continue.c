/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_le_ping.o -> r_llc_le_ping_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_le_ping_proc_continue(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = r_llc_proc_get(0);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 == param_2) {
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

