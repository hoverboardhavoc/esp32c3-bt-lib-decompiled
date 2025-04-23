/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app_flash -> llc_feat_exch.o -> r_llc_feats_exch_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void r_llc_feats_exch_proc_err_cb(uint param_1,uint param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  if (param_2 == 2) {
    cVar4 = param_3[1];
_L29:
    if (cVar4 == '\0') {
      return;
    }
    if (cVar4 != '\x1a') goto _L31;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x0e') {
        return;
      }
      cVar4 = param_3[2];
      goto _L29;
    }
    if (param_2 == 0) {
      cVar4 = *param_3;
      goto _L29;
    }
    if (param_3[1] != '\x0e') {
      return;
    }
  }
  iVar3 = r_sdk_config_get_opts();
  if ((param_1 < *(byte *)(iVar3 + 0xd)) && (iVar3 = *(int *)(&llc_env + param_1 * 4), iVar3 != 0))
  {
    *(byte *)(iVar3 + 0x30) = *(byte *)(iVar3 + 0x30) & 0xf7;
  }
  cVar4 = '\x1a';
_L31:
  iVar5 = *(int *)(&llc_env + param_1 * 4);
  iVar3 = r_llc_proc_get(0);
  iVar1 = r_llc_proc_state_get();
  if (iVar1 == 0) {
    if ((*(ushort *)(iVar5 + 0x42) & 0x80) == 0) {
      llc_ll_feature_req_pdu_send(param_1);
      r_llc_proc_state_set(iVar3,param_1,1);
      r_llc_proc_timer_set(param_1,0,1);
      return;
    }
  }
  else if (iVar1 == 1) {
    r_llc_proc_timer_set(param_1,0,0);
  }
  else {
    uVar2 = r_llc_proc_state_get(iVar3);
    r_assert_param(param_1,uVar2,"llc_feat_exch.c",0x102);
    cVar4 = '\x1f';
  }
  if (*(char *)(iVar3 + 8) != '\0') {
    r_llc_hci_feats_info_send(param_1,cVar4,iVar5 + 0x30);
    *(byte *)(iVar5 + 0x45) = *(byte *)(iVar5 + 0x45) & 0xfb;
  }
  r_llc_proc_unreg(param_1,0);
  return;
}

