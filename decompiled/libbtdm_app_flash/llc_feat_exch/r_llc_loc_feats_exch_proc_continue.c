/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> r_llc_loc_feats_exch_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_loc_feats_exch_proc_continue(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(&llc_env + param_1 * 4);
  iVar2 = r_llc_proc_get(0);
  iVar3 = r_llc_proc_state_get();
  if (iVar3 == 0) {
    if ((*(ushort *)(iVar1 + 0x42) & 0x80) == 0) {
      llc_ll_feature_req_pdu_send(param_1);
      r_llc_proc_state_set(iVar2,param_1,1);
      r_llc_proc_timer_set(param_1,0,1);
      return;
    }
  }
  else if (iVar3 == 1) {
    r_llc_proc_timer_set(param_1,0,0);
  }
  else {
    uVar4 = r_llc_proc_state_get(iVar2);
    r_assert_param(param_1,uVar4,"llc_feat_exch.c",0x102);
    param_2 = 0x1f;
  }
  if (*(char *)(iVar2 + 8) != '\0') {
    r_llc_hci_feats_info_send(param_1,param_2,iVar1 + 0x30);
    *(byte *)(iVar1 + 0x45) = *(byte *)(iVar1 + 0x45) & 0xfb;
  }
  r_llc_proc_unreg(param_1,0);
  return;
}

