/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> r_llc_feats_exch_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_feats_exch_proc_err_cb(uint param_1,int param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  
  if (param_2 == 1) {
    if (param_3[1] != '\x0e') {
      return;
    }
  }
  else {
    if (param_2 == 0) {
      cVar5 = *param_3;
    }
    else if (param_2 == 2) {
      cVar5 = param_3[1];
    }
    else {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x0e') {
        return;
      }
      cVar5 = param_3[2];
    }
    if (cVar5 == '\0') {
      return;
    }
    if (cVar5 != '\x1a') goto _L29;
  }
  iVar4 = r_sdk_config_get_opts();
  cVar5 = '\x1a';
  if ((param_1 < *(byte *)(iVar4 + 0xd)) &&
     (iVar4 = *(int *)(&llc_env + param_1 * 4), cVar5 = '\x1a', iVar4 != 0)) {
    *(byte *)(iVar4 + 0x30) = *(byte *)(iVar4 + 0x30) & 0xf7;
  }
_L29:
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = r_llc_proc_get(0);
  iVar2 = r_llc_proc_state_get();
  if (iVar2 == 0) {
    if ((*(ushort *)(iVar4 + 0x42) & 0x80) == 0) {
      llc_ll_feature_req_pdu_send(param_1);
      r_llc_proc_state_set(iVar1,param_1,1);
      r_llc_proc_timer_set(param_1,0,1);
      return;
    }
  }
  else if (iVar2 == 1) {
    r_llc_proc_timer_set(param_1,0,0);
  }
  else {
    uVar3 = r_llc_proc_state_get(iVar1);
    r_assert_param(param_1,uVar3,"llc_feat_exch.c",0x102);
    cVar5 = '\x1f';
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    r_llc_hci_feats_info_send(param_1,cVar5,iVar4 + 0x30);
    *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xfb;
  }
  r_llc_proc_unreg(param_1,0);
  return;
}

