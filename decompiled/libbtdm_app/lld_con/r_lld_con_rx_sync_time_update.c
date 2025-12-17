/*
 * Last changed at upstream commit 9b50531537e755792ac827d00d233eab499a0b37
 * https://github.com/espressif/esp32c3-bt-lib/commit/9b50531537e755792ac827d00d233eab499a0b37
 * Upstream date: 2025-12-17 10:51:37 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(5106725)
 * Source: libbtdm_app -> lld_con.o -> r_lld_con_rx_sync_time_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void r_lld_con_rx_sync_time_update(undefined4 param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar6 = 0;
  if ((*(ushort *)(param_2 + 0x84) & 1) != 0) {
    iVar3 = (uint)bVar1 * 0x14;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar3 + 10 + iVar5);
    if ((uVar2 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",1000,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = CONCAT22(uVar2,*(undefined2 *)(iVar3 + 8 + iVar5));
    *(uint *)(param_2 + 0x50) = uVar6;
  }
  uVar2 = *(ushort *)(param_2 + 0x84);
  if ((uVar2 & 0x100) != 0) {
    return;
  }
  *(ushort *)(param_2 + 0x84) = uVar2 | 0x100;
  if ((uVar2 & 1) == 0) {
    *(undefined4 *)(param_2 + 0x50) = *(undefined4 *)(param_2 + 0x48);
  }
  else {
    iVar3 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar4 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(param_2 + 0x93) * 2) * -2 +
            0x270) - (*(ushort *)((uint)bVar1 * 0x14 + 0xc + iVar3) & 0x3ff);
    iVar3 = (int)(uVar4 * 0x10000) >> 0x10;
    if (((lld_exp_sync_pos_tab & 1) != 0) && ((*(byte *)(param_2 + 0x93) - 2 & 0xff) < 2)) {
      iVar3 = (int)(((uVar4 & 0xffff) + (uint)_DAT_0001604a * -2) * 0x10000) >> 0x10;
    }
    if (0x751 < (iVar3 + 0x4e1U & 0xffff)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x90a,*(code **)(_r_plf_funcs_p + 8));
    }
    for (; iVar5 = _r_ip_funcs_p, iVar3 < 0; iVar3 = (iVar3 + 0x271) * 0x10000 >> 0x10) {
      uVar6 = uVar6 - 1 & 0xfffffff;
    }
    if ((*(char *)(param_2 + 0x46) == '\x01') && (*(char *)(param_2 + 0x42) != '\0')) {
      *(undefined1 *)(param_2 + 0x43) = 1;
      (**(code **)(iVar5 + 0x3d4))(param_1,*(code **)(iVar5 + 0x3d4));
    }
    *(short *)(param_2 + 0x6e) = (short)iVar3;
    *(uint *)(param_2 + 0x48) = uVar6;
    *(uint *)(param_2 + 0x54) = uVar6;
  }
                    /* WARNING: Could not recover jumptable at 0x00011c68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x398))(param_1,param_2,*(code **)(_r_ip_funcs_p + 0x398));
  return;
}

