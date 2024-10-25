/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> llc_phy_upd.o -> ll_phy_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ll_phy_req_handler(int param_1,int param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  
  iVar4 = (**(code **)(_r_plf_funcs_p + 0xf0))(*(code **)(_r_plf_funcs_p + 0xf0));
  if (*(char *)(iVar4 + 0x18) == '\0') {
    return 0x24;
  }
  iVar6 = *(int *)(&llc_env + param_1 * 4);
  iVar4 = (**(code **)(_r_ip_funcs_p + 0x678))(1,param_3,*(code **)(_r_ip_funcs_p + 0x678));
  if (iVar4 == 0) {
    iVar4 = 0x1e;
    if (((*(char *)(param_2 + 2) != '\0') && (*(char *)(param_2 + 1) != '\0')) &&
       (((*(ushort *)(iVar6 + 0x42) & 1) == 0 ||
        (iVar4 = (**(code **)(_r_ip_funcs_p + 0x66c))(param_1,9,*(code **)(_r_ip_funcs_p + 0x66c)),
        iVar4 == 0)))) {
      puVar3 = (undefined4 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x10e,param_1 << 8 | 1,0x14,*(code **)(_r_modules_funcs_p + 200));
      *(undefined1 *)(puVar3 + 1) = 9;
      (**(code **)(_r_ip_funcs_p + 0x684))(param_1,5,*(code **)(_r_ip_funcs_p + 0x684));
      iVar4 = _r_ip_funcs_p;
      *puVar3 = *(undefined4 *)(_r_ip_funcs_p + 0x654);
      bVar1 = *(byte *)(param_2 + 1);
      *(byte *)((int)puVar3 + 0xb) = bVar1;
      bVar2 = *(byte *)(param_2 + 2);
      *(byte *)((int)puVar3 + 10) = bVar2;
      if ((uint)bVar1 == (uint)bVar2) {
        bVar5 = (&one_bits)[bVar1] == '\x01';
      }
      else {
        bVar5 = false;
      }
      *(bool *)((int)puVar3 + 0xf) = bVar5;
      (**(code **)(iVar4 + 0x67c))(param_1,1,puVar3,*(code **)(iVar4 + 0x67c));
      (**(code **)(_r_ip_funcs_p + 0x650))(param_1,5,0,*(code **)(_r_ip_funcs_p + 0x650));
      iVar4 = 0;
    }
  }
  else {
    iVar4 = 0x24;
  }
  return iVar4;
}

