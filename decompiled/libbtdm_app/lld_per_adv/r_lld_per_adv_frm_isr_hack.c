/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_frm_isr_hack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_per_adv_frm_isr_hack(uint param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  uint uVar9;
  char cVar10;
  code *pcVar11;
  
  if (periodic_adv_data_need_to_set[param_1] != '\0') {
    *(undefined4 *)(*(int *)(&lld_per_adv_env + param_1 * 4) + 0x24) = 0;
    (**(code **)(_r_ip_funcs_p + 0x2d4))(0,0,1,*(code **)(_r_ip_funcs_p + 0x2d4));
    periodic_adv_data_need_to_set[param_1] = '\0';
  }
  iVar6 = (**(code **)(_r_ip_funcs_p + 0x848))
                    (1,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x848));
  if (iVar6 != 0) {
    return;
  }
  iVar6 = *(int *)(&lld_per_adv_env + param_1 * 4);
  if (iVar6 == 0) {
    (**(code **)(_r_plf_funcs_p + 8))(0x10000,0x43e,*(code **)(_r_plf_funcs_p + 8));
  }
  else {
    (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar6,1,*(code **)(_r_ip_funcs_p + 0x6b8));
    if (*(char *)(iVar6 + 0x53) == '\x02') {
      puVar7 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x208,0,0xff,*(code **)(_r_modules_funcs_p + 200));
      uVar1 = *(undefined1 *)(iVar6 + 0x52);
      puVar7[1] = 0;
      *puVar7 = uVar1;
      (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x2cc);
      uVar9 = param_1;
    }
    else {
      bVar2 = *(byte *)(iVar6 + 0x52);
      if (*(short *)(iVar6 + 0x24) != 0) {
        (**(code **)(_r_ip_funcs_p + 0x2d4))
                  (param_1,*(undefined1 *)(iVar6 + 0x26),1,*(code **)(_r_ip_funcs_p + 0x2d4));
        *(undefined2 *)(iVar6 + 0x24) = 0;
      }
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      iVar5 = ((uint)bVar2 * 9 & 0xff) * 0xe;
      uVar4 = *(ushort *)(iVar8 + iVar5);
      iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
      pcVar11 = *(code **)(_r_plf_funcs_p + 0xbc);
      *(ushort *)(iVar8 + iVar5) = (ushort)(((uint)uVar4 << 0x11) >> 0x11);
      iVar8 = (*pcVar11)(0x1400,pcVar11);
      if ((int)((uint)*(ushort *)(iVar5 + 6 + iVar8) << 0x13) < 0) {
        bVar2 = *(byte *)(iVar6 + 0x52);
        uVar9 = (**(code **)(_r_ip_funcs_p + 0x230))(*(code **)(_r_ip_funcs_p + 0x230));
        *(char *)(iVar6 + 0x57) = (char)uVar9;
        if (0x3f < uVar9) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2ea,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        uVar4 = *(ushort *)(iVar8 + iVar5 + 8);
        iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar8 + iVar5 + 8) = (ushort)uVar9 | uVar4 & 0xffc0;
        bVar3 = *(byte *)(iVar6 + 0x57);
        if ((bVar3 & 0xc0) != 0) {
          (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x635,*(code **)(_r_plf_funcs_p + 8));
        }
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        iVar8 = (uint)bVar2 * 0x5a + 0x26;
        uVar4 = *(ushort *)(iVar5 + iVar8);
        iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
        *(ushort *)(iVar5 + iVar8) = uVar4 & 0x3ff | (ushort)bVar3 << 10;
        uVar9 = 0;
        while( true ) {
          bVar2 = *(byte *)(iVar6 + 0x52);
          uVar9 = uVar9 + 1 & 0xff;
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          iVar5 = ((uint)bVar2 * 9 + uVar9 & 0xff) * 0xe;
          uVar4 = *(ushort *)(iVar8 + iVar5);
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar8 + iVar5) = uVar4 & 0x7fff;
          if (uVar9 == *(byte *)(iVar6 + 0x58) - 1) break;
          bVar2 = *(byte *)(iVar6 + 0x57);
          if (0x3f < bVar2) {
            (**(code **)(_r_plf_funcs_p + 8))(0,0x10000,0x2ea,*(code **)(_r_plf_funcs_p + 8));
          }
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          uVar4 = *(ushort *)(iVar8 + iVar5 + 8);
          iVar8 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1400,*(code **)(_r_plf_funcs_p + 0xbc));
          *(ushort *)(iVar8 + iVar5 + 8) = (ushort)bVar2 | uVar4 & 0xffc0;
        }
      }
      bVar2 = DAT_0001301b;
      cVar10 = DAT_0001301a;
      if (param_3 != 0) {
        cVar10 = *(char *)(iVar6 + 0x16) + DAT_0001301b;
      }
      *(char *)(iVar6 + 0x16) = cVar10;
      *(ushort *)(iVar6 + 0x14) = bVar2 & 0xf | 0x2000;
      uVar9 = (uint)*(byte *)(iVar6 + 0x52);
      pcVar11 = *(code **)(_r_ip_funcs_p + 0x300);
    }
    (*pcVar11)(uVar9,pcVar11);
  }
                    /* WARNING: Could not recover jumptable at 0x000114cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x848))(0,param_1,param_2,param_3,*(code **)(_r_ip_funcs_p + 0x848));
  return;
}

