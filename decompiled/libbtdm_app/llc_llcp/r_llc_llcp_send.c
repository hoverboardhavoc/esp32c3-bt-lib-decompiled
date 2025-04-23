/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> llc_llcp.o -> r_llc_llcp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_llc_llcp_send(int param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  ushort auStack_32 [7];
  
  if (param_2 != (byte *)0x0) {
    iVar5 = *(int *)(&llc_env + param_1 * 4);
    if (iVar5 != 0) {
      if (*param_2 < 0x23) {
        auStack_32[0] = *(ushort *)(llcp_pdu_handler + (uint)*param_2 * 0xc + 8);
        iVar2 = (**(code **)(_r_modules_funcs_p + 0x120))
                          (auStack_32[0] + 0xc,2,*(code **)(_r_modules_funcs_p + 0x120));
        bVar1 = *param_2;
        *(undefined4 *)(iVar2 + 4) = param_3;
        iVar3 = (**(code **)(_r_modules_funcs_p + 0x10))
                          (iVar2 + 9,param_2,auStack_32,0x30,
                           *(undefined4 *)(llcp_pdu_handler + (uint)bVar1 * 0xc + 4),
                           *(code **)(_r_modules_funcs_p + 0x10));
        if (iVar3 == 0) {
          *(char *)(iVar2 + 8) = (char)auStack_32[0];
          (**(code **)(_r_modules_funcs_p + 0x44))
                    (iVar5 + 0x28,iVar2,*(code **)(_r_modules_funcs_p + 0x44));
          (**(code **)(_r_ip_funcs_p + 0x5b8))(param_1,*(code **)(_r_ip_funcs_p + 0x5b8));
        }
        else {
          (**(code **)(_r_plf_funcs_p + 0xc))
                    (*param_2,"llc_llcp.c",0x32f,*(code **)(_r_plf_funcs_p + 0xc));
        }
        return;
      }
    }
  }
  if (param_2 == (byte *)0x0) {
    uVar4 = 0xffff;
  }
  else {
    uVar4 = (uint)*param_2;
  }
                    /* WARNING: Could not recover jumptable at 0x0001064e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_plf_funcs_p + 0xc))
            (param_1,uVar4,"llc_llcp.c",0x33e,*(code **)(_r_plf_funcs_p + 0xc));
  return;
}

