/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_disconnect.o -> r_llc_disconnect_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_disconnect_proc_err_cb(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (param_2 == 0) {
    cVar1 = *param_3;
    iVar2 = r_llc_proc_get(0);
    if (cVar1 == '\0') {
      iVar5 = *(int *)(&llc_env + param_1 * 4);
      iVar3 = r_llc_proc_state_get();
      if (iVar3 == 0) {
        r_llc_llcp_state_set(param_1,2,3);
        *(undefined1 *)(iVar5 + 0x47) = *(undefined1 *)(iVar2 + 9);
        r_llc_proc_timer_set(param_1,1,0);
        *(undefined1 *)(iVar5 + 0x46) = *(undefined1 *)(iVar2 + 9);
        llc_ll_terminate_ind_pdu_send(param_1,*(undefined1 *)(iVar2 + 8));
        r_llc_proc_state_set(iVar2,param_1,1);
        r_llc_proc_timer_pause_set(param_1,0,0);
        r_llc_proc_timer_set(param_1,0,1);
        return;
      }
      if (iVar3 == 1) {
        r_llc_disconnect(param_1,*(undefined1 *)(iVar2 + 9),1);
      }
      else {
        uVar4 = r_llc_proc_state_get(iVar2);
        r_assert_param(param_1,uVar4,"llc_disconnect.c",0xc0);
      }
    }
    r_llc_proc_unreg(param_1,0);
    return;
  }
  if (3 < param_2) {
    r_assert_param("llc_disconnect.c",0xf9);
    return;
  }
  return;
}

