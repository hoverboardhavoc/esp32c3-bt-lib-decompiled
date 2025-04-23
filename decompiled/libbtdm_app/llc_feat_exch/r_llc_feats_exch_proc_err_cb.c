/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_feat_exch.o -> r_llc_feats_exch_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_feats_exch_proc_err_cb(uint param_1,uint param_2,char *param_3)

{
  int iVar1;
  char cVar2;
  
  if (param_2 == 2) {
    cVar2 = param_3[1];
_L29:
    if (cVar2 == '\0') {
      return;
    }
    if (cVar2 != '\x1a') goto _L31;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x0e') {
        return;
      }
      cVar2 = param_3[2];
      goto _L29;
    }
    if (param_2 == 0) {
      cVar2 = *param_3;
      goto _L29;
    }
    if (param_3[1] != '\x0e') {
      return;
    }
  }
  iVar1 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar1 + 0xd)) && (iVar1 = *(int *)(&llc_env + param_1 * 4), iVar1 != 0))
  {
    *(byte *)(iVar1 + 0x30) = *(byte *)(iVar1 + 0x30) & 0xf7;
  }
  cVar2 = '\x1a';
_L31:
                    /* WARNING: Could not recover jumptable at 0x0001028e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x5b0))(param_1,cVar2,*(code **)(_r_ip_funcs_p + 0x5b0));
  return;
}

