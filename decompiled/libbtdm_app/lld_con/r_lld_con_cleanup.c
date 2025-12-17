/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_cleanup
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_cleanup(int param_1,int param_2,undefined1 param_3)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  code *pcVar9;
  uint uVar10;
  int iVar11;
  
  iVar11 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar11 == 0) {
    return;
  }
  if (param_2 != 0) {
    uVar10 = param_1 << 8 | 1;
    puVar4 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x212,uVar10,0xff,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar4 = param_3;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    iVar5 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (iVar11 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    while (*(char *)(iVar11 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar11 + 0x8e);
      bVar2 = *(byte *)(iVar11 + 0x90);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar8 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar8 + 2 + iVar6);
      if ((uVar3 & 3) == 3) {
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        (**(code **)(_r_ip_funcs_p + 0xf8))
                  (*(undefined2 *)(iVar8 + 4 + iVar6),*(code **)(_r_ip_funcs_p + 0xf8));
        if (*(int *)(iVar11 + 0x24) != 0) {
          uVar7 = 0x7db;
          pcVar9 = *(code **)(_r_plf_funcs_p + 8);
          goto _L314;
        }
      }
      else if ((uVar3 & 3) == 0) {
        uVar7 = 0x7e4;
        pcVar9 = *(code **)(_r_plf_funcs_p + 8);
_L314:
        (*pcVar9)(0,"lld_con.c",uVar7,pcVar9);
      }
      *(char *)(iVar11 + 0x92) = *(char *)(iVar11 + 0x92) + -1;
      *(byte *)(iVar11 + 0x90) = *(char *)(iVar11 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar11 + 0x24) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xf8))
                (*(undefined2 *)(*(int *)(iVar11 + 0x24) + 4),*(code **)(_r_ip_funcs_p + 0xf8));
    }
    while (iVar5 != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd0))
                (*(undefined2 *)(iVar5 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
      if (DAT_0001604d != '\0') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (0x20e,uVar10,0xff,*(code **)(_r_modules_funcs_p + 0xe4));
      }
      iVar5 = (**(code **)(_r_modules_funcs_p + 0x40))
                        (iVar11 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x730))(4,param_1,*(code **)(_r_ip_funcs_p + 0x730));
  (**(code **)(_r_modules_funcs_p + 0x110))
            (*(undefined4 *)(&lld_con_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
  (&g_event_empty)[param_1] = 0;
  iVar11 = _r_modules_funcs_p;
  *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
  (**(code **)(iVar11 + 0x200))(param_1,*(code **)(iVar11 + 0x200));
                    /* WARNING: Could not recover jumptable at 0x00011630. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x1d8))(param_1,*(code **)(_r_modules_funcs_p + 0x1d8));
  return;
}

