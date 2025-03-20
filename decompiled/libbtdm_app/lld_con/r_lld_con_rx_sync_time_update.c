/*
 * Last changed at upstream commit daab5dbba958a13041bd496e4a6ed506c9284a06
 * https://github.com/espressif/esp32c3-bt-lib/commit/daab5dbba958a13041bd496e4a6ed506c9284a06
 * Upstream date: 2025-03-20 20:43:40 +0800
 * Upstream subject: fix(bt): Update bt lib for ESP32-C3 and ESP32-S3(86a4da5c)
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
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  bVar1 = *(byte *)(_p_lld_env + 0xd8);
  uVar3 = 0;
  if ((*(ushort *)(param_2 + 0x84) & 1) != 0) {
    iVar4 = (uint)bVar1 * 0x14;
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar2 = *(ushort *)(iVar5 + iVar4 + 10);
    if ((uVar2 & 0xf000) != 0) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",1000,*(code **)(_r_plf_funcs_p + 8));
    }
    iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar3 = CONCAT22(uVar2,*(undefined2 *)(iVar4 + 8 + iVar5));
    *(uint *)(param_2 + 0x50) = uVar3;
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
    iVar4 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x1000,*(code **)(_r_plf_funcs_p + 0xbc));
    uVar6 = ((uint)*(ushort *)(&lld_exp_sync_pos_tab + (uint)*(byte *)(param_2 + 0x93) * 2) * -2 +
            0x270) - (*(ushort *)(iVar4 + (uint)bVar1 * 0x14 + 0xc) & 0x3ff);
    iVar4 = (int)(short)uVar6;
    if (((lld_exp_sync_pos_tab & 1) != 0) && ((*(byte *)(param_2 + 0x93) - 2 & 0xff) < 2)) {
      iVar4 = (int)(((uVar6 & 0xffff) + (uint)_DAT_0001604a * -2) * 0x10000) >> 0x10;
    }
    if (0x751 < (iVar4 + 0x4e1U & 0xffff)) {
      (**(code **)(_r_plf_funcs_p + 8))(0,"lld_con.c",0x8d0,*(code **)(_r_plf_funcs_p + 8));
    }
    for (; iVar5 = _r_ip_funcs_p, iVar4 < 0; iVar4 = (iVar4 + 0x271) * 0x10000 >> 0x10) {
      uVar3 = uVar3 - 1 & 0xfffffff;
    }
    if ((*(char *)(param_2 + 0x46) == '\x01') && (*(char *)(param_2 + 0x42) != '\0')) {
      *(undefined1 *)(param_2 + 0x43) = 1;
      (**(code **)(iVar5 + 0x3d4))(param_1,*(code **)(iVar5 + 0x3d4));
    }
    *(short *)(param_2 + 0x6e) = (short)iVar4;
    *(uint *)(param_2 + 0x48) = uVar3;
    *(uint *)(param_2 + 0x54) = uVar3;
  }
                    /* WARNING: Could not recover jumptable at 0x00011d2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(_r_ip_funcs_p + 0x398))(param_1,param_2);
  return;
}

