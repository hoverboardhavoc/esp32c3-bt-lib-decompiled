/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx(int param_1,undefined4 param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ushort uVar5;
  int iVar6;
  
  iVar2 = *(int *)(&lld_con_env + param_1 * 4);
  iVar3 = (**(code **)(_r_ip_funcs_p + 0x820))(1,param_1,param_2,*(code **)(_r_ip_funcs_p + 0x820));
  if (iVar3 == 0) {
    *(ushort *)(iVar2 + 0x84) = *(ushort *)(iVar2 + 0x84) & 0xfffb;
    while (iVar3 = (**(code **)(_r_ip_funcs_p + 0x2a4))(param_1,*(code **)(_r_ip_funcs_p + 0x2a4)),
          iVar3 != 0) {
      iVar6 = (uint)*(byte *)(_p_lld_env + 0xd8) * 0x14;
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar5 = *(ushort *)(iVar6 + 2 + iVar4);
      iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar6 + 4 + iVar4);
      if (((uVar5 & 1) == 0) &&
         ((**(code **)(_r_ip_funcs_p + 0x39c))(param_1,iVar2,*(code **)(_r_ip_funcs_p + 0x39c)),
         (uVar5 & 8) == 0)) {
        *(undefined4 *)(iVar2 + 0x58) = *(undefined4 *)(iVar2 + 0x50);
        if ((uVar5 & 0x66) == 0) {
          if ((uVar5 & 0x10) == 0) {
            iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
            uVar5 = uVar1 >> 8;
            *(undefined2 *)(iVar2 + 0x98) = *(undefined2 *)(param_1 * 0x5a + 0x50 + iVar4);
            if ((uVar5 != 0) && ((uVar1 & 3) != 0)) {
              if ((4 < uVar5) && ((*(ushort *)(iVar2 + 0x84) & 0x20) != 0)) {
                uVar5 = uVar5 - 4;
              }
              iVar4 = (**(code **)(_r_ip_funcs_p + 0x394))
                                (param_1,iVar2,uVar5,*(code **)(_r_ip_funcs_p + 0x394));
              if (iVar4 == 0) {
                iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))
                                  (0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
                *(undefined2 *)(iVar6 + 0x12 + iVar4) = 0;
              }
            }
          }
          else {
            *(ushort *)(iVar2 + 0x84) = *(ushort *)(iVar2 + 0x84) | 0x80;
            *(undefined1 *)(iVar2 + 0x8f) = 2;
          }
        }
      }
      else {
        iVar3 = 0;
      }
      (**(code **)(_r_ip_funcs_p + 0x390))(iVar2,iVar3,*(code **)(_r_ip_funcs_p + 0x390));
      (**(code **)(_r_ip_funcs_p + 0x2a8))(*(code **)(_r_ip_funcs_p + 0x2a8));
    }
                    /* WARNING: Could not recover jumptable at 0x00011e3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_r_ip_funcs_p + 0x820))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x820));
    return;
  }
  return;
}

