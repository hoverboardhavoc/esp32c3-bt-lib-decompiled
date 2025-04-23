/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
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
  undefined4 uVar3;
  int iVar4;
  
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
    param_2 = 0x1f;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    r_llc_hci_feats_info_send(param_1,param_2,iVar4 + 0x30);
    *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xfb;
  }
  r_llc_proc_unreg(param_1,0);
  return;
}

