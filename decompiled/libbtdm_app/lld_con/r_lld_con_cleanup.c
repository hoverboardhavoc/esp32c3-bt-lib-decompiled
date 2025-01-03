/*
 * Last changed at upstream commit ed99228396aaa18935b575d600bc19da38dc4746
 * https://github.com/espressif/esp32c3-bt-lib/commit/ed99228396aaa18935b575d600bc19da38dc4746
 * Upstream date: 2025-01-03 16:50:09 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(fd62b31)
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
  ushort uVar7;
  undefined4 uVar8;
  int iVar9;
  code *pcVar10;
  uint uVar11;
  int iVar12;
  
  iVar12 = *(int *)(&lld_con_env + param_1 * 4);
  if (iVar12 == 0) {
    return;
  }
  if (param_2 != 0) {
    uVar11 = param_1 << 8 | 1;
    puVar4 = (undefined1 *)
             (**(code **)(_r_modules_funcs_p + 200))
                       (0x212,uVar11,0xff,1,*(code **)(_r_modules_funcs_p + 200));
    *puVar4 = param_3;
    (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
    iVar5 = (**(code **)(_r_modules_funcs_p + 0x40))
                      (iVar12 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    while (*(char *)(iVar12 + 0x92) != '\0') {
      bVar1 = *(byte *)(iVar12 + 0x8e);
      bVar2 = *(byte *)(iVar12 + 0x90);
      iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar9 = ((uint)bVar1 * 9 + (uint)bVar2 & 0xff) * 0xe;
      uVar3 = *(ushort *)(iVar6 + iVar9 + 2);
      uVar7 = uVar3 & 3;
      if ((uVar3 & 3) == 0) {
_L300:
        uVar8 = 0x795;
        pcVar10 = *(code **)(_r_plf_funcs_p + 8);
_L321:
        (*pcVar10)(0,"lld_con.c",uVar8,pcVar10);
      }
      else if (2 < uVar7) {
        if (uVar7 != 3) goto _L300;
        iVar6 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        (**(code **)(_r_ip_funcs_p + 0xf8))
                  (*(undefined2 *)(iVar9 + 4 + iVar6),*(code **)(_r_ip_funcs_p + 0xf8));
        if (*(int *)(iVar12 + 0x24) == 0) goto _L301;
        uVar8 = 0x78c;
        pcVar10 = *(code **)(_r_plf_funcs_p + 8);
        goto _L321;
      }
_L301:
      *(char *)(iVar12 + 0x92) = *(char *)(iVar12 + 0x92) + -1;
      *(byte *)(iVar12 + 0x90) = *(char *)(iVar12 + 0x90) + 1U & 1;
    }
    if (*(int *)(iVar12 + 0x24) != 0) {
      (**(code **)(_r_ip_funcs_p + 0xf8))
                (*(undefined2 *)(*(int *)(iVar12 + 0x24) + 4),*(code **)(_r_ip_funcs_p + 0xf8));
    }
    while (iVar5 != 0) {
      (**(code **)(_r_ip_funcs_p + 0xd0))
                (*(undefined2 *)(iVar5 + 4),*(code **)(_r_ip_funcs_p + 0xd0));
      if (DAT_0001604d != '\0') {
        (**(code **)(_r_modules_funcs_p + 0xe4))
                  (0x20e,uVar11,0xff,*(code **)(_r_modules_funcs_p + 0xe4));
      }
      iVar5 = (**(code **)(_r_modules_funcs_p + 0x40))
                        (iVar12 + 0x28,*(code **)(_r_modules_funcs_p + 0x40));
    }
  }
  (**(code **)(_r_ip_funcs_p + 0x730))(4,param_1,*(code **)(_r_ip_funcs_p + 0x730));
  (**(code **)(_r_modules_funcs_p + 0x110))
            (*(undefined4 *)(&lld_con_env + param_1 * 4),*(code **)(_r_modules_funcs_p + 0x110));
  (&g_event_empty)[param_1] = 0;
  iVar12 = _r_modules_funcs_p;
  *(undefined4 *)(&lld_con_env + param_1 * 4) = 0;
  (**(code **)(iVar12 + 0x200))(param_1,*(code **)(iVar12 + 0x200));
                    /* WARNING: Could not recover jumptable at 0x000116fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_modules_funcs_p + 0x1d8))(param_1);
  return;
}

