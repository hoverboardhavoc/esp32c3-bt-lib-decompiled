/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> f_ll_phy_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 f_ll_phy_rsp_handler(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  
  uVar5 = 0x1e;
  if ((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) {
    uVar5 = 0;
  }
  if (((*(ushort *)(*(int *)(&llc_env + param_1 * 4) + 0x42) & 1) == 0) ||
     (iVar3 = (**(code **)(_r_ip_funcs_p + 0x678))(0,*(code **)(_r_ip_funcs_p + 0x678)), iVar3 != 9)
     ) {
    uVar5 = 0x24;
  }
  else {
    iVar3 = (**(code **)(_r_ip_funcs_p + 0x674))(param_1,0,*(code **)(_r_ip_funcs_p + 0x674));
    bVar1 = *(byte *)(param_2 + 2);
    *(byte *)(iVar3 + 10) = *(byte *)(iVar3 + 10) & bVar1;
    bVar2 = *(byte *)(param_2 + 1);
    *(byte *)(iVar3 + 0xb) = *(byte *)(iVar3 + 0xb) & bVar2;
    bVar4 = false;
    if ((uint)bVar1 == (uint)bVar2) {
      bVar4 = (&one_bits)[bVar1] == '\x01';
    }
    *(bool *)(iVar3 + 0xf) = bVar4;
    (**(code **)(_r_ip_funcs_p + 0x648))(param_1,2,uVar5,*(code **)(_r_ip_funcs_p + 0x648));
  }
  return uVar5;
}

