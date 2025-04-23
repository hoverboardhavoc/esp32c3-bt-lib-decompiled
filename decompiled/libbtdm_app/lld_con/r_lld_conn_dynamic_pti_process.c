/*
 * Last changed at upstream commit db872ab1620e1656f51d7a69c5a0576a6f369501
 * https://github.com/espressif/esp32c3-bt-lib/commit/db872ab1620e1656f51d7a69c5a0576a6f369501
 * Upstream date: 2025-04-23 17:25:53 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(edf923e)
 * Source: libbtdm_app -> lld_con.o -> r_lld_conn_dynamic_pti_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_conn_dynamic_pti_process(uint param_1)

{
  byte bVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = *(int *)(&lld_con_env + param_1 * 4);
  if ((iVar3 != 0) &&
     (iVar4 = (**(code **)(_r_modules_funcs_p + 0x184))(*(code **)(_r_modules_funcs_p + 0x184)),
     iVar4 != 0)) {
    iVar4 = *(int *)(_bt_rf_coex_cfg_p + 0x30);
    if ((*(char *)(iVar3 + 0x46) == '\0') &&
       ((uint)*(byte *)(iVar4 + 4) < (uint)*(ushort *)(iVar3 + 0x7c))) {
      uVar5 = *(uint *)(iVar3 + 100);
      if ((uint)*(byte *)(iVar4 + 6) << 1 < uVar5) {
        if ((uint)*(byte *)(iVar4 + 8) << 1 < uVar5) {
          uVar6 = 0;
          if (uVar5 <= (uint)*(byte *)(iVar4 + 10) << 1) {
            uVar6 = (uint)*(byte *)(iVar4 + 9);
          }
        }
        else {
          uVar6 = (uint)*(byte *)(iVar4 + 7);
        }
      }
      else {
        uVar6 = (uint)*(byte *)(iVar4 + 5);
      }
      if ((int)((uint)*(ushort *)(iVar3 + 0x7c) - (uint)*(ushort *)(iVar3 + 0x98)) <= (int)uVar6) {
        if (0xb < param_1) {
          (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
        }
        puVar2 = (uint *)((param_1 + 0x1800c4cb) * 4);
        *puVar2 = *puVar2 & 0x7fffffff;
        return;
      }
    }
    bVar1 = *(byte *)(iVar4 + 3);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x298d,*(code **)(_r_plf_funcs_p + 8));
    }
    puVar2 = (uint *)((param_1 + 0x1800c4cb) * 4);
    *puVar2 = *puVar2 & 0xffff0fff | (uint)bVar1 << 0xc;
    bVar1 = *(byte *)(*(int *)(_bt_rf_coex_cfg_p + 0x30) + 2);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ab,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x29ad,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 & 0xffffff0f | (uint)bVar1 << 4;
    bVar1 = *(byte *)(*(int *)(_bt_rf_coex_cfg_p + 0x30) + 1);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297b,*(code **)(_r_plf_funcs_p + 8));
    }
    if ((bVar1 & 0xf0) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x297d,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 & 0xfff0ffff | (uint)bVar1 << 0x10;
    bVar1 = **(byte **)(_bt_rf_coex_cfg_p + 0x30);
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x296a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 & 0xe00fffff | (uint)bVar1 << 0x14;
    if (0xb < param_1) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x293a,*(code **)(_r_plf_funcs_p + 8));
    }
    *puVar2 = *puVar2 | 0x80000000;
  }
  return;
}

