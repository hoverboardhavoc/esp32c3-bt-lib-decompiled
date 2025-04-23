/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_ll_reject_ind_pdu_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_ll_reject_ind_pdu_send(uint param_1,uint param_2,undefined1 param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((((param_1 < *(byte *)(iVar1 + 0xd)) && (*(int *)(&llc_env + param_1 * 4) != 0)) &&
      (((int)(uint)*(byte *)(*(int *)(&llc_env + param_1 * 4) + 0x30) >> 2 & 1U) != 0)) ||
     (0xd < param_2)) {
    uStack_14 = 0x11;
    uStack_13 = (undefined1)param_2;
    uStack_12 = param_3;
    (**(code **)(_r_ip_funcs_p + 0x5b4))(param_1,&uStack_14,*(code **)(_r_ip_funcs_p + 0x5b4));
  }
  else {
    uStack_14 = 0xd;
    uStack_13 = param_3;
    (**(code **)(_r_ip_funcs_p + 0x5b4))
              (param_1,&uStack_14,param_4,*(code **)(_r_ip_funcs_p + 0x5b4));
  }
  return;
}

