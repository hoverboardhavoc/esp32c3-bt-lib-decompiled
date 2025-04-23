/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_feat_exch.o -> r_llc_loc_feats_exch_proc_continue
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_feats_exch_proc_continue(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  
  iVar4 = *(int *)(&llc_env + param_1 * 4);
  iVar1 = (**(code **)(_r_ip_funcs_p + 0x674))(0,*(code **)(_r_ip_funcs_p + 0x674));
  iVar2 = (**(code **)(_r_ip_funcs_p + 0x680))(*(code **)(_r_ip_funcs_p + 0x680));
  if (iVar2 == 0) {
    if ((*(ushort *)(iVar4 + 0x42) & 0x80) == 0) {
      llc_ll_feature_req_pdu_send(param_1);
      (**(code **)(_r_ip_funcs_p + 0x684))(iVar1,param_1,1,*(code **)(_r_ip_funcs_p + 0x684));
                    /* WARNING: Could not recover jumptable at 0x0001020a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,1,*(code **)(_r_ip_funcs_p + 0x68c));
      return;
    }
  }
  else if (iVar2 == 1) {
    (**(code **)(_r_ip_funcs_p + 0x68c))(param_1,0,0,*(code **)(_r_ip_funcs_p + 0x68c));
  }
  else {
    pcVar5 = *(code **)(_r_plf_funcs_p + 0xc);
    uVar3 = (**(code **)(_r_ip_funcs_p + 0x680))(iVar1,*(code **)(_r_ip_funcs_p + 0x680));
    (*pcVar5)(param_1,uVar3,"llc_feat_exch.c",0x102);
    param_2 = 0x1f;
  }
  if (*(char *)(iVar1 + 8) != '\0') {
    (**(code **)(_r_ip_funcs_p + 0x5ac))
              (param_1,param_2,iVar4 + 0x30,*(code **)(_r_ip_funcs_p + 0x5ac));
    *(byte *)(iVar4 + 0x45) = *(byte *)(iVar4 + 0x45) & 0xfb;
  }
                    /* WARNING: Could not recover jumptable at 0x00010258. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x690))(param_1,0,*(code **)(_r_ip_funcs_p + 0x690));
  return;
}

