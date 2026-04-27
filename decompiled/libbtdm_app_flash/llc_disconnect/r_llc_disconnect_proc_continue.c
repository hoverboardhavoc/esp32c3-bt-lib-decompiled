/*
 * Last changed at upstream commit 58d499bba1019a80a622df60aa38f59c1e4565ba
 * https://github.com/espressif/esp32c3-bt-lib/commit/58d499bba1019a80a622df60aa38f59c1e4565ba
 * Upstream date: 2026-04-27 15:45:42 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(2f683593)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> r_llc_disconnect_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_disconnect_proc_continue(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = r_llc_proc_get(0);
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  if (param_2 == 0) {
    iVar2 = r_llc_proc_state_get();
    if (iVar2 == 0) {
      r_llc_llcp_state_set(param_1,2,3);
      *(undefined1 *)(iVar4 + 0x47) = *(undefined1 *)(iVar1 + 9);
      r_llc_proc_timer_set(param_1,1,0);
      *(undefined1 *)(iVar4 + 0x46) = *(undefined1 *)(iVar1 + 9);
      llc_ll_terminate_ind_pdu_send(param_1,*(undefined1 *)(iVar1 + 8));
      r_llc_proc_state_set(iVar1,param_1,1);
      r_llc_proc_timer_pause_set(param_1,0,0);
      r_llc_proc_timer_set(param_1,0,1);
      return;
    }
    if (iVar2 == 1) {
      r_llc_disconnect(param_1,*(undefined1 *)(iVar1 + 9),1);
    }
    else {
      iVar4 = r_llc_proc_state_get(iVar1);
      r_ble_log_internal_x1(0x804f0092,iVar4 << 8 | param_1);
      uVar3 = r_llc_proc_state_get(iVar1);
      r_assert_param(param_1,uVar3,"llc_disconnect.c",0xc2);
    }
  }
  r_llc_proc_unreg(param_1,0);
  return;
}

