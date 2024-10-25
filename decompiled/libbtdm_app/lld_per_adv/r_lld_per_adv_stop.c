/*
 * Last changed at upstream commit 6470c01165cf4edeed5d826ce4082a90deb92efd
 * https://github.com/espressif/esp32c3-bt-lib/commit/6470c01165cf4edeed5d826ce4082a90deb92efd
 * Upstream date: 2024-10-25 10:35:57 +0800
 * Upstream subject: feat(bt): Support ble controller run in flash(d752deac)
 * Source: libbtdm_app -> lld_per_adv.o -> r_lld_per_adv_stop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 r_lld_per_adv_stop(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  
  (**(code **)(_r_osi_funcs_p + 0x14))(*(code **)(_r_osi_funcs_p + 0x14));
  iVar2 = *(int *)(&lld_per_adv_env + param_1 * 4);
  uVar3 = 0xc;
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x53) == '\0') {
      (**(code **)(_r_ip_funcs_p + 0x6b8))(iVar2,0,*(code **)(_r_ip_funcs_p + 0x6b8));
      puVar4 = (undefined1 *)
               (**(code **)(_r_modules_funcs_p + 200))
                         (0x208,0,0xff,2,*(code **)(_r_modules_funcs_p + 200));
      *puVar4 = (char)param_1;
      puVar4[1] = 0;
      (**(code **)(_r_modules_funcs_p + 0xe0))(*(code **)(_r_modules_funcs_p + 0xe0));
      (**(code **)(_r_ip_funcs_p + 0x2cc))(param_1,*(code **)(_r_ip_funcs_p + 0x2cc));
    }
    else if (*(char *)(iVar2 + 0x53) == '\x01') {
      bVar1 = *(byte *)(iVar2 + 0x52);
      iVar5 = (**(code **)(_r_plf_funcs_p + 0xbc))(0x400,*(code **)(_r_plf_funcs_p + 0xbc));
      *(undefined2 *)((uint)bVar1 * 0x5a + 0x20 + iVar5) = 1;
      _DAT_60031000 = _DAT_60031000 & 0xfdffffff | 0x2000000;
      *(undefined1 *)(iVar2 + 0x53) = 2;
    }
    uVar3 = 0;
  }
  (**(code **)(_r_osi_funcs_p + 0x18))(*(code **)(_r_osi_funcs_p + 0x18));
  return uVar3;
}

