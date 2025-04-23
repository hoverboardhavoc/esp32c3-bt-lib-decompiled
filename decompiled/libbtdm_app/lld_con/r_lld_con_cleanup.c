/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_cleanup(int param_1,int param_2,undefined1 param_3)

{
  ushort uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  uint uVar8;
  int iVar9;
  
  iVar9 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar9 == 0) {
    return;
  }
  if (param_2 != 0) {
    uVar8 = param_1 << 8 | 1;
    puVar3 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x212,uVar8,0xff,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar3 = param_3;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    iVar4 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (iVar9 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    while (*(char *)(iVar9 + 0x92) != '\0') {
      iVar2 = ((uint)*(byte *)(iVar9 + 0x8e) * 9 + (uint)*(byte *)(iVar9 + 0x90) & 0xff) * 0xe;
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      uVar1 = *(ushort *)(iVar2 + 2 + iVar5);
      if ((uVar1 & 3) == 3) {
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        (**(code **)(_r_ip_funcs_p + 0xf8))
                  (*(undefined2 *)(iVar2 + 4 + iVar5),*(code **)(_r_ip_funcs_p + 0xf8));
        if (*(int *)(iVar9 + 0x24) != 0) {
          uVar6 = 0x79f;
          pcVar7 = *(code **)(_r_plf_funcs_p + 8);
          goto _L315;
        }
      }
      else if ((uVar1 & 3) == 0) {
        uVar6 = 0x7a8;
        pcVar7 = *(code **)(_r_plf_funcs_p + 8);
_L315:
        (*pcVar7)(0,"lld_con.c",uVar6,pcVar7);
      }
      *(char *)(iVar9 + 0x92) = *(char *)(iVar9 + 0x92) + -1;
      *(byte *)(iVar9 + 0x90) = *(char *)(iVar9 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar9 + 0x24) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xf8))
                (*(undefined2 *)(*(int *)(iVar9 + 0x24) + 4),*(code **)(_r_ip_funcs_p + 0xf8));
    }
    while (iVar4 != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd0))
                (*(undefined2 *)(iVar4 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
      if (DAT_0001604d != '\0') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (0x20e,uVar8,0xff,*(code **)(_r_modules_funcs_p + 0xe4));
      }
      iVar4 = (**(code **)(_r_modules_funcs_p + 0x40))
                        (iVar9 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x730))(4,param_1,*(code **)(_r_ip_funcs_p + 0x730));
  (**(code **)(_r_modules_funcs_p + 0x110))
            (*(undefined4 *)(&lld_con_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
  (&g_event_empty)[param_1] = 0;
  iVar9 = _r_modules_funcs_p;
  *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
  (**(code **)(iVar9 + 0x200))(param_1,*(code **)(iVar9 + 0x200));
                    /* WARNING: Could not recover jumptable at 0x00011662. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x1d8))(param_1,*(code **)(_r_modules_funcs_p + 0x1d8));
  return;
}

