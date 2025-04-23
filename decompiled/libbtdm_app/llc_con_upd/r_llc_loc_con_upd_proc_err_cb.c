/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_con_upd.o -> r_llc_loc_con_upd_proc_err_cb
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_loc_con_upd_proc_err_cb(uint param_1,uint param_2,char *param_3)

{
  ushort uVar1;
  int iVar2;
  char cVar3;
  
  uVar1 = 3 - (*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) & 0xff;
  if (param_2 == 2) {
    cVar3 = param_3[1];
_L173:
    if (cVar3 == '\0') {
      return;
    }
    if (1 < (byte)(cVar3 - 0x19U)) goto _L175;
  }
  else {
    if (2 < param_2) {
      if (param_2 != 3) {
        return;
      }
      if (param_3[1] != '\x0f') {
        return;
      }
      cVar3 = param_3[2];
      goto _L173;
    }
    if (param_2 == 0) {
      cVar3 = *param_3;
      uVar1 = 6;
      goto _L173;
    }
    if (param_3[1] != '\x0f') {
      return;
    }
    cVar3 = '\x1a';
  }
  iVar2 = (**(code **)(_r_plf_funcs_p + 0x38))(*(code **)(_r_plf_funcs_p + 0x38));
  if ((param_1 < *(byte *)(iVar2 + 0xd)) && (iVar2 = *(int *)(&llc_env + param_1 * 4), iVar2 != 0))
  {
    *(byte *)(iVar2 + 0x30) = *(byte *)(iVar2 + 0x30) & 0xfd;
  }
_L175:
                    /* WARNING: Could not recover jumptable at 0x00011154. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x5f4))(param_1,uVar1,cVar3,*(code **)(_r_ip_funcs_p + 0x5f4));
  return;
}

